#ifndef CTCI_MY_HASHTABLE_H
#define CTCI_MY_HASHTABLE_H

#include <iostream>
#include <functional>

#include "Vector.h"
#include "LinkedList.h"
#include "Entry.h"

using namespace std;
#define MAXSIZE 64

template <typename K, typename V>
class MyHashtable {
private:
    Vector<LinkedList<Entry<K, V> > > H;  // vector of lists -> chaining
    int size;
    static int hashFunc(K key);  // default hash function

public:
    MyHashtable();  // default constructor
    ~MyHashtable(); // destructor empties each entry list

    int (*hash)(K);
    MyHashtable(int maxSize, int (*h)(K));
    MyHashtable(MyHashtable<K,V> &other); //copy constructor
    MyHashtable& operator=(const MyHashtable<K,V> &other); // copy assignment
    int getSize();
    bool hasKey(K key); // checks if key is in the MyHashtable
    void insert(K key, V value);
    V get(K key);
    LinkedList<Entry<K, V> >& getListAtIndex(int index);
};

template <typename K, typename V>
int MyHashtable<K, V>::hashFunc(K key) {
    std::hash<K> hashVal;
    return hashVal(key) % MAXSIZE;
}

template <typename K, typename V>
MyHashtable<K, V>::MyHashtable(int maxSize, int (*h)(K)) {
    hash = h;
    size = maxSize;
    H.resize(maxSize);
}

/* default constructor */
template <typename K, typename V>
MyHashtable<K, V>::MyHashtable() {
    size = MAXSIZE;
    H.resize(MAXSIZE);
    hash = hashFunc;
}

/* copy constructor */
template <typename K, typename V>
MyHashtable<K, V>::MyHashtable(MyHashtable<K,V> &other) {
    size = other.getSize();
    hash = other.hash;
    H.resize(size);
    for (int i = 0; i < size; ++i) {
        H[i] = other.getListAtIndex(i);
    }
}

/* destructor empties each entry list */
template <typename K, typename V>
MyHashtable<K, V>::~MyHashtable() {
    for (int i = 0; i < size; ++i) {
        while (!H[i].isEmpty()) {
            H[i].removeFirst();
        }
    }
}

/* copy assignment */
template <typename K, typename V>
MyHashtable<K, V>& MyHashtable<K, V>::operator=(const MyHashtable<K,V> &other) {
    size =  other.getSize();
    hash = other.hash;
    H.resize(size);
    for (int i = 0; i < size; ++i) {
        H[i] = other.getListAtIndex(i);
    }
    return *this;
}
template <typename K, typename V>
int MyHashtable<K, V>::getSize() {
    return size;
}

/* checks if key is in the MyHashtable */
template <typename K, typename V>
bool MyHashtable<K, V>::hasKey(K key) {
    Node<Entry<K, V> > *current, *last;
    int index = hash(key);

    /* no list for key*/
    if (H[index].isEmpty()) {
        return false;
    }

    /* Iterate through the LinkedList */
    current = H[index].getFirstPtr();
    last = H[index].getLastPtr();
    while (current != last) {
        if (current->value.getKey() == key) {
            return true;
        }
        current = current->next;
    }
    if (last->value.getKey() == key) {
        return true;
    }

    return false;
}

template <typename K, typename V>
void MyHashtable<K, V>::insert(K key, V value) {
    Entry<K, V> newEntry(key, value);
    Node<Entry<K, V> > *current, *last;
    int index = hash(key);
    bool found = false;

    /* update value if key already exists*/
    if (!H[index].isEmpty()) {
        current = H[index].getFirstPtr();
        last = H[index].getLastPtr();
        while (current != last) {
            if (current->value.getKey() == key) {
                current->value.setValue(value);
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found && current->value.getKey() == key) {
            current->value.setValue(value);
        }
    }
    // /* add a new entry to the list if the key wasn't found */
    if (!found) {
        H[index].addLast(newEntry);
    }
}

template <typename K, typename V>
V MyHashtable<K, V>::get(K key) {
    Node<Entry<K, V> > *current, *last;
    int index = hash(key);

    /* no list for key */
    if (H[index].isEmpty()) {
        return V();
    }

    /* Iterate through the LinkedList */
    current = H[index].getFirstPtr();
    last = H[index].getLastPtr();
    while (current != last) {
        if (current->value.getKey() == key) {
            return current->value.getValue();
        }
        current = current->next;
    }
    if (last->value.getKey() == key) {
        return current->value.getValue();
    }

    return V();
}

template <typename K, typename V>
LinkedList<Entry<K, V> >& MyHashtable<K, V>::getListAtIndex(int index) {
    return  H[index];
}

#endif