require 'yard'
require 'fileutils'
require_relative 'api_interface'

output_path = ARGV[0]
output_dir = File.dirname(output_path)

FileUtils.mkdir_p(output_dir)

APIInterface.setup
APIInterface.export(output_path)