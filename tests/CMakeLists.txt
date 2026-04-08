enable_testing()

add_executable(test_inclusion test_inclusion.cpp)
target_link_libraries(test_inclusion hostapp)
add_test(test_inclusion test_inclusion)