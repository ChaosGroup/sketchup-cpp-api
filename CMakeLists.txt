
cmake_minimum_required(VERSION 3.22)

project(sketchup-cpp-api)

if(NOT WIN32 AND NOT APPLE)
	message(FATAL_ERROR "Unsupported platform")
endif()

set(SKETCHUP_VERSION 2024 CACHE STRING "Target SketchUp version")
set_property(CACHE SKETCHUP_VERSION PROPERTY STRINGS 2021 2022 2023 2024)

if(SKETCHUP_VERSION EQUAL 2024)
	set(RUBY_VERSION 3.2)
elseif(SKETCHUP_VERSION GREATER_EQUAL 2021)
	set(RUBY_VERSION 2.7)
endif()

include(ruby-c-extension-examples.cmake)

# find_package(Ruby) will populate the following variables
# This mimmics the setup but using the vars from ruby-c-extension-examples.cmake
set(Ruby_FOUND ${SU_Ruby_${RUBY_VERSION}_FOUND})
set(Ruby_EXECUTABLE ${SU_Ruby_${RUBY_VERSION}_EXECUTABLE})
set(Ruby_INCLUDE_DIRS ${SU_Ruby_${RUBY_VERSION}_INCLUDE_DIRS})
set(Ruby_LIBRARIES ${SU_Ruby_${RUBY_VERSION}_LIBRARIES})
set(Ruby_VERSION ${SU_Ruby_${RUBY_VERSION}_VERSION})
set(Ruby_VERSION_MAJOR ${SU_Ruby_${RUBY_VERSION}_VERSION_MAJOR})
set(Ruby_VERSION_MINOR ${SU_Ruby_${RUBY_VERSION}_VERSION_MINOR})
set(Ruby_VERSION_PATCH ${SU_Ruby_${RUBY_VERSION}_VERSION_PATCH})

message(STATUS Ruby_FOUND=${Ruby_FOUND})
message(STATUS Ruby_EXECUTABLE=${Ruby_EXECUTABLE})
message(STATUS Ruby_INCLUDE_DIRS=${Ruby_INCLUDE_DIRS})
message(STATUS Ruby_LIBRARIES=${Ruby_LIBRARIES})
message(STATUS Ruby_VERSION=${Ruby_VERSION})
message(STATUS Ruby_VERSION_MAJOR=${Ruby_VERSION_MAJOR})
message(STATUS Ruby_VERSION_MINOR=${Ruby_VERSION_MINOR})
message(STATUS Ruby_VERSION_PATCH=${Ruby_VERSION_PATCH})

if(NOT Ruby_FOUND)
	message(FATAL_ERROR "Failed to find ruby for RUBY_VERSION=${RUBY_VERSION}")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_XCODE_GENERATE_SCHEME ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(${PROJECT_NAME}${SKETCHUP_VERSION} INTERFACE)

# Ruby library so we can ignore any warnings coming from there
add_library(RubyLib${SKETCHUP_VERSION} INTERFACE)
target_include_directories(RubyLib${SKETCHUP_VERSION} INTERFACE ${Ruby_INCLUDE_DIRS})
target_link_libraries(RubyLib${SKETCHUP_VERSION} INTERFACE ${Ruby_LIBRARIES})

set(BUILD_INTENT dev CACHE STRING "Type of build. Can be dev|sonar")

if(${BUILD_INTENT} MATCHES "sonar")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
endif()

set(BUILD_VERSION_MAJOR 0)
set(BUILD_VERSION_MINOR 00)
set(BUILD_VERSION_REVISION 00)
set(BUILD_VERSION_FULL "${BUILD_VERSION_MAJOR}.${BUILD_VERSION_MINOR}.${BUILD_VERSION_REVISION}")

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/sonar-project.properties "\
	sonar.organization=ChaosGroup
	sonar.projectVersion=${BUILD_VERSION_FULL}

	sonar.sources=hostapp/,ruby/,cpp/,tests/,playground/

	sonar.tests=tests
	sonar.test.inclusions=tests/**

	sonar.coverageReportPaths=build/coverage.xml

	sonar.exclusions=build_utils/**

	sonar.issue.ignore.multicriteria=e1,e2

	# Inheriting constructors should be used
	# Note: not all Object constructors should be used by child classes
	sonar.issue.ignore.multicriteria.e1.ruleKey=cpp:S5952
	sonar.issue.ignore.multicriteria.e1.resourceKey=**

	# #include directives in a file should only be preceded by other preprocessor directives or comments
	sonar.issue.ignore.multicriteria.e2.ruleKey=cpp:S954
	sonar.issue.ignore.multicriteria.e2.resourceKey=**

	sonar.cfamily.threads=4
	sonar.cfamily.compile_commands=build/compile_commands.json
")

if(MSVC)
	# ignore Ruby lib's warnings
	target_compile_options(RubyLib${SKETCHUP_VERSION} INTERFACE
		/W0
	)

	# treat all warnings as errors in out code base
	target_compile_options(${PROJECT_NAME}${SKETCHUP_VERSION} INTERFACE
		/Wall /WX /wd4371 /wd4710 /wd4711 /wd5045 /wd4702
	)
else()
	# ignore Ruby lib's warnings
	target_compile_options(RubyLib${SKETCHUP_VERSION} INTERFACE
		-w
	)

	# treat all warnings as errors in out code base
	target_compile_options(${PROJECT_NAME}${SKETCHUP_VERSION} INTERFACE

		# rest are treated as errors
		-Wall -Wextra -Werror
	)
endif()

target_include_directories(${PROJECT_NAME}${SKETCHUP_VERSION} INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${PROJECT_NAME}${SKETCHUP_VERSION} INTERFACE RubyLib${SKETCHUP_VERSION})

add_subdirectory(build_utils/scripts)

enable_testing()

add_subdirectory(examples)

add_subdirectory(tests)
