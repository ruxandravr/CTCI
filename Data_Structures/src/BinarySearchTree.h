#ifndef CTCI_BINARY_SEARCH_TREE
#define CTCI_BINARY_SEARCH_TREE

#include <iostream>
#include <vector>

template <typename V>
class BinarySearchTree
{
private:
  V value;
  BinarySearchTree<V> *left, *right, *parent;
  bool hasValue;
  bool visited;
  std::vector<BinarySearchTree<V>*> nodesTraversal;

  /* Chapter 4 functions */
  std::vector<std::vector<V> > heightsList;
  int checkNodeBalance(int &hl, int &hr);


public:
  BinarySearchTree();
  BinarySearchTree(V value);
  ~BinarySearchTree();
  void insert(V value);
  BinarySearchTree* searchValue(V value);
  void deleteSelf();
  bool deleteNodeWithValue(V value);
  void inorder(std::vector<BinarySearchTree<V>*> &nodesTraversal);
  int height();
  V getValue();

  /* Chapter 4 functions */
  void printHeightList();
  void createLists();
  void traverse(int height, std::vector<std::vector<V> > &heightsList);
  std::vector<std::vector <V> > getHeightsList();
  bool isBalanced();
  bool isBalanced_v2();
  int heightHelper();
  bool validateBST(V &min, V &max);
  BinarySearchTree<V>* succesor(BinarySearchTree<V> *node);
};

/* Constructor */
template <typename V>
BinarySearchTree<V>::BinarySearchTree()
{
  left = right = parent = nullptr;
  hasValue = false;
  visited = false;
}

/* Destructor */
template <typename V>
BinarySearchTree<V>::~BinarySearchTree()
{
  while (left != nullptr) {
    left->deleteSelf();
  }
  while (right != nullptr) {
    right->deleteSelf();
  }
}

template <typename V>
BinarySearchTree<V>::BinarySearchTree(V value)
{
  left = right = parent = nullptr;
  this->value = value;
  hasValue = true;
  visited = false;
}

template <typename V>
V BinarySearchTree<V>::getValue()
{
  return value;
}

