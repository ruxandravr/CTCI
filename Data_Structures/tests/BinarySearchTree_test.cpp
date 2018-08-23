#include "../src/BinarySearchTree.h"
#include <gtest/gtest.h>

#include <vector>

TEST(BinarySearchTree, Inserting)
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(6);
  bst.insert(7);

  bst.insert(3);
  bst.insert(4);
  bst.insert(10);
  bst.insert(9);
  bst.insert(1);


  ASSERT_EQ(5, bst.searchValue(5)->getValue());
  ASSERT_EQ(nullptr, bst.searchValue(0));

}

TEST(BinarySearchTree, Deleting)
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(6);
  bst.insert(7);

  bst.insert(3);
  bst.insert(4);
  bst.insert(10);
  bst.insert(9);
  bst.insert(1);

  // bst.inorder();
  // std::cout << "\n";
  ASSERT_EQ(true, bst.deleteNodeWithValue(5));

  // bst.inorder();

}

TEST(BinarySearchTree, Height)
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(6);
  bst.insert(7);

  bst.insert(3);
  bst.insert(4);
  bst.insert(10);
  bst.insert(9);
  bst.insert(1);

  ASSERT_EQ(5, bst.height());

  std::vector <std::vector <int> > heightsList = {{5}, {3, 6}, {1, 4, 7}, {10}, {9}};
  ASSERT_EQ(heightsList, bst.getHeightsList());

}
TEST(BinarySearchTree, Balanced)
{
  BinarySearchTree<int> bst;
  bst.insert(7);
  bst.insert(3);
  bst.insert(4);
  bst.insert(1);
  bst.insert(5);
  bst.insert(6);
  bst.insert(9);
  bst.insert(8);
  bst.insert(10);
  bst.insert(11);

  ASSERT_EQ(false, bst.isBalanced());
}

TEST(BinarySearchTree, Balanced_V2)
{
  BinarySearchTree<int> bst;
  bst.insert(7);
  bst.insert(3);
  bst.insert(4);
  bst.insert(1);
  bst.insert(5);
  bst.insert(6);
  bst.insert(9);
  bst.insert(8);
  bst.insert(10);
  bst.insert(11);

  ASSERT_EQ(false, bst.isBalanced_v2());
}

TEST(BinarySearchTree, isBinary)
{
  BinarySearchTree<int> bst;
  bst.insert(7);
  bst.insert(3);
  bst.insert(4);
  bst.insert(1);
  bst.insert(5);
  bst.insert(6);
  bst.insert(9);
  bst.insert(8);
  bst.insert(10);
  bst.insert(11);

  int min = INT32_MIN;
  int max = INT32_MAX;

  ASSERT_EQ(true, bst.validateBST(min, max));
}

TEST(BinarySearchTree, Succesor)
{
  BinarySearchTree<int> bst;
  bst.insert(7);
  bst.insert(3);
  bst.insert(4);
  bst.insert(1);
  bst.insert(5);
  bst.insert(6);
  bst.insert(9);
  bst.insert(8);
  bst.insert(10);
  bst.insert(11);

  std::vector<BinarySearchTree<int>*> nodes;
  bst.inorder(nodes);

  std::cout << "\n";
  ASSERT_EQ(3, bst.succesor(nodes[0])->getValue());
  ASSERT_EQ(4, bst.succesor(nodes[1])->getValue());
  ASSERT_EQ(5, bst.succesor(nodes[2])->getValue());
  ASSERT_EQ(6, bst.succesor(nodes[3])->getValue());
  ASSERT_EQ(7, bst.succesor(nodes[4])->getValue());
  ASSERT_EQ(8, bst.succesor(nodes[5])->getValue());
  ASSERT_EQ(9, bst.succesor(nodes[6])->getValue());
  ASSERT_EQ(10, bst.succesor(nodes[7])->getValue());
  ASSERT_EQ(11, bst.succesor(nodes[8])->getValue());
  ASSERT_EQ(0, bst.succesor(nodes[9]));


}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}