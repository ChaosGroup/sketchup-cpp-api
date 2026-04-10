
cmake_minimum_required(VERSION 3.30)

project(SketchUpCppAPI)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_XCODE_GENERATE_SCHEME ON)

add_subdirectory(generators)

include(ruby-c-extension-examples.cmake)

foreach(SKETCHUP_VERSION 2021 2022 2023 2024 2025 2026)
	if(SKETCHUP_VERSION GREATER_EQUAL 2024)
		set(SU_RUBY_VERSION 3.2)
	elseif(SKETCHUP_VERSION GREATER_EQUAL 2021)
		set(SU_RUBY_VERSION 2.7)
	endif()
	add_library(SketchUpCppAPI_${SKETCHUP_VERSION} INTERFACE)
	target_include_directories(SketchUpCppAPI_${SKETCHUP_VERSION} INTERFACE
		${SU_Ruby_${SU_RUBY_VERSION}_INCLUDE_DIRS}
	)
	target_link_libraries(SketchUpCppAPI_${SKETCHUP_VERSION} INTERFACE HostApp ${SU_Ruby_${SU_RUBY_VERSION}_LIBRARIES})
	target_compile_definitions(SketchUpCppAPI_${SKETCHUP_VERSION} INTERFACE SKETCHUP_VERSION=${SKETCHUP_VERSION})		
endforeach()
	
# --- Install rules ---

# Headers
get_target_property(_HOSTAPP_INCLUDE_DIRS HostApp INTERFACE_INCLUDE_DIRECTORIES)
foreach(_DIR ${_HOSTAPP_INCLUDE_DIRS})
	install(DIRECTORY ${_DIR}/SketchUpCppAPI
		DESTINATION include)
endforeach()

# Ruby headers and libraries for each version
foreach(VERSION ${RUBY_VERSIONS})
	foreach(INCLUDE_DIR ${SU_Ruby_${VERSION}_INCLUDE_DIRS})
		if(IS_DIRECTORY ${INCLUDE_DIR})
			install(DIRECTORY ${INCLUDE_DIR}/
				DESTINATION ruby/${VERSION}/include)
		endif()
	endforeach()

	if(APPLE)
		get_filename_component(FRAMEWORK_DIR "${SU_Ruby_${VERSION}_LIBRARIES}" DIRECTORY)
		install(DIRECTORY ${FRAMEWORK_DIR}
			DESTINATION ruby/${VERSION}/lib)
	elseif(WIN32)
		install(FILES ${SU_Ruby_${VERSION}_LIBRARIES}
			DESTINATION ruby/${VERSION}/lib)
	endif()
endforeach()

# CMake package config
install(FILES cmake/SketchUpCppAPIConfig.cmake
	DESTINATION cmake)

enable_testing()
add_subdirectory(tests)
