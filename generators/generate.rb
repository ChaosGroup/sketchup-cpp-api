require 'yard'
require_relative 'api_interface'

output_path = ARGV[0]
raise "Output path does not exist #{output_path}" if !File.exist?(output_path)

APIInterface.setup
APIInterface.export(output_path)