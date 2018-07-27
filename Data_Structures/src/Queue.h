#ifndef CTCI_QUEUE_H
#define CTCI_QUEUE_H

#include <iostream>
#include <vector>
#include "Node.h"

template <typename V>
class Queue
{
private:
  Node<V> *frontPtr, *backPtr;
  int size;

public:
  Queue();
  ~Queue();

  Queue(const Queue<V> &other);
  Queue<V>& operator=(const Queue<V> &other);
  void push_back(V value);
  bool pop_front();
  V front();
  bool isEmpty();
  void print();
  bool equals (const Queue<V> &other);
};


template <typename V>
Queue<V>::Queue()
{
  frontPtr = backPtr = nullptr;
  size = 0;
}

template <typename V>
Queue<V>::~Queue()
{
  while (!isEmpty()) {
    pop_front();
  }
  size = 0;
}

/* Copy constuctor */
template <typename V>
Queue<V>::Queue(const Queue<V> &other)
{
  frontPtr = backPtr = nullptr;

  Node<V> *otherCurrent = other.frontPtr;
  while (otherCurrent != nullptr) {
    push_back(otherCurrent->value);
    otherCurrent = otherCurrent->next;
  }
  size = other.size;
}

/* Assignment operator */
template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V> &other)
{
  frontPtr = backPtr = nullptr;

  Node<V> *otherCurrent = other.frontPtr;
  while (otherCurrent != nullptr) {
    push_back(otherCurrent->value);
    otherCurrent = otherCurrent->next;
  }

  size = other.size;
  return *this;
}

/* Add an element in the queue (similar to addLast). */
template <typename V>
void Queue<V>::push_back(V value)
{
  Node<V> *newNode = new Node<V>(value);
  if (isEmpty()) {
    frontPtr = backPtr = newNode;
  } else {
    backPtr->next = newNode;
    newNode->prev = backPtr;
    backPtr = newNode;
  }
  size++;
}

/* Delete an element from the queue (similar to removeFirst). */
template <typename V>
bool Queue<V>::pop_front()
{
  if (isEmpty()) return false;

  Node<V> *current = frontPtr;
  if (frontPtr != backPtr) {
    frontPtr->next->prev = nullptr;
    frontPtr = frontPtr->next;
  } else {
    frontPtr = backPtr = nullptr;
  }
  size--;
  return true;
}

/* Inspect the first element of the queue. */
template <typename V>
V Queue<V>::front()
{
  if (frontPtr == nullptr) return V();
  return frontPtr->value;
}

template <typename V>
bool Queue<V>::isEmpty()
{
  return (frontPtr == nullptr) && (backPtr == nullptr);
}

/* Print the queue from front to back. */
template <typename V>
void Queue<V>::print()
{
  if (!isEmpty()) {
    Node<V> *current = frontPtr;
    while (current != nullptr) {
      std::cout << current->value << " ";
      current = current->next;
    }
    std::cout << "\n";
  }
}

/* Check if 2 queues are the same. */
template <typename V>
bool Queue<V>::equals (const Queue<V> &other)
{
  if (size != other.size) {
    return false;
  }

  Node<V> *otherCurrent = other.frontPtr;
  Node<V> *thisCurrent = frontPtr;
  while (otherCurrent != nullptr) {
    if (otherCurrent->value != thisCurrent->value) {
      return false;
    }
    otherCurrent = otherCurrent->next;
    thisCurrent = thisCurrent->next;
  }
  return true;
}

#endif