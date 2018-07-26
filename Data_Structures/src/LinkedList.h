#ifndef CTCI_LINKED_LIST_H
#define CTCI_LINKED_LIST_H

#include "Node.h"
#include "Hashtable.h"
#include <iostream>

template <typename V>
class LinkedList
{
private:
  Node<V> *first, *last;
  int size;

public:
  LinkedList();
  ~LinkedList();

  Node<V>* getFirstPtr() const;
  Node<V>* getLastPtr() const;
  LinkedList(const LinkedList<V> &other);
  LinkedList<V>& operator=(const LinkedList<V> &other);
  bool isEmpty() const;
  void addFirst(V value);
  void addLast(V value);
  void print();
  void removeFirst();
  void removeLast();
  bool contains(V value);
  bool equals(const LinkedList<V> &other);
  int getSize();

  /* Chapter 2 functions */
  /* Remove duplicates from a list */
  void removeDuplicates();
  void removeDuplicates_v2();

  /* Return k-th to last element */
  V kthToLast(int k);

  /* Partition the list by putting the smaller than a pivot elements on the left
  and the greater or eqaul to the pivot elements  on the right. */
  void partition(V pivot);
  static void add(LinkedList<int> &l1, LinkedList<int> &l2, LinkedList<int> &result);

  static bool isPalindrome(LinkedList<V> l);
  static bool isPalindrome_v2(LinkedList<V> &l);
};

template<typename V>
LinkedList<V>::LinkedList()
{
  first = last = nullptr;
  size = 0;
}

template<typename V>
LinkedList<V>::~LinkedList()
{
  while (!isEmpty()) {
    removeFirst();
  }
  size = 0;
}

template<typename V>
Node<V>* LinkedList<V>::getFirstPtr() const
{
  return first;
}

template<typename V>
Node<V>* LinkedList<V>::getLastPtr() const
{
  return last;
}

template<typename V>
LinkedList<V>::LinkedList(const LinkedList<V> &other)
{
  first = last = nullptr;
  if (!other.isEmpty()) {
    Node<V> *otherFirst = other.getFirstPtr();
    Node<V> *otherLast = other.getLastPtr();

    while (otherFirst != otherLast) {
      addLast(otherFirst->value);
      otherFirst = otherFirst->next;
    }
    addLast(otherLast->value);
  }

  size = other.size;
}

template<typename V>
LinkedList<V>& LinkedList<V>::operator=(const LinkedList<V> &other)
{
  first = last = nullptr;
  if (!other.isEmpty()) {
    Node<V> *otherFirst = other.getFirstPtr();
    Node<V> *otherLast = other.getLastPtr();

    while (otherFirst != otherLast) {
      addLast(otherFirst->value);
      otherFirst = otherFirst->next;
    }
    addLast(otherLast->value);
  }
  size = other.size;
  return *this;
}

template<typename V>
bool LinkedList<V>::isEmpty() const
{
  return (first == nullptr) && (last == nullptr);
}

template<typename V>
void LinkedList<V>::addFirst(V value)
{
  Node<V> *newNode = new Node<V>(value);

  if (isEmpty()) {
    first = last = newNode;
  } else {
    newNode->next = first;
    first->prev = newNode;
    first = newNode;
  }
  size++;
}

template<typename V>
void LinkedList<V>::addLast(V value)
{
  Node<V> *newNode = new Node<V>(value);

  if (isEmpty()) {
    first = last = newNode;
  } else {
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
  }
  size++;
}

template<typename V>
void LinkedList<V>::print()
{
  if (isEmpty()) return;

  Node<V> *current = first;
  while (current != last) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << current->value;
  std::cout <<"\n";
}

template<typename V>
void LinkedList<V>::removeFirst()
{
  if (isEmpty()) {
    return;
  }

  Node<V> *current = first;
  if (first != last) {
    first->next->prev = nullptr;
    first = first->next;
  } else {
    first = last = nullptr;
  }
  size--;
  delete current;
}

template<typename V>
void LinkedList<V>::removeLast()
{
  if (isEmpty()) {
    return;
  }

  Node<V> *current = last;
  if (first != last) {
    last->prev->next = nullptr;
    last = last->prev;
  } else {
    first = last = nullptr;
  }
  size--;
  delete current;
}

template<typename V>
bool LinkedList<V>::contains(V value)
{
  if (isEmpty()) {
    return false;
  } else {
    Node<V> *current = first;
    while (current != last) {
      if (current->value == value) {
        return true;
      }
      current = current->next;
    }
    if (last->value == value) {
      return true;
    }
    return false;
  }
}

