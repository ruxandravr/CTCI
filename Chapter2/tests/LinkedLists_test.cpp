#include "../src/LinkedLists.h"
#include <gtest/gtest.h>

#include<list>

TEST(LinkedLists, RemoveDuplicates)
{
  std::list<int> l = {0, 1, 1, 2, 2, 3, 3, 3, 4, 1,2};
  LinkedLists<int>::removeDuplicates(l);
  std::list<int> result = {0, 1, 2, 3, 4};

  ASSERT_EQ(l, result);
}

TEST(LinkedLists, RemoveDuplicates_V2)
{
  std::list<int> l = {0, 1, 1, 2, 2, 3, 3, 3, 4, 1,2};
  LinkedLists<int>::removeDuplicates_v2(l);
  std::list<int> result = {0, 1, 2, 3, 4};

  ASSERT_EQ(l, result);
}

TEST(LinkedLists, KthToLast)
{
  std::list<int> l = {0, 1, 1, 2, 2, 3, 3, 3, 4, 1, 2};

  ASSERT_EQ(1, LinkedLists<int>::kthToLast(l, 2));

  ASSERT_EQ(3, LinkedLists<int>::kthToLast(l, 4));

}

TEST(LinkedLists, Partition)
{
  std::list<int> l = {1, 2, 7, 10, 4, 9, 5, 3, 5, 2, 11, 2};
  std::list<int> result = {1, 2, 4, 3, 2, 2, 7, 10, 9, 5, 5, 11};
  LinkedLists<int>::partition(l, 5);

  ASSERT_EQ(l, result);
}

TEST(LinkedLists, add)
{
  std::list<int> l1 = {1, 9, 2};
  std::list<int> l2 = {0, 9};

  std::list<int> result = {1, 8, 3};
  std::list<int> addResult = LinkedLists<int>::add(l1, l2);

  ASSERT_EQ(result, addResult);
}

TEST(LinkedLists, add_v2)
{
  std::list<int> l1 = {9, 9, 9};
  std::list<int> l2 = {9, 9, 9};

  std::list<int> result = {1, 9, 9, 8};
  std::list<int> addResult = LinkedLists<int>::add_v2(l1, l2);

  ASSERT_EQ(result, addResult);
}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}