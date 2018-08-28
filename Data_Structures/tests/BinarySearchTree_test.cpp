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

TEST(BinarySearchTree, FirstCommonAncestor)
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

  ASSERT_EQ(3, bst.firstCommonAncestor(nodes[0], nodes[4])->getValue());
  ASSERT_EQ(7, bst.firstCommonAncestor(nodes[3], nodes[7])->getValue());
  ASSERT_EQ(7, bst.firstCommonAncestor(nodes[0], nodes[6])->getValue());
  ASSERT_EQ(7, bst.firstCommonAncestor(nodes[2], nodes[6])->getValue());
  ASSERT_EQ(3, bst.firstCommonAncestor(nodes[0], nodes[2])->getValue());
  ASSERT_EQ(7, bst.firstCommonAncestor(nodes[0], nodes[1])->getValue());

}

TEST(BinarySearchTree, Contains)
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

  ASSERT_EQ(true, bst.contains(nodes[2]));
}


TEST(BinarySearchTree, FirstCommonAncestor_v2)
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

  ASSERT_EQ(3, bst.firstCommonAncestor_v2(nodes[0], nodes[4])->getValue());
  ASSERT_EQ(7, bst.firstCommonAncestor_v2(nodes[3], nodes[7])->getValue());
  ASSERT_EQ(7, bst.firstCommonAncestor_v2(nodes[0], nodes[6])->getValue());
  ASSERT_EQ(7, bst.firstCommonAncestor_v2(nodes[2], nodes[6])->getValue());
  ASSERT_EQ(3, bst.firstCommonAncestor_v2(nodes[0], nodes[2])->getValue());
  ASSERT_EQ(7, bst.firstCommonAncestor_v2(nodes[0], nodes[1])->getValue());

}


TEST(BinarySearchTree, PathTo)
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

  std::vector<BinarySearchTree<int>*> path = bst.pathTo(nodes[3]);

  std::vector<int> result = {5, 4, 3, 7};
  int index = 0;
  for (auto n : path) {
    ASSERT_EQ(result[index], n->getValue());
    index++;
  }
}

TEST(BinarySearchTree, BSTsequence)
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(2);
  bst.insert(7);

  std::vector<std::list<int>> sequences = bst.BSTsequence();

  std::vector<std::list<int> > result = {{5, 7, 3, 2}, {5, 3, 7, 2}, {5, 3, 2, 7}};
  ASSERT_EQ(result, sequences);
}

TEST(BinarySearchTree, preorder)
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(2);
  bst.insert(7);

  std::string traversal = "";
  bst.preorder(traversal);
  std::string result = "532NNN7NN";
  ASSERT_EQ(result, traversal);
}


TEST(BinarySearchTree, subtree)
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(2);
  bst.insert(7);

  BinarySearchTree<int> bst1;
  bst1.insert(8);
  bst1.insert(5);
  bst1.insert(3);
  bst1.insert(2);
  bst1.insert(7);

  ASSERT_EQ(true, bst.isSubtree(bst1.getRoot(), bst.getRoot()));

  bst1.insert(1);
  ASSERT_EQ(false, BinarySearchTree<int>::isSubtree(bst1.getRoot(), bst.getRoot()));

}

TEST(BinarySearchTree, identical)
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(2);
  bst.insert(7);

  BinarySearchTree<int> bst1;
  // bst1.insert(8);
  bst1.insert(5);
  bst1.insert(3);
  bst1.insert(2);
  bst1.insert(7);

  ASSERT_EQ(true, bst1.isIdentical(bst.getRoot()));
}
TEST(BinarySearchTree, subtree_v2)
{
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(2);
  bst.insert(7);

  BinarySearchTree<int> bst1;
  bst1.insert(8);
  bst1.insert(5);
  bst1.insert(3);
  bst1.insert(2);
  bst1.insert(7);

  ASSERT_EQ(true, bst.isSubtree_v2(bst1.getRoot(), bst.getRoot()));

  bst1.insert(1);
  ASSERT_EQ(false, BinarySearchTree<int>::isSubtree_v2(bst1.getRoot(), bst.getRoot()));

}
TEST(BinarySearchTree, SumPaths)
{
  BinarySearchTree<int> bst;
  bst.insert(10);
  bst.insert(8);
  bst.insert(15);
  bst.insert(11);
  bst.insert(7);
  bst.insert(9);
  bst.insert(6);
  bst.insert(5);


  ASSERT_EQ(2, bst.totalSumPaths(36));
}

TEST(BinarySearchTree, SumPaths_v2)
{
  BinarySearchTree<int> bst;
  bst.insert(10);
  bst.insert(8);
  bst.insert(15);
  bst.insert(11);
  bst.insert(7);
  bst.insert(9);
  bst.insert(6);
  bst.insert(5);


  ASSERT_EQ(1, bst.totalSumPaths_v2(10));
  ASSERT_EQ(2, bst.totalSumPaths_v2(26));

}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}