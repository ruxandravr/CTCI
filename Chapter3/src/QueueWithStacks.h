#ifndef CTCI_QUEUE_WITH_STACKS
#define CTCI_QUEUE_WITH_STACKS

#include "../../Data_Structures/src/Stack.h"

template <typename V>
class QueueWithStacks
{
private:
  Stack<V> pushStack;
  Stack<V> popStack;

public:
  void push_back(V value);
  bool pop_front();
  V front();
  bool isEmpty();
  void transfer();
};

template <typename V>
void QueueWithStacks<V>::push_back(V value)
{
  pushStack.push(value);
}

template <typename V>
bool QueueWithStacks<V>::pop_front()
{
  transfer();
  return popStack.pop();
}

template <typename V>
V QueueWithStacks<V>::front()
{
  transfer();
  return popStack.top();
}

/* Transfer from the stack where we push elements to the stack from where we pop
  elements so we'll get the elments in reverse order. */
template <typename V>
void QueueWithStacks<V>::transfer()
{
  if (popStack.isEmpty()) {
    while (!pushStack.isEmpty()) {
      V value = pushStack.top();
      pushStack.pop();
      popStack.push(value);
    }
  }
}

template <typename V>
bool QueueWithStacks<V>::isEmpty()
{
  return pushStack.isEmpty() && popStack.isEmpty();
}

#endif