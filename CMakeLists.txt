# Check that the build does not happen in the source tree
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
   MESSAGE(FATAL_ERROR "Prevented in-tree built. Try again using CMake in the build folder.")
ENDIF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

# Project wide settings
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(wf-cabinet-transactions)

# Set compiler and linker flags
add_compile_options(-c -g -std=c++0x -Wall -Wextra -pedantic -pthread)

# Create SOURCES variable that contain the used source files
set(
    SOURCES
    src/transactionLogger.hpp src/transactionLogger.cpp
)

# Add main
ADD_EXECUTABLE(
    main
    src/main.cpp
    ${SOURCES}
)
target_link_libraries(
    main
    pthread
)

# Add tests
enable_testing()
# Included as source code, because google test library must be built with
# the same flags as the C++ code under test
add_subdirectory(lib/gtest-1.7.0)
include_directories(lib/gtest-1.7.0/include)
ADD_EXECUTABLE(
    qtests
    test/test_transactionLogger.cpp
    ${SOURCES}
)
target_link_libraries(
    qtests
    pthread
    gtest
    gtest_main
)
add_test( qtests qtests )


endif()
