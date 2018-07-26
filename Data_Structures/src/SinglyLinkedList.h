#ifndef CTCI_SINGLY_LINKED_LIST_H
#define CTCI_SINGLY_LINKED_LIST_H

#include "SNode.h"
#include <iostream>

template <typename V>
class SinglyLinkedList
{
private:
  SNode<V> *first, *last;
  int size;

public:
  SinglyLinkedList();
  ~SinglyLinkedList();

  SinglyLinkedList(const SinglyLinkedList<V> &other);
  SinglyLinkedList& operator=(const SinglyLinkedList<V> &other);
  void addFirst(V value);
  void addLast(V value);
  void removeFirst();
  void removeLast();
  bool isEmpty() const;
  SNode<V> *getFirstPtr() const;
  SNode<V> *getLastPtr() const;
  int getSize() const;
  bool equals(const SinglyLinkedList<V> &other);
  void print();
  SNode<V>* getNthNode(int n);
  SinglyLinkedList<V> reverse();

  /* Chapter 2 functions */
  void deleteNode(SNode<V> *n);
  bool isPalindrome();
  static bool intersect(SinglyLinkedList<V> l1, SinglyLinkedList<V> l2,
                        SNode<V> &intersection);

};

template<typename V>
SinglyLinkedList<V>::SinglyLinkedList()
{
  first = last = nullptr;
  size = 0;
}

template<typename V>
SinglyLinkedList<V>::~SinglyLinkedList()
{
  while(!isEmpty()) {
    removeFirst();
  }
  size = 0;
}

template<typename V>
bool SinglyLinkedList<V>::isEmpty() const
{
  return (first == nullptr) && (last == nullptr);
}

template<typename V>
SinglyLinkedList<V>::SinglyLinkedList(const SinglyLinkedList<V> &other)
{
  first = last = nullptr;
  if (!other.isEmpty()) {
    SNode<V> *otherfirst = other.getFirstPtr();

    while (otherfirst->next != nullptr) {
      addLast(otherfirst->value);
      otherfirst = otherfirst->next;
    }
    addLast(other.getLastPtr()->value);
  }
  size = other.size;
}

template<typename V>
SinglyLinkedList<V>& SinglyLinkedList<V>::operator=(const SinglyLinkedList<V> &other)
{
  first = last = nullptr;
  if (!other.isEmpty()) {
    SNode<V> *otherfirst = other.getFirstPtr();
    while (otherfirst->next != nullptr) {
      addLast(otherfirst->value);
      otherfirst = otherfirst->next;
    }
    addLast(other.getLastPtr()->value);
  }
  size = other.size;
  return *this;
}

template<typename V>
bool SinglyLinkedList<V>::equals(const SinglyLinkedList<V> &other)
{
  if (size != other.size) {
    return false;
  }
  SNode<V> *current = first;
  SNode<V> *otherfirst = other.getFirstPtr();
  if (!other.isEmpty()) {
    while (otherfirst->next != nullptr  && current->next != nullptr) {
      if (otherfirst->value != current->value) {
        return false;
      }
      otherfirst = otherfirst->next;
      current = current->next;
    }
  }
  return other.getLastPtr()->value == last->value;
}

template<typename V>
SNode<V>* SinglyLinkedList<V>::getFirstPtr() const
{
  return first;
}

template<typename V>
SNode<V>* SinglyLinkedList<V>::getLastPtr() const
{
  return last;
}

template<typename V>
int SinglyLinkedList<V>::getSize() const
{
  return size;
}

template<typename V>
void SinglyLinkedList<V>::addFirst(V value)
{
  SNode<V> *newNode = new SNode<V>(value);

  if (isEmpty()) {
    first = last = newNode;
  } else {
    newNode->next = first;
    first = newNode;
  }
  size++;
}

template<typename V>
void SinglyLinkedList<V>::addLast(V value)
{
  SNode<V> *newNode = new SNode<V>(value);

  if (isEmpty()) {
    first = last = newNode;
  } else {
    last->next = newNode;
    last = newNode;
  }
  size++;
}

