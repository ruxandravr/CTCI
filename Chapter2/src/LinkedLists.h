#ifndef CTCI_LINKED_LISTS_H
#define CTCI_LINKED_LISTS_H

#include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_set>
// #include <algorithm>
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


private:
  /* Helper functions. */
};

/* Removes duplicates by traversing the list with two pointers and constantly
  compare them. */
template <typename V>
void LinkedLists<V>::removeDuplicates(std::list<V> &l)
{
  typename std::list<V>::iterator it1, it2;

  if (l.size() < 2) {
    return;
  }

  for (it1 = l.begin(); it1 != l.end(); ++it1) {
    for (it2 = it1; it2 != l.end(); ++it2) {
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
  typename std::list<V>::iterator it;
  std::unordered_map<V, bool> lmap;

  if (l.size() < 2) {
    return;
  }

  for (it = l.begin(); it != l.end(); ++it) {
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


#endif
