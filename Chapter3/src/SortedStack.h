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
  static Stack<V> sortStack(Stack<V> s);
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


/* Sort a given stack by poping one element at a time from the stack and introducing
it in a new stack at a correct position. */
template <typename V>
Stack<V> SortedStack<V>::sortStack(Stack<V> s)
{
  Stack<V> newStack;

  if (s.isEmpty()) {
    return s;
  }

  newStack.push(s.top());
  s.pop();

  while (!s.isEmpty()) {
    V tmp = s.top();
    s.pop();

    while (!newStack.isEmpty() && newStack.top() < tmp) {
      s.push(newStack.top());
      newStack.pop();
    }
    newStack.push(tmp);
  }
  return newStack;
}

#endif