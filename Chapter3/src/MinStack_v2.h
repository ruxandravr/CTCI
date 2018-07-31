#ifndef CTCI_MIN_STACK
#define CTCI_MIN_STACK

#include "../../Data_Structures/src/Stack.h"

template <typename V>
class MinStack_v2 : public Stack<V>
{
private:
  Stack<V> minStack;  // a stack that will keep track of minimum elemnts
public:
  void push(V value);
  bool pop();
  V getMin();
};

template <typename V>
void MinStack_v2<V>::push(V value)
{
  /* Update the minimum element by pusing it into the stack. */
  if (minStack.isEmpty()) {
    minStack.push(value);
  } else {
    if (value <= minStack.top()) {
      minStack.push(value);
    }
  }
  Stack<V>::push(value);
}

template <typename V>
bool MinStack_v2<V>::pop()
{
  /* Pop the elemnt from the minimum stack if it no longer exists in actual stack.*/
  if (minStack.top() == Stack<V>::top()) {
    minStack.pop();
  }
  return Stack<V>::pop();
}

template <typename V>
V MinStack_v2<V>::getMin()
{
  return minStack.top(); // Return the minimum
}

#endif