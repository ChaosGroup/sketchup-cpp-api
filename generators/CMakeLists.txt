set(GENERATED_HPP ${CMAKE_CURRENT_BINARY_DIR}/hostapp.hpp)

add_custom_command(
    OUTPUT ${GENERATED_HPP}
    COMMAND ruby ${CMAKE_CURRENT_SOURCE_DIR}/generate.rb ${CMAKE_CURRENT_BINARY_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating hostapp.hpp from YARD stubs"
)

add_custom_target(generate
    DEPENDS ${GENERATED_HPP}
)

add_library(hostapp INTERFACE)
add_dependencies(hostapp generate)
target_include_directories(hostapp INTERFACE
	${CMAKE_CURRENT_BINARY_DIR}
	${Ruby_INCLUDE_DIRS}
)
target_link_libraries(hostapp INTERFACE ${Ruby_LIBRARIES})