template<typename V>
void SinglyLinkedList<V>:: removeLast()
{
  if (isEmpty()) {
    return;
  }

  SNode<V> *current= last;

  // there is only one node in our list
  if (first == last) {
    first = last = nullptr;
    delete current;
  } else {
    current = first;
    // more than one node
    while (current->next != last) {
      current = current->next;
    }
    delete current->next;
    last = current;
    current->next = nullptr;
  }
  size--;
}

template<typename V>
void SinglyLinkedList<V>::removeFirst()
{
  if (isEmpty()) {
    return;
  }

  SNode<V> *current = first;
  // only one node
  if (first->next == nullptr) {
    first = last = nullptr;
  } else {
    first = first->next;
  }
  delete current;
  size--;
}

template<typename V>
void SinglyLinkedList<V>:: print()
{
  if (isEmpty()) {
    return;
  }
  SNode<V> *current = first;
  while (current != last) {
    std::cout << current->value << " ";
    current = current->next;
  }
  if(last != nullptr) {
    std::cout << last->value;
  }

}

/* Returns the n-th node from the list. */
template<typename V>
SNode<V>* SinglyLinkedList<V>:: getNthNode(int n)
{
  if (n > size) {
    return nullptr;
  }
  SNode<V> *current = first;
  int index = 1;
  while (index < n) {
    current = current->next;
    index++;
  }
  return current;
}

/* Delete a node only by having a pointer to that node: copy the value from the
  next node and then delete the next node. Special cases for last and second to
  last nodes. */
template<typename V>
void SinglyLinkedList<V>::deleteNode(SNode<V> *n)
{
  if (n == nullptr || n-> next == nullptr) {
    return;
  }
  SNode<V> *next = n->next;
  n->value = next->value;
  n->next = next->next;

  /* More checks*/
  if (next == last) {
    last = n;
  }
  delete next;
  size--;
}

/* Reverse the list by creating a new one. */
template <typename V>
SinglyLinkedList<V> SinglyLinkedList<V>::reverse()
{
  SinglyLinkedList<V> l;
  if (isEmpty()) {
    return l;
  }

  if (first == last) {
    l.addFirst(first->value);
  } else {
    SNode<V> *current = first;
    while (current != last) {
      l.addFirst(current->value);
      current = current->next;
    }
    l.addFirst(last->value);
  }
  return l;
}

/* Tests is a list is a palindrome by checking if it is equal to its reverse. */
template <typename V>
bool SinglyLinkedList<V>::isPalindrome()
{
  SinglyLinkedList<V> reversed = this->reverse();
  return reversed.equals(*this);
}

/* Determine if 2 lists intersect (have an element whose reference is the same)*/
template <typename V>
bool SinglyLinkedList<V>::intersect(SinglyLinkedList<V> l1, SinglyLinkedList<V> l2,
                                    SNode<V> &intersection)
{
  if (l1.isEmpty() || l2.isEmpty()) return false;

  /* Intersecting lists should point to the same end node. */
  if (l1.getLastPtr() != l2.getLastPtr()) return false;

  SNode<V> *currentL1 = l1.getFirstPtr();
  SNode<V> *currentL2 = l2.getFirstPtr();

  if (l1.getSize() < l2.getSize()) {
    for (int i = 0; i < l2.getSize() - l1.getSize(); ++i) {
      currentL1 = currentL1->next;
    }
  }

  if (l2.getSize() < l1.getSize()) {
    for (int i = 0; i < l1.getSize() - l2.getSize(); ++i) {
      currentL2 = currentL2->next;
    }
  }

  while (currentL1 != nullptr || currentL2 != nullptr) {
    if (currentL1 == currentL2) {
      // intersection = currentL1;
      return true;
    }
    currentL1 = currentL1->next;
    currentL2 = currentL2->next;
  }

  return true;
}

#endif

