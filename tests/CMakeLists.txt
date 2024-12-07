list(APPEND tests TestObject TestMaterial TestOptional TestRubyClass)
set(TESTS_LIST "")
foreach(TARGET ${tests})
	add_library(${TARGET} MODULE ${TARGET}.cpp)
	target_link_libraries(${TARGET} PUBLIC ${PROJECT_NAME})
	set_target_properties(${TARGET} PROPERTIES 
		PREFIX ""
	)
	if(WIN32)
		set_target_properties(${TARGET} PROPERTIES
			SUFFIX .so
		)
	elseif(APPLE)
		set_target_properties(${TARGET} PROPERTIES
			SUFFIX .bundle
		)
	endif()
	add_custom_command(TARGET ${TARGET} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E
		copy ${CMAKE_CURRENT_SOURCE_DIR}/TC_${TARGET}.rb "${CMAKE_CURRENT_BINARY_DIR}"
	COMMAND ${CMAKE_COMMAND} -E 
		copy "$<TARGET_FILE:${TARGET}>" ${CMAKE_CURRENT_BINARY_DIR}/
	)

	set(TESTS_LIST "${TESTS_LIST}require '${CMAKE_CURRENT_BINARY_DIR}/TC_${TARGET}'
")
endforeach()

file(GENERATE OUTPUT Run_Tests.rb CONTENT "require 'testup'
TestUp::API.run_suite_without_gui('${CMAKE_CURRENT_BINARY_DIR}')")

add_custom_target(Tests ALL)
add_dependencies(Tests ${tests})
set_target_properties(Tests PROPERTIES 
	VS_DEBUGGER_COMMAND "C:/Program Files/SketchUp/SketchUp ${SKETCHUP_VERSION}/SketchUp.exe"
	VS_DEBUGGER_COMMAND_ARGUMENTS "-RubyStartup \"${CMAKE_CURRENT_BINARY_DIR}/Run_Tests.rb\""
	XCODE_SCHEME_EXECUTABLE "/Applications/SketchUp ${SKETCHUP_VERSION}/SketchUp.app"
	XCODE_SCHEME_ARGUMENTS  "-RubyStartup '${CMAKE_CURRENT_BINARY_DIR}/Run_Tests.rb'"
)
