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
target_link_libraries(linkedListTest ${GTEST_LIBRARIES} pthread LinkedListLibrary)

# Link nodeTestTests with what we want to test and the GTest and pthread library
add_executable(nodeTest tests/Node_test.cpp)
target_link_libraries(nodeTest ${GTEST_LIBRARIES} pthread NodeLibrary)

# Link entryTestTests with what we want to test and the GTest and pthread library
add_executable(entryTest tests/Entry_test.cpp)
target_link_libraries(entryTest ${GTEST_LIBRARIES} pthread EntryLibrary)

# Link vectorTestTests with what we want to test and the GTest and pthread library
add_executable(vectorTest tests/Vector_test.cpp)
target_link_libraries(vectorTest ${GTEST_LIBRARIES} pthread VectorLibrary)

# Link hashtableTestTests with what we want to test and the GTest and pthread library
add_executable(hashtableTest tests/Hashtable_test.cpp)
target_link_libraries(hashtableTest ${GTEST_LIBRARIES} pthread HashtableLibrary)

# Link myhashtableTestTests with what we want to test and the GTest and pthread library
add_executable(myhashtableTest tests/MyHashtable_test.cpp)
target_link_libraries(myhashtableTest ${GTEST_LIBRARIES} pthread MyHashtableLibrary)