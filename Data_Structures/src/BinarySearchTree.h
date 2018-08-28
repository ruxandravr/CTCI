#ifndef CTCI_BINARY_SEARCH_TREE
#define CTCI_BINARY_SEARCH_TREE

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>

template <typename V>
class BinarySearchTree
{
private:
  V value;
  BinarySearchTree<V> *left, *right, *parent;
  bool hasValue;
  bool visited;
  std::vector<BinarySearchTree<V>*> nodesTraversal;  // inorder vector of nodes

  /* Chapter 4 members */
  std::unordered_map<BinarySearchTree<V>*, std::unordered_map<BinarySearchTree<V>*, bool>> map;
  std::unordered_map<int, int> sums;

  /* Chapter 4 functions */
  std::vector<std::vector<V> > heightsList;
  int checkNodeBalance(int &hl, int &hr);
  int totalSumPathsHelper(int targetSum, int current, std::unordered_map<int, int> &sums);

public:
  BinarySearchTree();
  BinarySearchTree(V value);
  ~BinarySearchTree();
  BinarySearchTree<V>* getRoot();

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
  int nodeHeight(BinarySearchTree<V> *node);
  BinarySearchTree<V>* firstCommonAncestor(BinarySearchTree<V> *node1,
      BinarySearchTree<V> *node2);
  bool contains(BinarySearchTree<V> *node);
  BinarySearchTree<V>* firstCommonAncestor_v2(BinarySearchTree<V> *node1,
      BinarySearchTree<V> *node2);
  std::vector<BinarySearchTree<V>* > pathTo(BinarySearchTree<V> *node);
  void weave(std::list<V> &first, std::list<V> &second, std::vector<std::list<V> > &results,
             std::list<V> &result);
  void add(std::list<V> &result, std::list<V> other);
  std::vector<std::list <V> > BSTsequence();
  void preorder(std::string &traversal);
  static bool isSubtree(BinarySearchTree<V> *t1, BinarySearchTree<V> *t2);
  bool isIdentical(BinarySearchTree<V> *tree);
  static bool isSubtree_v2(BinarySearchTree<V> *t1, BinarySearchTree<V> *t2);
  int totalSumPaths(int targetSum);
  int totalSumPaths_v2(int targetSum);
  int sumPath(int targetSum, int currentSum);


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

template <typename V>
BinarySearchTree<V>* BinarySearchTree<V>::getRoot()
{
  return this;
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


/* Computes the height of a node by going up to the root. */
template <typename V>
int BinarySearchTree<V>::nodeHeight(BinarySearchTree<V> *node)
{
  int height = 0;
  while (node->parent != nullptr) {
    node = node->parent;
    height++;
  }
  return height;
}

/* Computes the first common ancestor by verifying the height of each node,
bringing the nodes to the same height, and gradually going up with each node
until finding a common parent. */
template<typename V>
BinarySearchTree<V>* BinarySearchTree<V>::firstCommonAncestor
(BinarySearchTree<V> *node1,BinarySearchTree<V> *node2)
{
  int height1 = nodeHeight(node1);
  int height2 = nodeHeight(node2);

  if (height1 >  height2) {
    for (int i = 0; i < height1 - height2; ++i) {
      node1 = node1->parent;
    }
  } else if (height2 >  height1) {
    for (int i = 0; i < height2 - height1; ++i) {
      node2 = node2->parent;
    }
  }

  while (node1->parent != node2->parent) {
    node1 = node1->parent;
    node2 = node2->parent;
  }

  return node1->parent;
}

/* Verify if a tree contains a given node. */
template <typename V>
bool BinarySearchTree<V>::contains(BinarySearchTree<V> *node)
{
  if (this == nullptr) {
    return false;
  }
  /* Use a map of maps to store each node contained in a tree. */
  if (map.find(this) != map.end()) {
    if (map[this].find(node) != map[this].end()) {
      return true;
    }
  }
  if (this == node) {
    map[this][node] = true;
    return true;
  }

  return (right->contains(node) || left->contains(node));
}

/* Compute the first common ancestor by verifying if the nodes are on different
sides -> fca = root, or recursively verifying for the left subtree or right subtree. */
template <typename V>
BinarySearchTree<V>* BinarySearchTree<V>::firstCommonAncestor_v2
(BinarySearchTree<V> *node1, BinarySearchTree<V> *node2)
{
  if (!contains(node1) || !contains(node2)) {
    return nullptr;
  }
  if ((left->contains(node1) && right->contains(node2)) ||
      (right->contains(node2) && left->contains(node1)))
    return this;

  if (left->contains(node1) && left->contains(node2)) {
    if (left == node1 || left == node2) {
      return this;
    }
    return left->firstCommonAncestor_v2(node1, node2);
  }

  if (right->contains(node1) && right->contains(node2)) {
    if (right == node1 || right == node2) {
      return this;
    }
    return right->firstCommonAncestor_v2(node1, node2);
  }
}

/* Function which returns a vector with the path to a given node (from root
to that node). */
template <typename V>
std::vector<BinarySearchTree<V>* > BinarySearchTree<V>::pathTo(BinarySearchTree<V> *node)
{
  std::vector<BinarySearchTree<V>* > empty;  // initially the path is empty
  if (this == nullptr) return empty;

  /* We reached the node, so we add it to the path. */
  if (this->value == node->value) {
    std::vector<BinarySearchTree<V>* > found = {node};
    return found;
  }

  /* In an upper node, check if the node was found in left or right subtree
  and add current element to the path. */
  std::vector<BinarySearchTree<V>* > leftPath = left->pathTo(node);
  std::vector<BinarySearchTree<V>* > rightPath = right->pathTo(node);

  if (leftPath.size() != 0) {
    leftPath.push_back(this);
    return leftPath;
  }

  if (rightPath.size() != 0) {
    rightPath.push_back(this);
    return rightPath;
  }

  return empty;
}

/* Function that combines two list of elements into a list of lists by keeping
the order of each element in the initial lists. */
template <typename V>
void  BinarySearchTree<V>::weave(std::list<V> &first, std::list <V> &second,
                                 std::vector<std::list<V> > &results, std::list<V> &result)
{
  /* If one of the initial lists is now empty, the other can be added to the
  current resulting list. */
  if (first.empty() || second.empty()) {
    std::list<V> solution = result;
    add(solution, first);
    add(solution, second);
    /* When we completed a list, we added to the result list of lists. */
    results.push_back(solution);
    return;
  }

  /* Take elements from the first list. */
  V firstElem = first.front();
  first.pop_front();
  result.push_back(firstElem);
  /* Continue recursing. */
  weave(first, second, results, result);
  /* Undo the changes. */
  first.push_front(firstElem);
  result.pop_back();


  /* Take elements from the first list. */
  V secondElem = second.front();
  second.pop_front();
  result.push_back(secondElem);
  /* Continue recursing. */
  weave(first, second, results, result);
  /* Undo the changes. */
  second.push_front(secondElem);
  result.pop_back();
}

/* Adds the element from other list to result list without changing other list. */
template <typename V>
void BinarySearchTree<V>::add(std::list<V> &result, std::list<V> other)
{
  while (!other.empty()) {
    result.push_back(other.front());
    other.pop_front();
  }
}

/* Generate all posbile sequences that led to this BST. One possible sequence
is represented as a list, and all lists go into a vector. A correct sequence
has on the first postion the root of the tree, and on next position the root
of the left or right subtree (their order isn't important), and so on... */
template <typename V>
std::vector<std::list <V> > BinarySearchTree<V>::BSTsequence()
{
  std::vector <std::list<V> > result;
  /* If we get to a null node, we return the vector with an empty list. */
  if (this == nullptr) {
    std::list<V> emptyList;
    result.push_back(emptyList);
    return result;
  }

  /* Find all possible sequences for the subtrees. */
  std::vector <std::list<V> > leftList = left->BSTsequence();
  std::vector <std::list<V> > rightList = right->BSTsequence();

  /* Combine each two lists from left and right subtree beacuse their order
  doesn't matter in obtaining a correct sequence. */
  for (auto llist : leftList) {
    for (auto rlist : rightList) {
      /* each list should have on the first position the current element (the
      root).*/
      std::list<V> root = {this->value};
      std::vector<std::list<V> > weaved;
      weave(llist, rlist, weaved, root);
      /* Push the resulting weaved list to the result vector. */
      while (!weaved.empty()) {
        result.push_back(weaved[weaved.size() - 1]);
        weaved.pop_back();
      }
    }
  }
  return result;
}

/* Store the preorder traversal of a BST in a string by marking the null nodes
with letter N. */
template <typename V>
void BinarySearchTree<V>::preorder(std::string &traversal)
{
  if (this == nullptr) {
    traversal += "N";
    return;
  }
  traversal += std::to_string(this->value);
  left->preorder(traversal);
  right->preorder(traversal);
}

/* Check if t2 is a subtree of t1. */
template <typename V>
bool BinarySearchTree<V>::isSubtree(BinarySearchTree<V> *t1, BinarySearchTree<V> *t2)
{
  if (t1 == nullptr || t2 == nullptr) {
    return false;
  }

  /* Preorder traverese both trees. */
  std::string traversal1 = "", traversal2 = "";
  t1->preorder(traversal1);
  t2->preorder(traversal2);

  /* Check if the second traversal is a substring of the first. */
  return traversal1.find(traversal2) != std::string::npos;
}

/* Check if this tree is identical to a given one. */
template <typename V>
bool BinarySearchTree<V>::isIdentical(BinarySearchTree<V> *tree)
{
  /* They are both null. */
  if (this == nullptr && tree == nullptr) {
    return true;
  }

  /* Only one of them is null. */
  if ((this == nullptr && tree != nullptr) || (tree == nullptr && this != nullptr)) {
    return false;
  }

  /* They have different root values. */
  if (this->value != tree->value) {
    return false;
  }

  /* Verify their subtrees. */
  return left->isIdentical(tree->left) && right->isIdentical(tree->right);
}

/* Check if t2 is a subtree of t1. */
template <typename V>
bool BinarySearchTree<V>::isSubtree_v2(BinarySearchTree<V> *t1, BinarySearchTree<V> *t2)
{
  if (t1 == nullptr && t2 == nullptr) {
    return true;
  }

  if ((t1 == nullptr && t2 != nullptr) || (t2 == nullptr && t1 != nullptr)) {
    return false;
  }

  /* When root values match, check if t2 is identical to the subtree of the t1
  root.*/
  if (t1->value == t2->value) {
    if (t1->isIdentical(t2))
      return true;
  }

  return isSubtree_v2(t1->left, t2) || isSubtree(t1->right, t2);
}

/* Check how many paths that start from the root are equal to targetSum. */
template <typename V>
int BinarySearchTree<V>::sumPath(int targetSum, int currentSum)
{
  /* Null node -> sum is 0 -> 0 paths. */
  if (this == nullptr) {
    return 0;
  }

  /* Current sum is the sum of all nodes till this node. */
  int sumsNumber = 0;
  currentSum += this->value;
  /* If we find the sum we found a new path. */
  if (currentSum == targetSum) {
    sumsNumber++;
  }

  /* Return the number of paths found till this node + number of paths found
  in subtrees. */
  return sumsNumber + left->sumPath(targetSum, currentSum) + right->sumPath(targetSum, currentSum);
}

/* Check how many paths in a tree (that start from any node) are equal to
targetSum. */
template <typename V>
int BinarySearchTree<V>::totalSumPaths(int targetSum)
{
  /* Null node -> sum is 0 -> 0 paths. */
  if (this == nullptr) {
    return 0;
  }

  /* Check the number of paths from the root. */
  int pathsFromRoot = sumPath(targetSum, 0);

  /* Check the number of paths from the subtrees (left/right child is the new root). */
  int pathsLeft = left->totalSumPaths(targetSum);
  int pathsRight = right->totalSumPaths(targetSum);

  return pathsFromRoot + pathsLeft + pathsRight;

}

/* Check how many paths in a tree (that start from any node) are equal to
targetSum by visiting each node only once and storing in a hastable all
sums found. */
template <typename V>
int BinarySearchTree<V>::totalSumPaths_v2(int targetSum)
{
  sums = std::unordered_map<int, int>();
  return totalSumPathsHelper(targetSum, 0, sums);
}

/* The hashtable stores for each sum found in the tree the number of apparitions
of that sum. */
template <typename V>
int BinarySearchTree<V>::totalSumPathsHelper(int targetSum, int currentSum, std::unordered_map<int, int> &sums)
{
  if (this == nullptr) {
    return 0;
  }

  /* Update the sum of the nodes until this current node. */
  currentSum += this->value;

  /* If we previous encountered a sum that is different from the current sum
  with the targetSum, than we found a good path.*/
  int totalPaths = (sums.find(currentSum - targetSum) != sums.end())? sums[currentSum - targetSum] : 0;

  /* Update the hasthable with the current sum. */
  if (sums.find(currentSum) != sums.end()) {
    sums[currentSum] = sums[currentSum] + 1;
  } else {
    sums[currentSum] = 1;
  }

  /* If the current sum is equal to the target sum, we have found another path. */
  if (currentSum == targetSum) {
    totalPaths++;
  }

  /* Calculate the total paths for both subtrees. */
  totalPaths += left->totalSumPathsHelper(targetSum, currentSum, sums);
  totalPaths += right->totalSumPathsHelper(targetSum, currentSum, sums);
  return totalPaths;
}
#endif