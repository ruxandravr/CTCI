#include <bits/stdc++.h>
#include "Vector.h"
#include "LinkedList.h"

#include <functional>
using namespace std;

#define MAXSIZE 64

/* Entry in the MyHashtable <key, value> */
template <typename K, typename V>
struct Entry {
    private:
        K key;
        V value;

    public:
        Entry(K _key, V _value): key(_key), value(_value) {};
        Entry() {
        }
        Entry& operator=(Entry<K, V> &other) {
            this->key = other.getKey();
            this->value = other.getValue();
            return *this;
        }

        Entry(Entry<K, V> &other) {
            this->key = other.getKey();
            this->value = other.getValue();            
        }
        
        K getKey() {
            return key;
        }

        V getValue() {
            return value;
        }

        void setValue(V value) {
            this->value = value;
        }
};

template <typename K, typename V>
class MyHashtable {
    private:
        /* vector of lists -> chaining */
        Vector<LinkedList<Entry<K, V> > > H;
        int size;
        
        /* Default hash function */
        static int hashFunc(K key) {
            std::hash<K> hashVal;
            return hashVal(key) % MAXSIZE;
        }

    public:
        int (*hash)(K);
        
        MyHashtable(int maxSize, int (*h)(K)) {
            hash = h;
            size = maxSize;
            H.resize(maxSize);
        }

        /* default constructor */
        MyHashtable() {
            size = MAXSIZE;
            H.resize(MAXSIZE);
            hash = hashFunc;
        }

        /* copy constructor */
        MyHashtable(MyHashtable<K,V> &other) {
            size = other.getSize();
            hash = other.hash;
            H.resize(size);
            for (int i = 0; i < size; ++i) {
                H[i] = other.getListAtIndex(i);
            }
        }

        /* destructor empties each entry list */
        ~MyHashtable() {
            for (int i = 0; i < size; ++i) {
                while (!H[i].isEmpty()) {
                    H[i].removeFirst();
                }
            }
        }

        /* copy assignment */
        MyHashtable& operator=(const MyHashtable<K,V> &other) {
            size =  other.getSize();
            hash = other.hash;
            H.resize(size);
            for (int i = 0; i < size; ++i) {
                H[i] = other.getListAtIndex(i);
            }
            return *this;
        }

        int getSize() {
            return size;
        }

        /* checks if key is in the MyHashtable */
        bool hasKey(K key) {
            Node<Entry<K, V> > *current, *last; 
            int index = hash(key);
            
            /* no list for key*/
            if (H[index].isEmpty()) {
                return false;
            }
            
            /* Iterate through the LinkedList */    
            current = H[index].getFirst();
            last = H[index].getLast();
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

        void insert(K key, V value) {
            Entry<K, V> newEntry(key, value);
            Node<Entry<K, V> > *current, *last;
            int index = hash(key);
            bool found = false;

            /* update value if key already exists*/
            if (!H[index].isEmpty()) {
                current = H[index].getFirst();
                last = H[index].getLast();
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

        V get(K key) {
            Node<Entry<K, V> > *current, *last; 
            int index = hash(key);
            
            /* no list for key */
            if (H[index].isEmpty()) {
                return V();
            }
            
            /* Iterate through the LinkedList */
            current = H[index].getFirst();
            last = H[index].getLast();
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

        LinkedList<Entry<K, V> >& getListAtIndex(int index) {
            return  H[index];
        }
};