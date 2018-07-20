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


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}