add_executable(test_inclusion test_inclusion.cpp)
target_link_libraries(test_inclusion hostapp)

add_library(test_sketchup_cpp_api MODULE test_sketchup_cpp_api.cpp)
target_link_libraries(test_sketchup_cpp_api hostapp)
set_target_properties(test_sketchup_cpp_api PROPERTIES
	PREFIX ""
)

if(WIN32)
	set_target_properties(test_sketchup_cpp_api PROPERTIES
		SUFFIX .so
	)
elseif(APPLE)
	set_target_properties(test_sketchup_cpp_api PROPERTIES
		SUFFIX .bundle
	)
endif()

file(GENERATE
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/run_test_sketchup_cpp_api.rb
	INPUT ${CMAKE_CURRENT_SOURCE_DIR}/run_test_sketchup_cpp_api.rb
)

if(WIN32)
	set(SKETCHUP_EXECUTABLE "C:/Program Files/SketchUp/SketchUp ${SKETCHUP_VERSION}/SketchUp.exe")
elseif(APPLE)
	set(SKETCHUP_EXECUTABLE "/Applications/SketchUp ${SKETCHUP_VERSION}/SketchUp.app/Contents/MacOS/SketchUp")
endif()

add_test(NAME test_sketchup_cpp_api
	COMMAND ${SKETCHUP_EXECUTABLE} -RubyStartup $<TARGET_FILE_DIR:test_sketchup_cpp_api>/run_test_sketchup_cpp_api.rb
)

set_target_properties(test_sketchup_cpp_api PROPERTIES
	VS_DEBUGGER_COMMAND "C:/Program Files/SketchUp/SketchUp ${SKETCHUP_VERSION}/SketchUp.exe"
	VS_DEBUGGER_COMMAND_ARGUMENTS "-RubyStartup $<TARGET_FILE_DIR:test_sketchup_cpp_api>/run_test_sketchup_cpp_api.rb"
	XCODE_SCHEME_EXECUTABLE "/Applications/SketchUp ${SKETCHUP_VERSION}/SketchUp.app"
	XCODE_SCHEME_ARGUMENTS "-RubyStartup ${CMAKE_CURRENT_BINARY_DIR}/\${CONFIGURATION}/run_test_sketchup_cpp_api.rb"
)