set(HOSTAPP_HPP ${CMAKE_CURRENT_BINARY_DIR}/include/SketchUpCppAPI/HostApp.hpp)

find_package(Ruby REQUIRED)

add_custom_command(
    OUTPUT ${HOSTAPP_HPP}
    COMMAND ${Ruby_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/generate.rb ${HOSTAPP_HPP}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating ${HOSTAPP_HPP} from YARD stubs"
)

add_custom_target(generate
    DEPENDS ${HOSTAPP_HPP}
)

add_library(HostApp INTERFACE)
add_dependencies(HostApp generate)
target_include_directories(HostApp INTERFACE
	${CMAKE_CURRENT_BINARY_DIR}/include
)

