#ifndef CTCI_SET_OF_STACKS
#define CTCI_SET_OF_STACKS

#include <vector>
#include "../../Data_Structures/src/Stack.h"

/* Implement a stack like a set of stacks with a maximum size. Because we don't
  know the size of each stack, we use a vector of sizes. */
template <typename V>
class SetOfStacks
{
private:
  std::vector<Stack<V> > stacks;
  std::vector<int> sizes;
  int maximumSize;

public:
  SetOfStacks(int maximumSize);
  void push(V value);
  bool pop();
  V top();
  bool isEmpty();
  void print();
};

/* Constructorspecifies the maximum size of a stack. */
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
    Stack<V> newStack;
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

  /* Pop element from vectors if stack reamains empty. */
  if (sizes[sizes.size() - 1] == 0) {
    sizes.pop_back();
    stacks.pop_back();
  }
  return result;
}

/* Top() on the last stack. */
template <typename V>
V SetOfStacks<V>::top()
{
  return stacks[stacks.size() - 1].top();
}

/* No stacks in the vector. */
template <typename V>
bool SetOfStacks<V>::isEmpty()
{
  return stacks.empty();
}

/* Print each stack. */
template <typename V>
void SetOfStacks<V>::print()
{
  for (int i = 0; i < stacks.size(); ++i) {
    std::cout << "Stack: " << i << ": ";
    stacks[i].print();
  }
}

#endif
