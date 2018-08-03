#ifndef CTCI_BINARY_SEARCH_TREE
#define CTCI_BINARY_SEARCH_TREE

#include <iostream>

template <typename V>
class BinarySearchTree
{
private:
  V value;
  BinarySearchTree<V> *left, *right, *parent;

public:
  BinarySearchTree();
  BinarySearchTree(V value);
  // ~BinarySearchTree();
  void insert(V value);
  BinarySearchTree* searchValue(V value);
  void deleteSelf();
  bool deleteNodeWithValue(V value);
  bool hasValue;
  void inorder();
  V getValue();
};

template <typename V>
BinarySearchTree<V>::BinarySearchTree()
{
  left = right = parent = nullptr;
  hasValue = false;
}

template <typename V>
BinarySearchTree<V>::BinarySearchTree(V value)
{
  left = right = parent = nullptr;
  this->value = value;
  hasValue = true;
}

template <typename V>
V BinarySearchTree<V>::getValue()
{
  return value;
}

template <typename V>
void BinarySearchTree<V>::insert(V value)
{
  /* If it's empty. */
  if (hasValue == false) {
    this->value = value;
    hasValue = true;
  } else if (value <= this->value) {
    if (left == nullptr) {
      left = new BinarySearchTree<V>(value);
      left->parent = this;
    } else {
      left->insert(value);
    }
  } else {
    if (right == nullptr) {
      right = new BinarySearchTree<V>(value);
      right->parent = this;
    } else {
      right->insert(value);
    }
  }
}

template <typename V>
BinarySearchTree<V>* BinarySearchTree<V>::searchValue(V value)
{
  /* If it's empty. */
  if (hasValue == false) {
    return nullptr;
  } else if (value < this->value) {
    if (left != nullptr) {
      return left->searchValue(value);
    }
  } else if (value == this->value) {
    return this;
  } else if (value > this->value) {
    if (right != nullptr) {
      return right->searchValue(value);
    }
  }
  return nullptr;
}

template <typename V>
void BinarySearchTree<V>::deleteSelf()
{
  BinarySearchTree<V> *following = this;
  if (left == nullptr && right == nullptr) {
    if (this == parent->left) {
      parent->left = nullptr;
    } else if (this == parent->right) {
      parent->right = nullptr;
    }
    delete this;
  } else {
    if (left != nullptr) {
      following = left;
      while (following->right != nullptr) {
        following = following->right;
      }
    } else {
      following = right;
      while (following->left != nullptr) {
        following = following->left;
      }
    }
    this->value = following->value;
    following->deleteSelf();
  }
}

template <typename V>
bool BinarySearchTree<V>::deleteNodeWithValue(V value)
{
  BinarySearchTree<V> *node = searchValue(value);
  if (node == nullptr) {
    return false;
  }
  node->deleteSelf();
  return true;
}


template <typename V>
void BinarySearchTree<V>::inorder()
{
  if (left != nullptr) {
    left->inorder();
  }
  std::cout << value << " ";
  if (right != nullptr) {
    right->inorder();
  }
}
#endif