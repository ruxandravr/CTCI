#ifndef CTCI_MIN_HEAP_H
#define CTCI_MIN_HEAP_H

#include <iostream>
#include <vector>

template <typename V>
class MinHeap
{
private:
  std::vector<V> heap;
  void swap(int parent, int child);

public:
  void insert(V value);
  V getMin();
  void extractMin();
  void heapifyUp();
  void heapifyDown();
  V getLeftChild(int index);
  V getRightChild(int index);
  V getParent(int index);
  bool hasLeftChild(int index);
  bool hasRightChild(int index);
  void print();
  std::vector<V> getHeap();
};

template <typename V>
V MinHeap<V>::getLeftChild(int index)
{
  return heap[2 * index + 1];
}

template <typename V>
V MinHeap<V>::getRightChild(int index)
{
  return heap[2 * index + 2];
}

template <typename V>
V MinHeap<V>::getParent(int index)
{
  return heap[(index - 1) / 2];
}

template <typename V>
bool MinHeap<V>::hasLeftChild(int index)
{
  return (index * 2 + 1) <= heap.size();
}

template <typename V>
bool MinHeap<V>::hasRightChild(int index)
{
  return (index * 2 + 2) <= heap.size();
}

/* Insert the node at the end of the heap and then establish the heap property
from bottom to top. */
template <typename V>
void MinHeap<V>::insert(V value)
{
  heap.push_back(value);
  if (heap.size() > 1) {
    heapifyUp();
  }
}

template <typename V>
V MinHeap<V>::getMin()
{
  if (heap.empty()) return V();

  return heap[0];
}

/* Replace the first element with the last one and then establish the heap
property from bottom to top. */
template <typename V>
void MinHeap<V>::extractMin()
{
  if (heap.empty()) return;

  heap[0] = heap[heap.size() - 1];
  heap.pop_back();
  heapifyDown();
}

/* Swap first node with one of its children so than no children can be smaller
than parent. */
template <typename V>
void MinHeap<V>::heapifyDown()
{
  int parent = 0;

  while ((hasLeftChild(parent) &&  heap[parent] > getLeftChild(parent)) ||
         (hasRightChild(parent) && heap[parent] > getRightChild(parent))) {
    int childIndex = getLeftChild(parent) < getRightChild(parent) ? (2 * parent + 1) :
                     (2 * parent + 2);
    swap(parent, childIndex);
    parent = childIndex;
  }
}

/* Swap child nodes with parent nodes so than no children can be smaller
than parent. */
template <typename V>
void MinHeap<V>::heapifyUp()
{
  int index = heap.size() - 1;

  while (heap[index] < getParent(index)) {
    int parent = (index - 1) / 2;
    swap(parent, index);
    index = parent;
  }
}

template <typename V>
void MinHeap<V>::swap(int parent, int child)
{
  V tmp = heap[parent];
  heap[parent] = heap[child];
  heap[child] = tmp;
}

template <typename V>
void MinHeap<V>::print()
{
  for (auto elem : heap) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

template <typename V>
std::vector<V> MinHeap<V>::getHeap() {
    return heap;
}

#endif