template<typename V>
bool LinkedList<V>::equals(const LinkedList<V> &other)
{
  if (size != other.size) {
    return false;
  }

  Node<V> *current = first, *otherCurrent = other.first;
  while (current != last && otherCurrent != other.last) {
    if (current->value != otherCurrent->value) {
      return false;
    }
    current = current->next;
    otherCurrent = otherCurrent->next;
  }

  if (current != last || otherCurrent != other.last) {
    return false;
  }

  return true;
}

template <typename V>
int LinkedList<V>::getSize()
{
  return size;
}

template<typename V>
void LinkedList<V>::removeDuplicates()
{
  Hashtable<V, bool> nodeMap;
  Node<V> *current = first;

  if (isEmpty() || first == last) {
    return;
  }

  while (current->next != nullptr) {
    if (nodeMap.hasKey(current->value)) {
      Node<V> *tmp = current;
      current->prev->next = current->next;
      current->next->prev = current->prev;
      current = current->next;
      delete tmp;
      size--;
    } else {
      nodeMap.insert(current->value, true);
      current = current->next;
    }

  }
}

template<typename V>
void LinkedList<V>::removeDuplicates_v2()
{
  Node<V> *current, *next;
  current = first;

  if (isEmpty() || first == last) {
    return;
  }

  while (current->next != nullptr) {
    next = current->next;
    while (next->next != nullptr) {
      if (next->value == current->value) {
        Node<V> *tmp = next;
        next->prev->next = next->next;
        next->next->prev = next->prev;
        next = next->next;
        delete tmp;
        size--;
      } else {
        next = next->next;
      }
    }
    current = current->next;
  }
}

/* Returns k th element to last assuming we don't know the size of the list or
  the last pointer. */
template<typename V>
V LinkedList<V>::kthToLast(int k)
{
  Node<V> *current, *kth;
  current = kth = first;

  for (int i = 1; i < k; ++i) {
    if (current == nullptr) {
      std::cout << "K bigger than the list";
      return V();
    }
    current = current->next;
  }

  while (current->next != nullptr) {
    current = current->next;
    kth = kth->next;
  }
  return kth->value;
}


/* Partition by traversing the list and deleting the greater or equal to the
  pivot elements and inserting then at the back. */
template<typename V>
void LinkedList<V>::partition(V pivot)
{
  Node<V> *current = first;
  Node<V> *end = last;

  while (current->value >= pivot && current != end) {
    V value = current->value;
    current = current->next;
    removeFirst();
    addLast(value);
  }

  while (current != end) {
    if (current->value >= pivot) {
      addLast(current->value);
      Node<V> *tmp = current;
      current->prev->next = current->next;
      current->next->prev = current->prev;
      current = current->next;
      delete tmp;
      size--;
    } else {
      current = current->next;
    }
  }
}
/* Adds numbers memorised as linked lists. */
template<typename V>
void LinkedList<V>::add(LinkedList<int> &l1, LinkedList<int> &l2, LinkedList<int> &result)
{
  Node<V> *currentL1 = l1.getFirstPtr();
  Node<V> *currentL2 = l2.getFirstPtr();
  int accumulator = 0;

  while (currentL1 != nullptr && currentL2!= nullptr) {
    result.addLast((currentL1->value + currentL2->value + accumulator) % 10);
    accumulator = (currentL1->value + currentL2->value + accumulator) / 10;
    currentL1 = currentL1->next;
    currentL2 = currentL2->next;
  }

  while (currentL1 != nullptr) {
    result.addLast((currentL1->value + accumulator) % 10);
    accumulator = (currentL1->value + accumulator) / 10;
    currentL1 = currentL1->next;
  }

  while (currentL2 != nullptr) {
    result.addLast((currentL2->value + accumulator) % 10);
    accumulator = (currentL2->value + accumulator) / 10;
    currentL2 = currentL2->next;
  }

  if (accumulator) {
    result.addLast(accumulator);
  }
}

/* Checks if a list is a palindrome by constantly comparing first and last node
  and then deleting them until the list is empty. */
template <typename V>
bool LinkedList<V>::isPalindrome(LinkedList<V> l)
{
  if (l.isEmpty() || l.getFirstPtr() == l.getLastPtr()) {
    return true;
  }

  while (!l.isEmpty()) {
    if (l.getFirstPtr()->value != l.getLastPtr()->value) {
      return false;
    }
    l.removeFirst();
    l.removeLast();
  }
  return true;
}

/* Checks if a list is palindrome by traversing both forward and backward. */
template <typename V>
bool LinkedList<V>::isPalindrome_v2(LinkedList<V> &l)
{
  if (l.isEmpty() || l.getFirstPtr() == l.getLastPtr()) {
    return true;
  }

  Node<V> *forward = l.getFirstPtr();
  Node<V> *backward = l.getLastPtr();
  while (forward != backward) {
    if (forward->value != backward->value) {
      return false;
    }
    forward = forward->next;
    backward = backward->prev;
  }
  return true;
}


#endif