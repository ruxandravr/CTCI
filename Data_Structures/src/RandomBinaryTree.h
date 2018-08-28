#ifndef CTCI_RANDOM_BINARY_TREE_H
#define CTCI_RANDOM_BINARY_TREE_H

#include <cstdlib>
#include <iostream>
#include <vector>

template <typename V>
class RandomBinaryTree
{
private:
  RandomBinaryTree<V> *left, *right;
  V value;
  bool hasValue;
  int children;
  V getRandomValueHelper(int random);
  void deleteNode();
  RandomBinaryTree<V>* searchValue(V value);

public:
  RandomBinaryTree();
  RandomBinaryTree(V value);
  void insert(V value);
  void deleteValue(V value);
  void inorder(std::vector<V> &traversal);
  int getSize();
  V getRandomValue();
};

/* Default Constructor*/
template <typename V>
RandomBinaryTree<V>::RandomBinaryTree()
{
  left = right = nullptr;
  hasValue = false;
  children = 0;
}

/* Constructor */
template <typename V>
RandomBinaryTree<V>::RandomBinaryTree(V value)
{
  left = right = nullptr;
  this->value = value;
  hasValue = true;
  children = 0;
}

/* Get the size of the subtree (number of children + 1->this node) */
template <typename V>
int RandomBinaryTree<V>::getSize()
{
  if (this == nullptr) {
    return 0;
  }
  return this->children + 1;
}

/* Inorder insert a node in the tree. */
template <typename V>
void RandomBinaryTree<V>::insert(V value)
{
  if (!hasValue) {
    this->value = value;
    hasValue = true;
  } else if (value <=  this->value) {
    this->children++;
    if (left != nullptr) {
      left->insert(value);
    } else {
      left = new RandomBinaryTree<V>(value);
    }
  } else {
    this->children++;
    if (right != nullptr) {
      right->insert(value);
    } else {
      right = new RandomBinaryTree<V>(value);
    }
  }
}

/* Search for a value in the tree. */
template <typename V>
RandomBinaryTree<V>* RandomBinaryTree<V>::searchValue(V value)
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

/* Inorder delete a node in the tree. */
template <typename V>
void RandomBinaryTree<V>::deleteNode()
{
  if (this == nullptr) {
    return;
  }

  if (left == nullptr && right == nullptr) {
    hasValue = false;
    delete this;
  } else {
    RandomBinaryTree<V> *next = this;
    children--;  // update children
    if (next->left != nullptr) {
      next = next->left;
      next->children--;  // update children
      while (next->right != nullptr) {
        next = next->right;
        next->children--;  // update children
      }
    } else if (next->right != nullptr) {
      next = next->right;
      next->children--;
      while (next->left != nullptr) {
        next = next->left;
        next->children--;
      }
    }
    this->value = next->value;
    next->children++;
    next->deleteNode();
  }
}

/* Delete a value if it exists in the treee. */
template <typename V>
void RandomBinaryTree<V>::deleteValue(V value)
{
  RandomBinaryTree<V> *toDelete = searchValue(value);
  if (toDelete == nullptr) {
    return;
  } else {
    toDelete->deleteNode();
  }
}

/* Store the inorder traversal of the tree in a vector. */
template <typename V>
void RandomBinaryTree<V>::inorder(std::vector<V> &traversal)
{
  if (left != nullptr) {
    left->inorder(traversal);
  }
  if (hasValue) {
    traversal.push_back(value);
    // std::cout << this->value << " ";
  }
  if (right != nullptr) {
    right->inorder(traversal);
  }
}

/* Get a random value from the tree. */
template <typename V>
V RandomBinaryTree<V>::getRandomValue()
{
  /* Generate a random number from 0 to the number of nodes in the tree. */
  int random = rand() % getSize();
  /* Return the node with the random position. */
  return getRandomValueHelper(3);
}

/* Retrun a node with a given position by binary searching for that node.
If the position is smaller than the left subtree number of children, check
for the node in the last subtree. If the posion is equal to the left subtree
number of children, the node we are looking for is the root. Otherwise, the
node is in the right subtree, and its position is smaller with (the number of
children in the left subtree + 1 (the root)). */
template <typename V>
V RandomBinaryTree<V>::getRandomValueHelper(int random)
{
  if (left->getSize() == random) {
    return value;
  }
  if (random < left->getSize()) return left->getRandomValueHelper(random);
  return right->getRandomValueHelper(random - left->getSize() - 1);
}

#endif