#ifndef CTCI_SET_OF_STACKS
#define CTCI_SET_OF_STACKS

#include <vector>
#include "../../Data_Structures/src/LinkedList.h"

/* Implement a stack like a set of stacks with a maximum size. Because we don't
  know the size of each stack, we use a vector of sizes. */
template <typename V>
class SetOfStacks
{
private:
  std::vector<StackWithBottom<V> > stacks;
  std::vector<int> sizes;
  int maximumSize;

public:
  SetOfStacks(int maximumSize);
  void push(V value);
  bool pop();
  V top();
  bool isEmpty();
  void print();
  bool popAtIndex(int index);
};


template <typename V>
SetOfStacks<V>::SetOfStacks(int maximumSize)
{
  this->maximumSize = maximumSize;
}

template <typename V>
void SetOfStacks<V>::push(V value)
{
  /* Create a new stack and push it to the vector. */
  if (stacks.empty() || sizes[sizes.size() - 1] >= maximumSize) {
    StackWithBottom<V> newStack;
    newStack.push(value);
    stacks.push_back(newStack);
    sizes.push_back(1);
  } else if (sizes[sizes.size() - 1] < maximumSize) {
    /* Add the element to the last existing stack. */
    sizes[sizes.size() - 1]++;
    stacks[stacks.size() - 1].push(value);
  }
}

template <typename V>
bool SetOfStacks<V>::pop()
{
  if (stacks.empty()) return false;
  bool result;
  /* Pop element and decrease size. */
  sizes[sizes.size() - 1]--;
  result = stacks[stacks.size() - 1].pop();

  /* Pop element from vectors if stack remains empty. */
  if (sizes[sizes.size() - 1] == 0) {
    sizes.pop_back();
    stacks.pop_back();
  }
  return result;
}


template <typename V>
V SetOfStacks<V>::top()
{
  return stacks[stacks.size() - 1].top();
}

template <typename V>
bool SetOfStacks<V>::isEmpty()
{
  return stacks.empty();
}

/* Pop an element from a stack and then shift all the stacks to left. */
template <typename V>
bool SetOfStacks<V>::popAtIndex(int index)
{
  if (index > sizes.size()) return false;

  if (index == sizes.size()) {
    return pop();
  }

  /* Assume the indexes given as parameters start with 1. */
  index--;

  /* Pop actual stack. */
  stacks[index].pop();

  /* Start shifting by deleting bottom element from next stack and pushing it
    to current stack. */
  for (int i = index; i < sizes.size() - 1; ++i) {
    if (stacks[i].isEmpty()) return false;
    V nextValue = stacks[i + 1].bottom();
    stacks[i].push(nextValue);
    stacks[i + 1].pop_bottom();
  }

  /* Decrease the size of last stack. */
  sizes[sizes.size() - 1]--;

  /* Pop last element from vectors if last stack remains empty. */
  if (stacks[sizes.size() - 1].isEmpty()) {
    stacks.pop_back();
    sizes.pop_back();
  }

  return true;
}

/* Print each stack. [useful for debug] */
template <typename V>
void SetOfStacks<V>::print()
{
  for (int i = 0; i < stacks.size(); ++i) {
    std::cout << "Stack: " << i << ": ";
    stacks[i].print();
  }
}

/* Implementation of a stack as a LinkedList because we keep track of the bottom
    element as well. */
template<typename V>
class StackWithBottom : public LinkedList<V>
{
public:
  void push(V value);
  bool pop();
  bool pop_bottom();
  V top();
  V bottom();
};

template <typename V>
void StackWithBottom<V>::push(V value)
{
  LinkedList<V>::addFirst(value);
}

template <typename V>
bool StackWithBottom<V>::pop()
{
  bool result = LinkedList<V>::isEmpty();
  LinkedList<V>::removeFirst();
  return !result;
}
template <typename V>
bool StackWithBottom<V>::pop_bottom()
{
  bool result = LinkedList<V>::isEmpty();
  LinkedList<V>::removeLast();
  return !result;
}

template <typename V>
V StackWithBottom<V>::top()
{
  V result = LinkedList<V>::getFirstPtr()->value;
  return result;
}

template <typename V>
V StackWithBottom<V>::bottom()
{
  V result = LinkedList<V>::getLastPtr()->value;
  return result;
}


#endif
