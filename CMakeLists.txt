cmake_minimum_required(VERSION 3.10)
project(css342_homework)

# https://stackoverflow.com/questions/66340703/how-to-force-cmake-to-use-the-new-version-of-cmp0077-allow-options-to-be-set-fr
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "-DDEBUG -g -O0")

# path to static library
Set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

# path to library
Set(CMAKE_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/src)

# path to executable
Set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# disable pthread on Windows
# https://github.com/google/googletest/issues/1051
# https://gist.github.com/kylemanna/d386526abafce0eea22b
find_package(Thread QUIET)
if (CMAKE_THREAD_LIBS_INIT)
    set(gtest_disable_pthreads OFF)
else ()
    message(STATUS "Disabling pthread in Google Test")
    set(gtest_disable_pthreads ON)
endif ()

# we use this to get code coverage
if (UNIX AND RUN_COV)
    message("coverage flag set")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif ()

# set up google test
include(ext_dependencies/googletest/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/ext_dependencies/googletest
        ${LIBRARY_OUTPUT_PATH}/ext_dependencies/googletest
)

include(CTest)

# testing targets
add_custom_target(function_tests COMMAND env GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND} -V -R _test)
add_custom_target(mem_tests COMMAND env GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND} --test-action memcheck)

add_subdirectory(src)
add_subdirectory(test)

# code coverage, only run on Linux (e.g. during Github Action)
if (UNIX AND RUN_COV)
    message("coverage flag set")
    include(ext_dependencies/coverage/CodeCoverage.cmake)
    append_coverage_compiler_flags()
    setup_target_for_coverage_lcov(
            NAME
            coverage_check
            EXECUTABLE
            ${PROJECT_NAME}_unit_test
            EXCLUDE
            "${PROJECT_SOURCE_DIR}/lib/*"
            "${PROJECT_SOURCE_DIR}/ext_dependencies/*"
            "${PROJECT_SOURCE_DIR}/build/*"
            "${PROJECT_SOURCE_DIR}/build/*"
            "${PROJECT_SOURCE_DIR}/src/main.cpp"
            LCOV_ARGS
            "--no-external"
    )
endif ()
