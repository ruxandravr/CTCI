cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include src/ directory for gathering all the needed libraries
include_directories ("${PROJECT_SOURCE_DIR}/src")
add_subdirectory(src)

# Link multiStackTestTests with what we want to test and the GTest and pthread library
add_executable(multiStackTest tests/multiStack_test.cpp)
target_link_libraries(multiStackTest ${GTEST_LIBRARIES} pthread multiStackLibrary)

# Link multiStackTestTests with what we want to test and the GTest and pthread library
add_executable(fixedMultiStackTest tests/fixedMultiStack_test.cpp)
target_link_libraries(fixedMultiStackTest ${GTEST_LIBRARIES} pthread fixedMultiStackLibrary)

# Link MinStackTestTests with what we want to test and the GTest and pthread library
add_executable(MinStackTest tests/MinStack_test.cpp)
target_link_libraries(MinStackTest ${GTEST_LIBRARIES} pthread MinStackLibrary)
