
cmake_minimum_required(VERSION 3.22)

project(sketchup-cpp-api)

if(NOT WIN32 AND NOT APPLE)
	message(FATAL_ERROR "Unsupported platform")
endif()

set(SKETCHUP_VERSION 2026 CACHE STRING "Target SketchUp version")
set_property(CACHE SKETCHUP_VERSION PROPERTY STRINGS 2021 2022 2023 2024 2025 2026)

if(SKETCHUP_VERSION GREATER_EQUAL 2024)
	set(SU_RUBY_VERSION 3.2)
elseif(SKETCHUP_VERSION GREATER_EQUAL 2021)
	set(SU_RUBY_VERSION 2.7)
endif()

# # Find system Ruby for the executable (used by generators)
find_package(Ruby REQUIRED)

# Override include dirs and libraries with SketchUp's Ruby
include(ruby-c-extension-examples.cmake)

# find_package(Ruby) will populate the following variables
# This mimmics the setup but using the vars from ruby-c-extension-examples.cmake
set(Ruby_FOUND ${SU_Ruby_${SU_RUBY_VERSION}_FOUND})
set(Ruby_INCLUDE_DIRS ${SU_Ruby_${SU_RUBY_VERSION}_INCLUDE_DIRS})
set(Ruby_LIBRARIES ${SU_Ruby_${SU_RUBY_VERSION}_LIBRARIES})
set(Ruby_VERSION ${SU_Ruby_${SU_RUBY_VERSION}_VERSION})
set(Ruby_VERSION_MAJOR ${SU_Ruby_${SU_RUBY_VERSION}_VERSION_MAJOR})
set(Ruby_VERSION_MINOR ${SU_Ruby_${SU_RUBY_VERSION}_VERSION_MINOR})
set(Ruby_VERSION_PATCH ${SU_Ruby_${SU_RUBY_VERSION}_VERSION_PATCH})

message(STATUS Ruby_FOUND=${Ruby_FOUND})
message(STATUS Ruby_EXECUTABLE=${Ruby_EXECUTABLE})
message(STATUS Ruby_INCLUDE_DIRS=${Ruby_INCLUDE_DIRS})
message(STATUS Ruby_LIBRARIES=${Ruby_LIBRARIES})
message(STATUS Ruby_VERSION=${Ruby_VERSION})
message(STATUS Ruby_VERSION_MAJOR=${Ruby_VERSION_MAJOR})
message(STATUS Ruby_VERSION_MINOR=${Ruby_VERSION_MINOR})
message(STATUS Ruby_VERSION_PATCH=${Ruby_VERSION_PATCH})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_XCODE_GENERATE_SCHEME ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(${PROJECT_NAME} INTERFACE)

# Ruby library so we can ignore any warnings coming from there
# add_library(RubyLib INTERFACE)
# target_include_directories(RubyLib INTERFACE ${Ruby_INCLUDE_DIRS})
# target_link_libraries(RubyLib INTERFACE ${Ruby_LIBRARIES})

set(BUILD_VERSION_MAJOR 0)
set(BUILD_VERSION_MINOR 00)
set(BUILD_VERSION_REVISION 00)
set(BUILD_VERSION_FULL "${BUILD_VERSION_MAJOR}.${BUILD_VERSION_MINOR}.${BUILD_VERSION_REVISION}")

# if(MSVC)
# 	# ignore Ruby lib's warnings
# 	target_compile_options(RubyLib INTERFACE
# 		/W0
# 	)
# 	# treat all warnings as errors in out code base
# 	target_compile_options(${PROJECT_NAME} INTERFACE
# 		/Wall /WX /wd4371 /wd4710 /wd4711 /wd5045 /wd4702
# 	)
# else()
# 	# ignore Ruby lib's warnings
# 	target_compile_options(RubyLib INTERFACE
# 		-w
# 	)
# 	# treat all warnings as errors in out code base
# 	target_compile_options(${PROJECT_NAME} INTERFACE
# 		# rest are treated as errors
# 		-Wall -Wextra -Werror
# 	)
# endif()

# target_include_directories(${PROJECT_NAME} INTERFACE
# 	${CMAKE_SOURCE_DIR}
# )
# target_link_libraries(${PROJECT_NAME} INTERFACE RubyLib)

add_subdirectory(generators)
add_subdirectory(tests)
