require File.join(__dir__, "test_sketchup_cpp_api")

result = test_sketchup_cpp_api
puts result ? "PASS" : "FAIL"
