cmake_minimum_required(VERSION 3.22)

add_executable(generate_dummy_class${SKETCHUP_VERSION} generate_dummy_class.cpp)
target_compile_definitions(generate_dummy_class${SKETCHUP_VERSION} PUBLIC "SOURCE_DIR=\"${CMAKE_SOURCE_DIR}/hostapp/dummy_objects.hpp\"")

add_executable(parse_ruby_doc${SKETCHUP_VERSION} parse_ruby_doc.cpp)
target_compile_definitions(parse_ruby_doc${SKETCHUP_VERSION} PUBLIC "OUTPUT_DIR=\"${CMAKE_SOURCE_DIR}/build_utils/output/\"")
