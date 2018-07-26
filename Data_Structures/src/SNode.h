#ifndef CTCI_S_NODE_H
#define CTCI_S_NODE_H

#include <iostream>

template <typename V>
class SNode
{
public:
  V value;
  SNode<V> *next;

  SNode() =  delete;
  ~SNode() = default;
  SNode(V value);
  SNode<V>(const SNode<V> &other);
  SNode<V>& operator=(const SNode<V> &other);
  bool equals(const SNode<V> &node);

  /* Functions for a singly linked list saved as it's head node */
  static void print(SNode<V> *head);

  /* Chapter 2 functions */
  static SNode<V>* intersect(SNode<V> *head1, SNode<V> *head2);
  static SNode<V>* loop(SNode<V> *head);


};

template<typename V>
SNode<V>::SNode(V value)
{
  this->value = value;
  this->next = nullptr;
}

template<typename V>
SNode<V>::SNode(const SNode<V> &other)
{
  this->value = other.value;
  this->next = other.next;
}

template<typename V>
SNode<V>& SNode<V>::operator=(const SNode<V> &other)
{
  this->value = other.value;
  this->next = other.next;

  return *this;
}

template<typename V>
bool SNode<V>::equals(const SNode<V> &node)
{
  return value == node.value;
}

/* Print a singly linked list identified by its head. */
template<typename V>
void SNode<V>::print(SNode<V> *head)
{
  if (head == nullptr) return;

  while (head != nullptr) {
    std::cout << head->value << " ";
    head = head->next;
  }
  std::cout << "\n";
}

/* Determine if two lists identified by head pointer intersect by traversing
  the lists and checking if they have the same ending node. Intersection node
  is found after we start traversing each list from the same length to end. */
template<typename V>
SNode<V>* SNode<V>::intersect(SNode<V> *head1, SNode<V> *head2)
{
  if (head1 == nullptr || head2 == nullptr) return nullptr;

  SNode<V> *current1 = head1;
  SNode<V> *current2 = head2;
  int size1 = 1;
  int size2 = 1;

  /* Reach the ending node and calculate lists' size. */
  while (current1->next != nullptr) {
    current1 = current1->next;
    size1++;
  }

  while (current2->next != nullptr) {
    current2 = current2->next;
    size2++;
  }

  /* Ending node should be the same. */
  if (current1 != current2) return nullptr;

  current1 = head1;
  current2 = head2;

  /* Trim the shortest list. */
  if (size1 < size2) {
    for (int i = 0; i < size2 - size1; ++i) {
      current2 = current2->next;
    }
  }

  if (size2 < size1) {
    for (int i = 0; i< size1 - size2; ++i) {
      current1 = current1->next;
    }
  }

  /* Traverse lists until finding intersection. */
  while (current1 != current2) {
    current1 = current1->next;
    current2 = current2->next;
  }

  return current1;

}


/* Determine if a singly linked list identified by its head has a loop. Traverse
  the list with two pointers: fast and slow (fast takes 2x steps more than the
  slow pointer). If the pointers collide, than the list has a loop. To determine
  the head of the loop move both pointers with the same speed from the collision
  node. */
template<typename V>
SNode<V>* SNode<V>::loop(SNode<V> *head)
{
  if (head == nullptr) return nullptr;

  SNode<V> *fast = head;
  SNode<V> *slow = head;

  /* Verify if the end is reached. */
  while (fast != nullptr && slow != nullptr) {
    if (fast == slow && slow != head) { // determine collision point
      break;
    }
    if (fast->next == nullptr || slow->next == nullptr) {
      return nullptr;
    }
    fast = fast->next->next;
    slow = slow->next;
  }

  if (fast == nullptr || slow == nullptr) {
    return nullptr;
  }

  /* Determine head of the loop. */
  slow = head;

  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return fast;
}


#endif