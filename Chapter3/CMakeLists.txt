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

# Link MinStack_v2TestTests with what we want to test and the GTest and pthread library
add_executable(MinStack_v2Test tests/MinStack_v2_test.cpp)
target_link_libraries(MinStack_v2Test ${GTEST_LIBRARIES} pthread MinStack_v2Library)

# Link SetOfStacksTestTests with what we want to test and the GTest and pthread library
add_executable(SetOfStacksTest tests/SetOfStacks_test.cpp)
target_link_libraries(SetOfStacksTest ${GTEST_LIBRARIES} pthread SetOfStacksLibrary)

# Link SetOfStacks_v2TestTests with what we want to test and the GTest and pthread library
add_executable(SetOfStacks_v2Test tests/SetOfStacks_v2_test.cpp)
target_link_libraries(SetOfStacks_v2Test ${GTEST_LIBRARIES} pthread SetOfStacks_v2Library)

# Link QueueWithStacksTestTests with what we want to test and the GTest and pthread library
add_executable(QueueWithStacksTest tests/QueueWithStacks_test.cpp)
target_link_libraries(QueueWithStacksTest ${GTEST_LIBRARIES} pthread QueueWithStacksLibrary)

# Link QueueWithStacksTestTests with what we want to test and the GTest and pthread library
add_executable(SortedStackTest tests/SortedStack_test.cpp)
target_link_libraries(SortedStackTest ${GTEST_LIBRARIES} pthread SortedStackLibrary)


# Link AnimalShelterTestTests with what we want to test and the GTest and pthread library
add_executable(AnimalShelterTest tests/AnimalShelter_test.cpp)
target_link_libraries(AnimalShelterTest ${GTEST_LIBRARIES} pthread AnimalShelterLibrary)