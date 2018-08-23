#include "../src/MinimalBST.h"
#include <gtest/gtest.h>

#include <iostream>
#include <vector>

TEST(MinimalBST, Inserting)
{
  std::vector<int> v = {1,2,3,4,5,6,7,8,9};
  MinimalBST<int> bst(v);
  std::vector<int> result;
  bst.inorder(bst.getRoot(), result);
  ASSERT_EQ(v, result);

}

TEST(MinimalBST, Validate)
{
  std::vector<int> v = {1,2,3,4,5,6,7,8,9};
  MinimalBST<int> bst(v);
  int min = INT32_MIN;
  ASSERT_EQ(true, MinimalBST<int>::validateBST(bst.getRoot(), min));

  v.push_back(0);
  MinimalBST<int> bst2(v);
  ASSERT_EQ(false, MinimalBST<int>::validateBST(bst.getRoot(), min));

}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}