#ifndef CTCI_HASHTABLE_H
#define CTCI_HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <functional>

#include "Entry.h"

using namespace std;
#define MAXSIZE 64

template <typename K, typename V>
class Hashtable {
private:
    vector<list<Entry<K, V> > > H; // vector of lists -> chaining
    int size;
    static int hashFunc(K key); /* Default hash function */

public:
    int (*hash)(K);
    Hashtable(); // default constructor
    /*  destructor uses clear that separately calls the destructor for each
        element of the vector */
    ~Hashtable();

    Hashtable(Hashtable<K, V> &other);
    int getSize();
    Hashtable(int maxSize, int (*h)(K));
    Hashtable& operator=(Hashtable<K, V> &other);
    bool hasKey(K key);  // checks if key is in the Hashtable
    void insert(K key, V value);
    V get(K key);
    list<Entry<K,V> > getListAtIndex(int index);
};

/* Default hash function */
template <typename K, typename V>
int Hashtable<K, V>::hashFunc(K key) {
    std::hash<K> hashVal;
    return hashVal(key) % MAXSIZE;
}

template <typename K, typename V>
int Hashtable<K, V>::getSize() {
    return size;
}

template <typename K, typename V>
Hashtable<K, V>::Hashtable(int maxSize, int (*h)(K)) {
    hash = h;
    size = maxSize;
    // H =  vector<list<Entry<K, V> > > (maxSize);
    H.resize(maxSize);
}

/* default constructor */
template <typename K, typename V>
Hashtable<K, V>::Hashtable() {
    size = MAXSIZE;
    H.resize(MAXSIZE);
    hash = hashFunc;
}

/* destructor uses clear that separately calls the destructor for each
element of the vector */
template <typename K, typename V>
Hashtable<K, V>::~Hashtable() {
    size = 0;
    H.clear();
}

template <typename K, typename V>
Hashtable<K, V>::Hashtable(Hashtable<K, V> &other) {
    size = other.getSize();
    hash = other.hash;
    H.resize(size);

    for (int i = 0; i < size; i++){
        for (auto &entry :  other.getListAtIndex(i)) {
            H[i].push_back(entry);
        }
    }
}

template <typename K, typename V>
Hashtable<K, V>& Hashtable<K, V>::operator=(Hashtable<K, V> &other) {
    size = other.getSize();
    hash = other.hash;
    H.resize(size);

    for (int i = 0; i < size; i++){
        for (auto &entry :  other.getListAtIndex(i)) {
            H[i].push_back(entry);
        }
    }
    return *this;
}

/* checks if key is in the Hashtable */
template <typename K, typename V>
bool Hashtable<K, V>::hasKey(K key) {
    int index = hash(key);

    /* no list for key*/
    if (H[index].empty()) {
        return false;
    }

    /* key not found in the list */
    for (auto &entry : H[index]) {
        if (entry.getKey() == key) {
            return true;
        }
    }

    return false;
}


template <typename K, typename V>
void Hashtable<K, V>::insert(K key, V value) {
    Entry<K, V> newEntry(key, value);
    int index = hash(key);
    bool found = false;

    /* update value if key already exists*/
    for (auto &entry : H[index]) {
        if (entry.getKey() == key) {
            entry.setValue(value);
            found = true;
            break;
        }
    }
    /* add a new entry to the list if the key wasn't found */
    if (!found) {
        H[index].push_back(newEntry);
    }

}


template <typename K, typename V>
V Hashtable<K, V>::get(K key) {
    /* check if key exists in the Hashtable */
    if (!hasKey(key)) {
        return V();
    }

    /* look for the value */
    int index = hash(key);
    for (auto &entry : H[index]) {
        if (entry.getKey() == key) {
            return entry.getValue();
        }
    }
}

template <typename K, typename V>
list<Entry<K,V> > Hashtable<K, V>::getListAtIndex(int index) {
    return H[index];
}

#endif