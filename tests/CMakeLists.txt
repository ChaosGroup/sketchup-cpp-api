# TODO test all versions
set(SKETCHUP_VERSION 2026)

# test_inclusion
add_executable(test_inclusion test_inclusion.cpp)
target_link_libraries(test_inclusion SketchUpCppAPI_${SKETCHUP_VERSION})

# test_find_package
add_test(NAME test_find_package
	COMMAND ${CMAKE_COMMAND}
		-DBUILD_DIR=${CMAKE_BINARY_DIR}
		-DINSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/test_find_package_install
		-DCONSUMER_SRC=${CMAKE_CURRENT_SOURCE_DIR}/test_find_package
		-DCONSUMER_BUILD=${CMAKE_CURRENT_BINARY_DIR}/test_find_package_build
		-DTEST_SOURCE=${CMAKE_CURRENT_SOURCE_DIR}/test_find_package.cpp
		-P ${CMAKE_CURRENT_SOURCE_DIR}/test_find_package.cmake
)

# test_sketchup_cpp_api
add_library(test_sketchup_cpp_api MODULE
	test_sketchup_cpp_api.cpp
	hostapp/test_sketchup.cpp
	hostapp/test_model.cpp
)
target_compile_definitions(test_sketchup_cpp_api PRIVATE SKETCHUP_VERSION=${SKETCHUP_VERSION})
target_link_libraries(test_sketchup_cpp_api SketchUpCppAPI_${SKETCHUP_VERSION})
target_include_directories(test_sketchup_cpp_api PRIVATE doctest/doctest)
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

if(APPLE)
	add_test(NAME test_sketchup_cpp_api
		COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/launch_sketchup_mac.sh ${SKETCHUP_EXECUTABLE} -RubyStartup $<TARGET_FILE_DIR:test_sketchup_cpp_api>/run_test_sketchup_cpp_api.rb
	)
else()
	add_test(NAME test_sketchup_cpp_api
		COMMAND ${SKETCHUP_EXECUTABLE} -RubyStartup $<TARGET_FILE_DIR:test_sketchup_cpp_api>/run_test_sketchup_cpp_api.rb
	)
endif()
set_tests_properties(test_sketchup_cpp_api PROPERTIES
	PASS_REGULAR_EXPRESSION "\\[doctest\\] Status: SUCCESS!"
)

set_target_properties(test_sketchup_cpp_api PROPERTIES
	VS_DEBUGGER_COMMAND "C:/Program Files/SketchUp/SketchUp ${SKETCHUP_VERSION}/SketchUp.exe"
	VS_DEBUGGER_COMMAND_ARGUMENTS "-RubyStartup $<TARGET_FILE_DIR:test_sketchup_cpp_api>/run_test_sketchup_cpp_api.rb"
	XCODE_SCHEME_EXECUTABLE "/Applications/SketchUp ${SKETCHUP_VERSION}/SketchUp.app"
	XCODE_SCHEME_ARGUMENTS "-RubyStartup ${CMAKE_CURRENT_BINARY_DIR}/\${CONFIGURATION}/run_test_sketchup_cpp_api.rb"
)
