#ifndef CTCI_VECTOR_H
#define CTCI_VECTOR_H

#include <iostream>

template <typename V>
class Vector
{
private:
  V *array;
  int capacity;
  int size;

public:
  Vector();
  ~Vector();

  V& operator[](int pos) const;
  Vector<V> operator+(const Vector<V> &other);
  Vector(int capacity);
  Vector(int capacity, const V &initial);
  Vector(const Vector<V> &other);
  Vector<V>& operator=(const Vector<V> &other);
  bool empty();
  int getSize() const;
  int getCapacity() const;
  void pushBack(const V value);
  void removeFirst();
  void removeLast();
  void removeFirstOccurence(V value);
  void removeLastOccurence(V value);
  void print() const;
  void printAll() const;
  void resize(int capacity);
  bool equals(const Vector<V> &other);
};

/* Overloading [] operator */
template<typename V>
V& Vector<V>:: operator[](int pos) const
{
  return array[pos];
}

/* Overloading + operator */
template<typename V>
Vector<V> Vector<V>::operator+(const Vector<V> &other1)
{
  int size1 = other1.getSize();
  int capacity1 = other1.getCapacity();

  Vector<V> newArray(capacity + capacity1);
  newArray.size = size + size1;
  newArray.capacity = capacity + capacity1;

  for (int i = 0; i < size; ++i) {
    newArray[i] = array[i];
  }
  for (int i = size; i < size + size1; ++i) {
    newArray[i] = other1[i - size];
  }
  return newArray;
}

template<typename V>
Vector<V>::Vector()
{
  this->capacity = this->size = 0;
}

/* First constructor */
template<typename V>
Vector<V>::Vector(int capacity)
{
  this->capacity = capacity;
  this-> size = 0;
  this-> array =  new V[capacity];
}

/* Second constructor */
template<typename V>
Vector<V>::Vector(int capacity, const V &initial)
{
  this->capacity = capacity;
  this-> size = 0;
  this-> array =  new V[capacity];

  for (int i = 0; i < capacity; ++i) {
    array[i] = initial;
  }
}

/* Copy constructor */
template<typename V>
Vector<V>::Vector(const Vector<V> &other)
{
  array = new V[other.getCapacity()];
  size = other.getSize();
  capacity = other.getCapacity();

  for (int i = 0; i < other.getSize(); ++i) {
    array[i] = other[i];
  }
}

/* Destructor */
template<typename V>
Vector<V>::~Vector()
{
  delete[] array;
}

/* Copy assignment */
template<typename V>
Vector<V>& Vector<V>::operator=(const Vector<V>& other)
{
  delete[] array;
  array = new V[other.getCapacity()];
  size = other.getSize();
  capacity = other.getCapacity();

  for (int i = 0; i < other.getSize(); ++i) {
    array[i] = other[i];
  }

  return *this;
}

/* Insert element at the end of the vector */
template<typename V>
void Vector<V>::pushBack(const V value)
{
  if (size < capacity) {
    array[size++] = value;
  } else {
    V *copy = new V[size];
    for (int i = 0; i < size; ++i) {
      copy[i] = array[i];
    }
    capacity = capacity << 1;
    array = new V[capacity];
    for (int i = 0; i < size; ++i) {
      array[i] = copy[i];
    }
    array[size++] = value;

    delete[] copy;
  }
}

/* Remove first element */
template<typename V>
void Vector<V>::removeFirst()
{
  if (!empty()) {
    for (int i = 0; i < size - 1; ++i) {
      array[i] = array[i + 1];
    }
    size--;
  }
}

/* Remove last element */
template<typename V>
void Vector<V>::removeLast()
{
  if (!empty()) {
    size--;
  }
}

/* Remove first occurence of given element */
template<typename V>
void Vector<V>::removeFirstOccurence(V value)
{
  if (empty()) {
    return;
  }
  for (int i = 0; i < size; ++i) {
    if (array[i] ==  value) {
      for (int j = i; j < size - 1; ++j) {
        array[j] = array[j + 1];
      }
      size--;
      break;
    }
  }
}

/* Remove last occurence of given element */
template<typename V>
void Vector<V>::removeLastOccurence(V value)
{
  if (empty()) {
    return;
  }
  for (int i = size - 1; i >= 0; --i) {
    if (array[i] ==  value) {
      for (int j = i; j < size - 1; ++j) {
        array[j] = array[j + 1];
      }
      size--;
      break;
    }
  }
}

/* Print all inserted elements */
template<typename V>
void Vector<V>::print() const
{
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";

}

/* Print all elements - all capacity */
template<typename V>
void Vector<V>::printAll() const
{
  for (int i = 0; i < capacity; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";

}
template<typename V>
bool Vector<V>::empty()
{
  if (size == 0) {
    return true;
  }
  return false;
}
template<typename V>
int Vector<V>::getSize() const
{
  return size;
}

template<typename V>
int Vector<V>::getCapacity() const
{
  return capacity;
}

template<typename V>
void Vector<V>::resize(int capacity)
{
  this->capacity = capacity;
  this-> size = 0;
  this-> array =  new V[capacity];
}

template<typename V>
bool Vector<V>::equals(const Vector<V> &other)
{
  if (size != other.size) {
    return false;
  }

  if (capacity != other.capacity) {
    return false;
  }

  for (int i = 0; i < size; ++i) {
    if (array[i] != other.array[i]) {
      return false;
    }
  }

  return true;
}


#endif