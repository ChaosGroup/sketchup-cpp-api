# SketchUpCppAPIConfig.cmake
# Package config for find_package(SketchUpCppAPI)
#
# Defines INTERFACE IMPORTED targets:
#   SketchUpCppAPI::SketchUpCppAPI_2021 .. SketchUpCppAPI::SketchUpCppAPI_2026
#
# Each target sets up include directories, link libraries, compile definitions,
# and C++20 requirement for the corresponding SketchUp version.

if(TARGET SketchUpCppAPI::SketchUpCppAPI_2024)
    return()
endif()

get_filename_component(_SKETCHUP_CPP_API_PREFIX "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

if(APPLE)
    execute_process(COMMAND uname -m OUTPUT_VARIABLE _SKETCHUP_CPP_API_ARCH OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

set(_SKETCHUP_CPP_API_RUBY_VERSIONS 2.7 3.2)

foreach(_VERSION ${_SKETCHUP_CPP_API_RUBY_VERSIONS})
    set(_SKETCHUP_CPP_API_RUBY_${_VERSION}_INCLUDE_DIRS
        "${_SKETCHUP_CPP_API_PREFIX}/ruby/${_VERSION}/include"
    )
    if(APPLE)
        list(APPEND _SKETCHUP_CPP_API_RUBY_${_VERSION}_INCLUDE_DIRS
            "${_SKETCHUP_CPP_API_PREFIX}/ruby/${_VERSION}/include/${_SKETCHUP_CPP_API_ARCH}-darwin"
        )
    endif()

    if(WIN32)
        file(GLOB _SKETCHUP_CPP_API_RUBY_${_VERSION}_LIBRARIES
            "${_SKETCHUP_CPP_API_PREFIX}/ruby/${_VERSION}/lib/*.lib"
        )
    elseif(APPLE)
        set(_SKETCHUP_CPP_API_RUBY_${_VERSION}_LIBRARIES
            "${_SKETCHUP_CPP_API_PREFIX}/ruby/${_VERSION}/lib/Ruby.framework/Ruby"
        )
    endif()
endforeach()

foreach(_SU_VERSION 2021 2022 2023 2024 2025 2026)
    if(_SU_VERSION GREATER_EQUAL 2024)
        set(_RUBY_VERSION 3.2)
    elseif(_SU_VERSION GREATER_EQUAL 2021)
        set(_RUBY_VERSION 2.7)
    endif()

    add_library(SketchUpCppAPI::SketchUpCppAPI_${_SU_VERSION} INTERFACE IMPORTED)
    target_include_directories(SketchUpCppAPI::SketchUpCppAPI_${_SU_VERSION} INTERFACE
        "${_SKETCHUP_CPP_API_PREFIX}/include"
        ${_SKETCHUP_CPP_API_RUBY_${_RUBY_VERSION}_INCLUDE_DIRS}
    )
    target_link_libraries(SketchUpCppAPI::SketchUpCppAPI_${_SU_VERSION} INTERFACE
        ${_SKETCHUP_CPP_API_RUBY_${_RUBY_VERSION}_LIBRARIES}
    )
    target_compile_definitions(SketchUpCppAPI::SketchUpCppAPI_${_SU_VERSION} INTERFACE
        SKETCHUP_VERSION=${_SU_VERSION}
    )
    target_compile_features(SketchUpCppAPI::SketchUpCppAPI_${_SU_VERSION} INTERFACE
        cxx_std_20
    )
endforeach()

# Cleanup
foreach(_VERSION ${_SKETCHUP_CPP_API_RUBY_VERSIONS})
    unset(_SKETCHUP_CPP_API_RUBY_${_VERSION}_INCLUDE_DIRS)
    unset(_SKETCHUP_CPP_API_RUBY_${_VERSION}_LIBRARIES)
endforeach()
unset(_SKETCHUP_CPP_API_RUBY_VERSIONS)
unset(_SKETCHUP_CPP_API_PREFIX)
unset(_SKETCHUP_CPP_API_ARCH)
unset(_VERSION)
unset(_SU_VERSION)
unset(_RUBY_VERSION)
