#ifndef CTCI_MINIMAL_BST_H
#define CTCI_MINIMAL_BST_H

#include <iostream>
#include <vector>

template <typename V>
class BSTNode
{
public:
  V value;
  BSTNode *left, *right;
  BSTNode(V value)
  {
    left = right = nullptr;
    this->value = value;
  }
};

template <typename V>
class MinimalBST
{
private:
  BSTNode<V> *root;

public:
  MinimalBST(std::vector<V> array);
  BSTNode<V>* createMinimalBST(std::vector<int> array, int start, int end);
  void inorder(BSTNode<V> *node, std::vector<V> &sorted);
  BSTNode<V>* getRoot();
  static bool validateBST(BSTNode<V> *node, V &lastValue);
};

/* Create a tree from an array. */
template <typename V>
MinimalBST<V>::MinimalBST(std::vector<V> array)
{
  root = createMinimalBST(array, 0, array.size()-1);

}

/* Recursively insert nodes in the middle of the array: */
template <typename V>
BSTNode<V>* MinimalBST<V>::createMinimalBST(std::vector<int> array, int start, int end)
{
  if (start > end) {
    return nullptr;
  }

  /* The root is the middle node. */
  int mid = (start + end) / 2;
  BSTNode<V> *node = new BSTNode<V>(array[mid]);
  /* The left child is the middle element from the first half of the array. */
  node->left = createMinimalBST(array, start, mid - 1);
  /* The right child is the middle element from the last half of the array. */
  node->right = createMinimalBST(array, mid + 1, end);
  return node;
}

/* Inorder traversal of the tree by inserting the sorting elements into an array. */
template <typename V>
void MinimalBST<V>::inorder(BSTNode<V> *node, std::vector<V> &sorted)
{
  if (node->left != nullptr) {
    inorder(node->left, sorted);
  }
  sorted.push_back(node->value);
  if (node->right != nullptr) {
    inorder(node->right, sorted);
  }
}

template <typename V>
BSTNode<V>* MinimalBST<V>::getRoot()
{
  return root;
}

/* Verifying if a tree is a binary search tree by traversing it inorder and
verifying that current element is bigger than the previous one. */
template <typename V>
bool MinimalBST<V>::validateBST(BSTNode<V> *node, V &lastValue)
{
  if (node->left != nullptr) {
    validateBST(node->left, lastValue);
  }

  if (lastValue != INT32_MIN && node->value < lastValue) {
    return false;
  }
  lastValue = node->value;

  if (node->right != nullptr) {
    validateBST(node->right, lastValue);
  }

  return true;
}

#endif