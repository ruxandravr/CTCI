cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include src/ directory for gathering all the needed libraries
include_directories ("${PROJECT_SOURCE_DIR}/src")
add_subdirectory(src)

# Link linkedListTestTests with what we want to test and the GTest and pthread library
add_executable(LinkedListsTest tests/LinkedLists_test.cpp)
target_link_libraries(LinkedListsTest ${GTEST_LIBRARIES} pthread LinkedListsLibrary)
