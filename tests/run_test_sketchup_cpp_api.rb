begin
  require File.join(__dir__, 'test_sketchup_cpp_api')
rescue StandardError => e
  STDOUT << e.message
  STDOUT << e.backtrace
  STDOUT << 'FAILURE'
  STDOUT.flush
end

Sketchup.quit