/* Insert a node in the tree */
template <typename V>
void BinarySearchTree<V>::insert(V value)
{
  /* If it's empty. */
  if (hasValue == false) {
    this->value = value;
    hasValue = true;
    /* If smaller than actual value insert in the left subtree, otherwise
    insert in the right subtree. */
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

/* Search for a value in the tree. */
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

/* Replace a node with its inorder predecesor/succesor and delete that node. */
template <typename V>
void BinarySearchTree<V>::deleteSelf()
{
  BinarySearchTree<V> *following = this;
  /* If it is a leaf */
  if (left == nullptr && right == nullptr) {
    /* left child*/
    if (this == parent->left) {
      parent->left = nullptr;
    } else if (this == parent->right) {
      /* right child */
      parent->right = nullptr;
    }
    delete this;
    /* if it has children */
  } else {
    if (left != nullptr) {
      /* if it has left child, get to the rightmost */
      following = left;
      while (following->right != nullptr) {
        following = following->right;
      }
    } else {
      /* if it has right child, get to the leftmost */
      following = right;
      while (following->left != nullptr) {
        following = following->left;
      }
    }
    this->value = following->value;
    following->deleteSelf();
  }
}

/* Search for the node and if it exists delete it. */
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

/* Inorder traversal of the tree by inserting references to nodes into an array.*/
template <typename V>
void BinarySearchTree<V>::inorder(std::vector<BinarySearchTree<V>*> &nodesTraversal)
{
  if (left != nullptr) {
    left->inorder(nodesTraversal);
  }

  // std::cout << this->value << " ";
  nodesTraversal.push_back(this);

  if (right != nullptr) {
    right->inorder(nodesTraversal);
  }
}

/* Recursive function for computing the height of a tree
  height = 1 + maxHeigh(leftSubtree, rightSubtree). */
template <typename V>
int BinarySearchTree<V>::height()
{
  int hl = 0, hr = 0;

  if (left == nullptr && right == nullptr) {
    return 1;
  }
  if (left != nullptr) {
    hl =  1 + left->height();
  }

  if (right != nullptr) {
    hr =  1 + right->height();
  }

  return (hl > hr) ? hl : hr;
}

/* Create a vector of vectors (one for each height) and traverse the tree to
complete them. */
template<typename V>
void BinarySearchTree<V>::createLists()
{
  int h = height();
  heightsList = std::vector<std::vector<V> >(h);
  traverse(0, heightsList);
}

/* Recursively traverse the tree by inserting a node in its height list. */
template<typename V>
void BinarySearchTree<V>::traverse(int height, std::vector<std::vector<V> > &heightsList)
{
  /* Don't add the same node twice. */
  if (!this->visited) {
    heightsList[height].push_back(this->value);
    this->visited = true;
  }

  /* Traverse left subtree with increased height. */
  if (left != nullptr && !left->visited) {
    left->traverse(height + 1, heightsList);
  }

  /* Traverse right subtree with increased height. */
  if (right != nullptr && !right->visited) {
    right->traverse(height + 1, heightsList);
  }
}

/* Print each height list. */
template <typename V>
void BinarySearchTree<V>::printHeightList()
{
  createLists();
  for (int i = 0; i < heightsList.size(); ++i) {
    std::cout << i << ": ";
    for (auto elem : heightsList[i]) {
      std::cout << elem << " ";
    }
    std::cout << "\n";
  }
}

template <typename V>
std::vector<std::vector <V> > BinarySearchTree<V>::getHeightsList()
{
  createLists();
  return heightsList;
}

/* Check if a node is balanced: retain its left subtree height and right subtree
height. */
template <typename V>
int BinarySearchTree<V>:: checkNodeBalance(int &hl, int &hr)
{
  int hl1= 0, hr1 = 0;
  if (left == nullptr && right == nullptr) {
    return 1;
  }

  if (left != nullptr) {
    hl1 = 1 + left->checkNodeBalance(hl, hr);
  }

  if (right != nullptr) {
    hr1 = 1 + right->checkNodeBalance(hl, hr);
  }

  hl = hl1;
  hr = hr1;
  return (hl > hr) ? hl : hr;
}

/* Verify if each node is balanced: its left subtree height isn't grater or
smaller with more than 1 than its right subtree height. */
template <typename V>
bool BinarySearchTree<V>::isBalanced()
{
  if (left == nullptr && right == nullptr) {
    return true;
  }

  int hl = 0, hr = 0;
  checkNodeBalance(hl, hr);
  if (abs(hl - hr) > 1) {
    return false;
  }

  if (left != nullptr) {
    return left->isBalanced();
  }

  if (right != nullptr) {
    return right->isBalanced();
  }
}

/* Simultaneously calculate the height of a tree and check if it's balanced.
When discovering an unbalanced node, the function return INT32_MIN value. */
template <typename V>
int BinarySearchTree<V>::heightHelper()
{
  if (left == nullptr && right == nullptr) {
    return 0;
  }

  int hl = 0, hr = 0;

  if (left != nullptr) {
    hl = left->heightHelper();
  }

  if (right != nullptr) {
    hr = right->heightHelper();
  }

  if (abs (hl - hr) > 1) {
    return INT32_MIN;
  }
  if (hl != INT32_MIN && hr != INT32_MIN) {
    return (hl > hr) ? 1 + hl : 1 + hr;
  }

  return INT32_MIN;

}

/* Verify if a tree is balanced or not by using the result of the previous
function.*/
template <typename V>
bool BinarySearchTree<V>::isBalanced_v2()
{
  if (heightHelper() == INT32_MIN) {
    return false;
  }
  return true;
}

/* Verify if a tree is a binary search tree by checking if each value in the
tree is within a specific range. Firstly the range is infinite, than it modifies
when going to left or to right subtree. */
template <typename V>
bool BinarySearchTree<V>::validateBST(V &min, V &max)
{
  if (this->value < min || this->value > max) {
    return false;
  }

  /* Leaf is within the range. */
  if (this->value >= min && this->value <= max && left == nullptr && right == nullptr) {
    return true;
  }

  /* Going to left subtree -> modify the upper limit of the range. */
  if (left != nullptr) {
    return left->validateBST(min, this->value);
  }

  /* Going to right subtree -> modify the lower limit of the range. */
  if (right != nullptr) {
    return right->validateBST(this->value, max);
  }
}

/* Return the succesor of a given reference to a node. */
template <typename V>
BinarySearchTree<V>* BinarySearchTree<V>::succesor(BinarySearchTree<V> *node)
{
  if (node == nullptr) {
    return nullptr;
  }
  BinarySearchTree<V> *next, *current;

  /* If it has a right child, it's succesor it's the leftmost node from the
  right subtree.*/
  if (node->right != nullptr) {
    next = node->right;
    while (next->left != nullptr) {
      next = next->left;
    }
    /* Otherwise, the succesor is an upper node. */
  } else {
    current = node;
    /* Going up if the node is a right child (because all the parents were visited
    before). */
    while (current->parent->right == current) {
      current = current->parent;

      if (current->parent == nullptr) {
        return nullptr;
      }
    }
    next = current->parent;
  }
  return next;
}

#endif