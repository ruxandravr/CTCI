#ifndef CTCI_FIXED_MULTI_STACK_H
#define CTCI_FIXED_MULTI_STACK_H

#include <iostream>

template <typename V>
class FixedMultiStack
{
private:
  int stackNumber;
  int defaultSize;
  int *sizes;
  V *values;

public:
  FixedMultiStack(int stackNumber, int defaultSize);
  ~FixedMultiStack();
  void push(int stack, V value);
  V pop(int stack);
  V peek(int stack);
  bool isFull(int stack);
  bool isEmpty(int stack);
  int getLastIndex(int stack);
  void print();

};

template <typename V>
FixedMultiStack<V>::FixedMultiStack(int stackNumber, int defaultSize)
{
  this->stackNumber = stackNumber;
  this->defaultSize = defaultSize;

  sizes = new int[stackNumber];
  for (int i = 0;  i < stackNumber; ++i) {
    sizes[i] = 0;
  }

  values = new V[stackNumber * defaultSize];
  for (int i = 0;  i < stackNumber * defaultSize; ++i) {
    values[i] = 0;
  }
}

template <typename V>
FixedMultiStack<V>::~FixedMultiStack()
{
  delete[] sizes;
  delete[] values;
}

template <typename V>
bool FixedMultiStack<V>::isFull(int stack)
{
  return sizes[stack - 1] == defaultSize;
}

template <typename V>
bool FixedMultiStack<V>::isEmpty(int stack)
{
  return sizes[stack - 1] == 0;
}

template <typename V>
void FixedMultiStack<V>::push(int stack, V value)
{
  if (isFull(stack)) {
    std::cout << "Stack full. Push cannot be done.\nReturning...\n";
    return;
  }

  sizes[stack - 1]++;
  values[getLastIndex(stack)] = value;
}

template <typename V>
V FixedMultiStack<V>::pop(int stack)
{
  if (isEmpty(stack)) {
    std::cout << "Stack empty. Pop cannot be done.\nReturning...\n";
    return V();
  }

  V value = values[getLastIndex(stack)];
  values[getLastIndex(stack)] = 0;
  sizes[stack - 1]--;
  return value;
}

template <typename V>
V FixedMultiStack<V>::peek(int stack)
{
  if (isEmpty(stack)) {
    std::cout << "Stack empty. Peek cannot be done.\nReturning...\n";
    return V();
  }

  return values[getLastIndex(stack)];
}

template <typename V>
int FixedMultiStack<V>::getLastIndex(int stack)
{
  return (stack - 1) * defaultSize + sizes[stack - 1] - 1;
}

template <typename V>
void FixedMultiStack<V>::print()
{
  for (int i = 0; i < stackNumber * defaultSize; ++i) {
    std::cout << values[i] << " ";
  }
  std::cout << "\n";
}


#endif