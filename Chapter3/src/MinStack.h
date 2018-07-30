#ifndef CTCI_MIN_STACK
#define CTCI_MIN_STACK

#include "../../Data_Structures/src/Stack.h"

template <typename V>
class MinNode
{
public:
  V value;
  V min;

  MinNode(V value, V min)
  {
    this->value = value;
    this->min = min;
  }

  MinNode()
  {
    this->value = V();
    this->min = V();
  }
};

template <typename V>
class MinStack : public Stack<MinNode <V> >
{
public:
  void push(V value);
  V top();
  bool pop();
  V getMin();
};

template <typename V>
void MinStack<V>::push(V value)
{
  MinNode<V> min;
  if (Stack<MinNode<V> >::isEmpty()) {
    min = MinNode<V>(value, value);
  } else {
    MinNode<V> lastMin = Stack<MinNode<V> >::top();
    V newMin = (value < lastMin.min) ? value : lastMin.min;
    min = MinNode<V>(value, newMin);
  }

  Stack<MinNode<V> >::push(min);
}

template <typename V>
V MinStack<V>::top()
{
  MinNode<V> value = Stack<MinNode<V> >::top();
  return value.value;
}

template <typename V>
bool MinStack<V>::pop()
{
  return Stack<MinNode<V> >::pop();
}

template <typename V>
V MinStack<V>::getMin()
{
  MinNode<V> value = Stack<MinNode<V> >::top();
  return value.min;
}

// template <typename V>
// bool MinStack<V>::isEmpty() {
//     return Stack<MinNode<V> >::isEmpty();
// }

#endif