cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include src/ directory for gathering all the needed libraries
include_directories ("${PROJECT_SOURCE_DIR}/src")
add_subdirectory(src)

# Link linkedListTestTests with what we want to test and the GTest and pthread library
add_executable(linkedListTest tests/LinkedList_test.cpp)
target_link_libraries(linkedListTest ${GTEST_LIBRARIES} pthread LinkedListLibrary NodeLibrary)

# Link linkedListTestTests with what we want to test and the GTest and pthread library
add_executable(nodeTest tests/Node_test.cpp)
target_link_libraries(nodeTest ${GTEST_LIBRARIES} pthread NodeLibrary)