#ifndef CTCI_SORTED_STACK_H
#define CTCI_SORTED_STACK_H

#include "../../Data_Structures/src/Stack.h"

template <typename V>
class SortedStack
{
private:
  Stack<V> sorted;
  Stack<V> temporary;

public:
  void push(V value);
  bool pop();
  V top();
  bool isEmpty();
  void print();
  void sortStack(Stack<V> &s);
};

template <typename V>
void SortedStack<V>::push(V value)
{
  if (sorted.isEmpty() || value < sorted.top()) {
    sorted.push(value);
  } else {
    while(!sorted.isEmpty() && sorted.top() < value) {
      temporary.push(sorted.top());
      sorted.pop();
    }
    sorted.push(value);
    while (!temporary.isEmpty()) {
      sorted.push(temporary.top());
      temporary.pop();
    }
  }
}

template <typename V>
bool SortedStack<V>::pop()
{
  return sorted.pop();
}

template <typename V>
V SortedStack<V>::top()
{
  return sorted.top();
}

template <typename V>
bool SortedStack<V>::isEmpty()
{
  return sorted.isEmpty();
}

template <typename V>
void SortedStack<V>::print()
{
  sorted.print();
}

template <typename V>
void SortedStack<V>::sortStack(Stack<V> &s)
{
  Stack<V> temporary;
}

#endif