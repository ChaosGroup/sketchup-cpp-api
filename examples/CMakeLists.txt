foreach(TARGET playground any_of_example entities_observer_example ruby_hash_example)
	add_library(${TARGET}${SKETCHUP_VERSION} MODULE ${TARGET}.cpp)

	target_link_libraries(${TARGET}${SKETCHUP_VERSION} PUBLIC ${PROJECT_NAME}${SKETCHUP_VERSION})

	set_target_properties(${TARGET}${SKETCHUP_VERSION} PROPERTIES
		PREFIX ""
		FOLDER examples
	)

	if(WIN32)
		set_target_properties(${TARGET}${SKETCHUP_VERSION} PROPERTIES
			SUFFIX .so
		)
	elseif(APPLE)
		set_target_properties(${TARGET}${SKETCHUP_VERSION} PROPERTIES
			SUFFIX .bundle
		)
	endif()

	file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/${TARGET}${SKETCHUP_VERSION}.rb CONTENT "require '$<TARGET_FILE:${TARGET}${SKETCHUP_VERSION}>'")

	set_target_properties(${TARGET}${SKETCHUP_VERSION} PROPERTIES
		VS_DEBUGGER_COMMAND "C:/Program Files/SketchUp/SketchUp ${SKETCHUP_VERSION}/SketchUp.exe"
		VS_DEBUGGER_COMMAND_ARGUMENTS "-RubyStartup $<TARGET_FILE_DIR:${TARGET}${SKETCHUP_VERSION}>/${TARGET}${SKETCHUP_VERSION}.rb"
		XCODE_SCHEME_EXECUTABLE "/Applications/SketchUp ${SKETCHUP_VERSION}/SketchUp.app"
		XCODE_SCHEME_ARGUMENTS "-RubyStartup ${CMAKE_CURRENT_BINARY_DIR}/\${CONFIGURATION}/${TARGET}${SKETCHUP_VERSION}.rb"
	)
endforeach()