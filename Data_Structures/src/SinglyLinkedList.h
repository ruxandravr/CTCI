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

  /* Chapter 2 functions */
  void deleteNode(SNode<V> *n);

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
  return true;
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
#endif

