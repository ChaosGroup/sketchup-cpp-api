macro(run)
    execute_process(COMMAND ${ARGN} RESULT_VARIABLE _result)
    if(NOT _result EQUAL 0)
        message(FATAL_ERROR "Command failed: ${ARGN}")
    endif()
endmacro()

run(${CMAKE_COMMAND} --install ${BUILD_DIR} --prefix ${INSTALL_PREFIX})
run(${CMAKE_COMMAND} -S ${CONSUMER_SRC} -B ${CONSUMER_BUILD}
    -DSketchUpCppAPI_DIR=${INSTALL_PREFIX}/cmake
    -DTEST_SOURCE=${TEST_SOURCE})
run(${CMAKE_COMMAND} --build ${CONSUMER_BUILD})
