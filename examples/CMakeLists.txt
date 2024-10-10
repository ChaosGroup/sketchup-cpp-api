foreach(TARGET playground any_of_example entities_observer_example ruby_hash_example)

	add_library(${TARGET} MODULE ${TARGET}.cpp)

	target_link_libraries(${TARGET} PUBLIC ${PROJECT_NAME})

	set_target_properties(${TARGET} PROPERTIES
		PREFIX ""
		FOLDER examples
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

	file(GENERATE OUTPUT $<CONFIG>/${TARGET}.rb CONTENT "require '$<TARGET_FILE:${TARGET}>'")

	set_target_properties(${TARGET} PROPERTIES 
		VS_DEBUGGER_COMMAND "C:/Program Files/SketchUp/SketchUp ${SKETCHUP_VERSION}/SketchUp.exe"
		VS_DEBUGGER_COMMAND_ARGUMENTS "-RubyStartup $<TARGET_FILE_DIR:${TARGET}>/${TARGET}.rb"
		XCODE_SCHEME_EXECUTABLE "/Applications/SketchUp ${SKETCHUP_VERSION}/SketchUp.app"
		XCODE_SCHEME_ARGUMENTS "-RubyStartup ${CMAKE_CURRENT_BINARY_DIR}/\${CONFIGURATION}/${TARGET}.rb"
	)
endforeach()