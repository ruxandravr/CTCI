#ifndef CTCI_LINKED_LISTS_H
#define CTCI_LINKED_LISTS_H

#include <list>
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <unordered_map>


template <typename V>
class LinkedLists
{
public:
  static void removeDuplicates(std::list<V> &l);
  static void removeDuplicates_v2(std::list<V> &l);
  /* Note: another two options of this functionality can be found in the file
  Data_Strutures/LinkedList.h */

  static V kthToLast(std::list<V> &l, int k);
  /* Note: another two options of this functionality can be found in the file
  Data_Strutures/LinkedList.h */

  /* Remove a node by reference is found in Data_Strutures/SinglyLinkedList.h */

  static void partition(std::list<V> &l, V pivot);
  /* Note: another option of this functionality can be found in the file
  Data_Strutures/LinkedList.h */

  static std::list<int> add(std::list<int> &l1, std::list<int> &l2);
  static std::list<int> add_v2(std::list<int> &l1, std::list<int> &l2);

  /* Checking if a list is palindrome is found in Data_Strutures/LinkedList.h
  and Data_Strutures/SinglyLinkedList.h */


private:
  /* Helper functions. */
};

/* Removes duplicates by traversing the list with two pointers and constantly
  compare them. */
template <typename V>
void LinkedLists<V>::removeDuplicates(std::list<V> &l)
{
  if (l.size() < 2) {
    return;
  }

  for (auto it1 = l.begin(); it1 != l.end(); ++it1) {
    for (auto it2 = it1; it2 != l.end(); ++it2) {
      if (it1 != it2 && *it2 == *it1) {
        l.erase(it2);
        it2--;
      }
    }
  }

}

/* Removes the duplicates by using a hashtable. */
template <typename V>
void LinkedLists<V>::removeDuplicates_v2(std::list<V> &l)
{
  std::unordered_map<V, bool> lmap;

  if (l.size() < 2) {
    return;
  }

  for (auto it = l.begin(); it != l.end(); ++it) {
    if (lmap.find(*it) != lmap.end()) {
      l.erase(it);
      it--;
    } else {
      lmap[*it] = true;
    }
  }

}

/* Return the kth to last element by traversing the list with 2 pointers.*/
template <typename V>
V LinkedLists<V>::kthToLast(std::list<V> &l, int k)
{
  typename std::list<V>::iterator it1, it2;
  it1 = it2 = l.begin();

  /* Move first pointer forwark with k elements. */
  for (int i = 0; i < k; i++) {
    if (it1 == l.end()) {
      return V();
    }
    it1++;
  }

  /* When the first pointer reaches the end of the list the second pointer will
  be pointing at the kth to last element. */
  while (it1 != l.end()) {
    it1++;
    it2++;
  }
  return *it2;
}

template <typename V>
void LinkedLists<V>::partition(std::list<V> &l, V pivot)
{
  auto it = l.begin();
  int ending = l.size();
  int index = 0;

  while (index < ending) {
    if (*it >= pivot) {
      l.push_back(*it);
      it = l.erase(it); // remain on the same position if deleting an element
    } else {
      it++; // go to the following position if element not deteletd
    }
    index++;
  }
}

/* Adds number memorisez as listd with the first element the least significant
  digit. */
template <typename V>
std::list<int> LinkedLists<V>::add(std::list<int> &l1, std::list<int> &l2)
{
  std::list<int> result;
  int accumulator = 0;
  auto it1 = l1.begin();
  auto it2 = l2.begin();

  while (it1 != l1.end() && it2 != l2.end()) {
    result.push_back((*it1 + *it2 + accumulator) % 10);
    accumulator = (*it1 + *it2 + accumulator) / 10;
    it1++;
    it2++;
  }
  if (it1 != l1.end()) {
    result.push_back((*it1 + accumulator) % 10);
    accumulator = (*it1 + accumulator) / 10;
    it1++;
  }
  if (it2 != l2.end()) {
    result.push_back((*it2 + accumulator) % 10);
    accumulator = (*it2 + accumulator) / 10;
    it2++;
  }
  if (accumulator) {
    result.push_back(accumulator);
  }
  return result;
}

/* Adds number memorisez as listd with the first element the most significant
  digit by adding 0-s in front. */
template <typename V>
std::list<int> LinkedLists<V>::add_v2(std::list<int> &l1, std::list<int> &l2)
{
  std::list<int> result;
  int accumulator = 0;

  while (l1.size() < l2.size()) {
    l1.push_front(0);
  }

  while (l2.size() < l1.size()) {
    l2.push_front(0);
  }

  std::reverse_iterator<std::list<int>::iterator> it1 = l1.rbegin();
  std::reverse_iterator<std::list<int>::iterator> it2 = l2.rbegin();

  while (it1 != l1.rend() && it2 != l2.rend()) {
    result.push_front((*it1 + *it2 + accumulator) % 10);
    accumulator = (*it1 + *it2 + accumulator) / 10;
    it1++;
    it2++;
  }

  if (accumulator) {
    result.push_front(accumulator);
  }

  return result;
}
#endif