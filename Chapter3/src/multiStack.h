#ifndef CTCI_MULTI_STACK_H
#define CTCI_MULTI_STACK_H

#include <iostream>
#include "StackInfo.h"

//  defaultSize
//  <--------->
//  |---------+---------+---------|       |-----+------+-------------+-----|
//  |   S1    |   S2    |   S3    |   ->  |  S1 |  S2  |     S3      | S1  |
//  |         |         |         |       |     |      |             |     |
//  |---------+---------+---------|       |-----+------+-------------+-----|
//            ^                                 ^                    ^
//            2nd stack start                  1st stack end       1st stack start
//

/* Implements multiple stacks into an circular array. */
template <typename V>
class MultiStack
{
private:
  V *values;
  StackInfo *stacks;
  int stacksNumber;
  int defaultSize;
  int length;

public:
  MultiStack(int stacksNumber, int defaultSize);
  ~MultiStack();
  void push(int stackNumber, V value);
  V pop(int stackNumber);
  V peek(int stackNumber);
  bool isFull();
  int adjustIndex(int index);
  void expand(int stack);
  void shift(int stack);
  void print();

};

template <typename V>
MultiStack<V>::MultiStack(int stacksNumber, int defaultSize)
{
  this->stacksNumber = stacksNumber;
  this->defaultSize = defaultSize;

  length = stacksNumber * defaultSize;
  values = new V[length];
  stacks = new StackInfo[stacksNumber];

  for (int i = 0; i < length; ++i) {
    values[i] = 0;
  }

  /* Marks each stack with a start and a capacity. */
  for (int i = 0; i < stacksNumber; ++i) {
    stacks[i].setStack(i * defaultSize, defaultSize);
  }
}

template <typename V>
MultiStack<V>::~MultiStack()
{
  delete[] values;
  delete[] stacks;
}

/* Push an element in the stackNumber stack. */
template <typename V>
void MultiStack<V>::push(int stackNumber, V value)
{
  if (isFull())  {
    std::cout << "Stack is full. Push cannot be done.\nReturning...";
    return;
  }

  /* If current stack is full expand it. */
  if (stacks[stackNumber - 1].isFull()) {
    expand(stackNumber - 1);
  }

  /* Adjust stack's size and update values array. */
  stacks[stackNumber - 1].size++;
  values[adjustIndex(stacks[stackNumber - 1].lastAvailableIndex())] = value;

}

/* Pop and return an element from stackNumber stack. */
template <typename V>
V MultiStack<V>::pop(int stackNumber)
{
  if (stacks[stackNumber - 1].isEmpty()) {
    std::cout << "Stack is empyy. Pop cannot be done.\nReturning...";
    return V();
  }

  /* Replace the old value with 0, update stack's size and return the old value. */
  V value = values[adjustIndex(stacks[stackNumber - 1].lastAvailableIndex())];
  values[adjustIndex(stacks[stackNumber - 1].lastAvailableIndex())] = 0;
  stacks[stackNumber - 1].size--;

  return value;
}

/* Return the element on top of the stackNumber stack. */
template <typename V>
V MultiStack<V>::peek(int stackNumber)
{
  return values[adjustIndex(stacks[stackNumber - 1].lastAvailableIndex())];
}

/* Returns true if there is no free place in the array. */
template <typename V>
bool MultiStack<V>::isFull()
{
  int totalSize = 0;
  for (int i = 0; i < stacksNumber; ++i) {
    totalSize += stacks[i].size;
  }

  return totalSize == (length);
}

/* Adjust the element index to fit into the array -> for a circular stack. */
template <typename V>
int MultiStack<V>::adjustIndex(int index)
{
  /* If it is a negative value move the index to the end. */
  if (index < 0) {
    return (index % (length) + (length)) % (length);

  }
  /* Move the index to the begining. */
  return index % (length);
}

/* Make room for another element in a stack by shifting the stack next to it.*/
template <typename V>
void MultiStack<V>::expand(int stack)
{
  shift((stack + 1) % stacksNumber) ;
  stacks[stack].capacity++;
}

/* Shift the elements of a stack with one element to the right. */
template <typename V>
void MultiStack<V>::shift(int stack)
{
  /* If there isn't enough place to shift elements within this stack, expand it. */
  if (stacks[stack].isFull()) {
    expand(stack);
  }

  /* Move from the last possible element to first element. */
  int lastIndex = adjustIndex(stacks[stack].start + stacks[stack].capacity - 1);

  while (stacks[stack].isInStack(lastIndex, length)) {
    values[lastIndex] = values[adjustIndex(lastIndex - 1)];
    lastIndex = adjustIndex(lastIndex - 1);
  }

  /* Update the start and the capacity. */
  stacks[stack].start = adjustIndex(stacks[stack].start + 1);
  stacks[stack].capacity--;

}

/* Print a stack. */
template <typename V>
void MultiStack<V>::print()
{
  for (int i = 0; i < length; ++i) {
    std::cout << values[i] << " ";
  }
  std::cout << "\n";
}
#endif