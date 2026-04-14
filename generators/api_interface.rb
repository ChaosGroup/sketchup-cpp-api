require_relative 'class_interface'
require_relative 'module_interface'
require_relative 'observer_interface'

class APIInterface

  def self.setup
    ruby_files = Dir.glob("#{__dir__}/ruby-api-stubs/lib/sketchup-api-stubs/stubs/**/*.rb")
    YARD::Logger.instance.level = YARD::Logger::ERROR
    YARD::Parser::SourceParser.parse(ruby_files)
    YARD::Logger.instance.level = YARD::Logger::INFO
    load "#{__dir__}/api_override.rb"
  end

  def self.export(path)
    File.write(path, hpp)
  end

  def self.hpp
    all_classes = YARD::Registry.all(:class).map { |element| ClassInterface.new(element) }
    all_modules = YARD::Registry.all(:module).map { |element| ModuleInterface.new(element) }

    observer_classes = YARD::Registry.all(:class)
      .select { |c| ObserverInterface.observer?(c) }
      .map { |c| ObserverInterface.new(c) }

    # Topologically sort observers so parents come before children
    observer_classes = topological_sort_observers(observer_classes)

    # Separate observer and non-observer class interfaces
    observer_class_interfaces = all_classes.select(&:observer?)
    non_observer_class_interfaces = all_classes.reject(&:observer?)

    # Sort observer class interfaces to match topological order
    obs_order = observer_classes.map(&:full_path)
    observer_class_interfaces.sort_by! { |ci|
      idx = obs_order.index(ci.instance_variable_get(:@class_object).path)
      idx || 999
    }

    indent = "\t"

    s = ''
    s << '#pragma once' << "\n"
    s << "\n"
    s << '#ifndef SKETCHUP_VERSION' << "\n"
    s << '#error "SKETCHUP_VERSION must be defined"' << "\n"
    s << '#endif' << "\n"
    s << "\n"
    s << '#include <concepts>' << "\n"
    s << "\n"

    s << "namespace SketchUpCppAPI::HostApp" << "\n"
    s << "{" << "\n"

    # Phase 1: Forward declarations
    all_modules.each { |i| s << i.forward_declaration(indent) << "\n" }
    all_classes.each { |i| s << i.forward_declaration(indent) << "\n" }

    # Phase 2: Non-observer class definitions (simple stubs, some with add_observer declarations)
    non_observer_class_interfaces.each { |i| s << i.definition(indent) << "\n" }

    # Phase 3: Observer class definitions (topologically sorted so parents first)
    observer_class_interfaces.each { |i| s << i.definition(indent) << "\n" }

    # Phase 4: Observer infrastructure
    unless observer_classes.empty?
      s << "\n#{indent}namespace detail {\n\n"

      # Per-observer concepts, trampolines, register functions
      observer_classes.each { |obs| s << obs.infrastructure("#{indent}\t") << "\n\n" }
      s << "#{indent}} // namespace detail\n\n"
    end

    # Phase 5: Out-of-class add_observer/remove_observer definitions
    observer_classes.each do |obs|
      ObserverInterface::OBSERVER_MAP.each do |host_path, obs_path|
        next unless obs_path == obs.full_path
        host_obj = YARD::Registry.at(host_path)
        # Skip modules (handled in module definition phase)
        next if host_obj&.type == :module
        s << obs.add_observer_definition(host_path, indent) << "\n\n"
      end
    end

    # Phase 6: Module definitions (with methods)
    all_modules.each { |i|
      s << i.definition(indent, observer_classes) << "\n"
    }

    s << "}" << "\n"

    s
  end

  private

  def self.topological_sort_observers(observers)
    by_path = observers.map { |o| [o.full_path, o] }.to_h
    sorted = []
    visited = {}

    visit = ->(obs) {
      return if visited[obs.full_path]
      visited[obs.full_path] = true
      parent = obs.parent_observer
      if parent && by_path[parent.full_path]
        visit.call(by_path[parent.full_path])
      end
      sorted << obs
    }

    observers.each { |obs| visit.call(obs) }
    sorted
  end

end
