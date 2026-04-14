begin
  # Derive the module name from this script's filename (run_<name>.rb -> <name>)
  name = File.basename(__FILE__, '.rb').sub(/^run_/, '')
  require File.join(__dir__, name)
rescue StandardError => e
  STDOUT << e.message << "\n"
  STDOUT << e.backtrace.join("\n") << "\n"
  STDOUT.flush
end
