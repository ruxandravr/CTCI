#include "../src/RandomBinaryTree.h"
#include <gtest/gtest.h>

#include <vector>

TEST(RandomBinaryTree, Inserting)
{
  RandomBinaryTree<int> bst;
  bst.insert(5);
  bst.insert(6);
  bst.insert(7);

  bst.insert(3);
  bst.insert(4);
  bst.insert(10);
  bst.insert(9);
  bst.insert(1);

  std::vector<int> result = {1, 3, 4, 5, 6, 7, 9, 10};  
  std::vector<int> traversal;
  bst.inorder(traversal);
  ASSERT_EQ(result, traversal);
}

TEST(RandomBinaryTree, Deleting)
{
  RandomBinaryTree<int> bst;
  bst.insert(8);
  bst.insert(2);
  bst.insert(5);

  bst.insert(4);
  bst.insert(1);

  bst.deleteValue(8);

  std::vector<int> result = {1, 2, 4, 5};  
  std::vector<int> traversal;
  bst.inorder(traversal);
  ASSERT_EQ(result, traversal);
}

TEST(RandomBinaryTree, RandomNumber)
{
  RandomBinaryTree<int> bst;
  bst.insert(8);
  bst.insert(2);
  bst.insert(5);

  bst.insert(4);
  bst.insert(1);

  // somehow the random generator always picks the value
  ASSERT_EQ(5, bst.getRandomValue());
}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}