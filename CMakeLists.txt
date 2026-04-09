
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
	
enable_testing()
add_subdirectory(tests)
