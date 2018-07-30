#ifndef CTCI_STACK_INFO_H
#define CTCI_STACK_INFO_H

/* Class which stores information about each stack. */
class StackInfo
{
public:
  int start, size, capacity;

  StackInfo();
  void setStack(int start, int capacity);
  bool isEmpty();
  bool isFull();

  /* Verifies if an element at given index is in the stack. */
  bool isInStack(int index, int totalLength);

  /* Return the index of the last inserted element. */
  int lastAvailableIndex();

};

StackInfo::StackInfo()
{
  this->start = 0;
  this->capacity = 0;
  this->size = 0;
}

void StackInfo::setStack(int start, int capacity)
{
  this->start = start;
  this->capacity = capacity;
  this->size = 0;
}

bool StackInfo::isEmpty()
{
  return (size == 0);
}

bool StackInfo::isFull()
{
  return (size == capacity);
}

/* Verifies if an element at given index is in the stack. */
bool StackInfo::isInStack(int index, int totalLength)
{
  if (index < 0 || index > totalLength) {
    return false;
  }

  /* Circular stack. */
  if (index < start) {
    return (start <= index + totalLength) &&
           (index + totalLength < start + capacity);
  }

  return start <= index && index < start + capacity;
}

/* Return the index of the last inserted element. */
int StackInfo::lastAvailableIndex()
{
  return start + size - 1;
}

#endif