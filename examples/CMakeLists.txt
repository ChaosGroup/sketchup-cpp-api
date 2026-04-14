set(SKETCHUP_VERSION 2026)

foreach(TARGET hello_sketchup app_observer)
	add_library(${TARGET} MODULE ${TARGET}.cpp)
	target_link_libraries(${TARGET} SketchUpCppAPI_${SKETCHUP_VERSION})
	set_target_properties(${TARGET} PROPERTIES
		PREFIX ""
	)

	if(WIN32)
		set_target_properties(${TARGET} PROPERTIES SUFFIX .so)
		set(SKETCHUP_EXECUTABLE "C:/Program Files/SketchUp/SketchUp ${SKETCHUP_VERSION}/SketchUp.exe")
	elseif(APPLE)
		set_target_properties(${TARGET} PROPERTIES SUFFIX .bundle)
		set(SKETCHUP_EXECUTABLE "/Applications/SketchUp ${SKETCHUP_VERSION}/SketchUp.app")
	endif()

	file(GENERATE
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/run_${TARGET}.rb
		INPUT ${CMAKE_CURRENT_SOURCE_DIR}/run_example.rb
		NEWLINE_STYLE UNIX
	)

	set_target_properties(${TARGET} PROPERTIES
		XCODE_SCHEME_EXECUTABLE ${SKETCHUP_EXECUTABLE}
		XCODE_SCHEME_ARGUMENTS "-RubyStartup ${CMAKE_CURRENT_BINARY_DIR}/\${CONFIGURATION}/run_${TARGET}.rb"
	)
endforeach()
