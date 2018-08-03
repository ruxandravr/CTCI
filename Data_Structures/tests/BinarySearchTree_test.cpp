#include "../src/BinarySearchTree.h"
#include <gtest/gtest.h>

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
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}