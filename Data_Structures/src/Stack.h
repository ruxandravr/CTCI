#ifndef CTCI_STACK_H
#define CTCI_STACK_H

#include <iostream>
#include <vector>
#include "Node.h"

template <typename V>
class Stack
{
private:
  Node<V> *topPtr;
  int size;

public:
  Stack();
  ~Stack();

  Stack(const Stack<V> &other);
  Stack<V>& operator=(const Stack<V> &other);
  void push(V value);
  bool pop();
  V top();
  bool isEmpty();
  void print();
  bool equals (const Stack<V> &other);
};

template <typename V>
Stack<V>::Stack()
{
  topPtr = nullptr;
  size = 0;
}

template <typename V>
Stack<V>::~Stack()
{
  while (!isEmpty()) {
    pop();
  }
  size = 0;
}

/* Copy constructor. */
template <typename V>
Stack<V>::Stack(const Stack<V> &other)
{
  topPtr = nullptr;

  std::vector<V> values;
  Node<V> *otherCurrent = other.topPtr;
  while (otherCurrent != nullptr) {
    values.push_back(otherCurrent->value);
    otherCurrent = otherCurrent->next;
  }

  for (int i = values.size() - 1; i >= 0; --i) {
    push(values[i]);
  }
  size = other.size;
}

/* Asignment operator. */
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V> &other)
{
  topPtr = nullptr;

  std::vector<V> values;
  Node<V> *otherCurrent = other.topPtr;
  while (otherCurrent != nullptr) {
    values.push_back(otherCurrent->value);
    otherCurrent = otherCurrent->next;
  }

  for (int i = values.size() - 1; i >= 0; --i) {
    push(values[i]);
  }
  size = other.size;
  return *this;
}

/* Insert an element in the stack (similar to addFirst). */
template <typename V>
void Stack<V>::push(V value)
{
  Node<V> *newNode = new Node<V>(value);
  if (isEmpty()) {
    topPtr = newNode;
  } else {
    topPtr->prev = newNode;
    newNode->next = topPtr;
    topPtr = newNode;
  }
  size++;
}

/* Delete an element from the stack (similar to removeFirst). */
template <typename V>
bool Stack<V>::pop()
{
  if (isEmpty()) return false;

  Node<V> *current = topPtr;
  if (topPtr->next != nullptr) {
    topPtr->next->prev = nullptr;
    topPtr = topPtr->next;
  } else {
    topPtr = nullptr;
  }
  size--;
  return true;
}

/* Inspect the top element of the stack. */
template <typename V>
V Stack<V>::top()
{
  if (topPtr == nullptr) return V();
  return topPtr->value;
}

template <typename V>
bool Stack<V>::isEmpty()
{
  return (topPtr == nullptr);
}

/* Print the stack from top to bottom. */
template <typename V>
void Stack<V>::print()
{
  if (!isEmpty()) {
    Node<V> *current = topPtr;
    while (current != nullptr) {
      std::cout << current->value << " ";
      current = current->next;
    }
    std::cout << "\n";
  }
}

/* Check if two stacks are equal. */
template <typename V>
bool Stack<V>::equals (const Stack<V> &other)
{
  if (size != other.size) {
    return false;
  }

  Node<V> *otherCurrent = other.topPtr;
  Node<V> *thisCurrent = topPtr;
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