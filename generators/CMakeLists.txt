execute_process(
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ruby generate.rb ${CMAKE_CURRENT_BINARY_DIR}
    RESULT_VARIABLE RES
    OUTPUT_VARIABLE OUT
    ERROR_VARIABLE ERR
)

if(NOT RES EQUAL 0)
    message(FATAL_ERROR
        "Command failed with exit code: ${RES}\n"
        "stdout:\n${OUT}\n"
        "stderr:\n${ERR}"
    )
endif()