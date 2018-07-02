#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 64

/* Entry in the Hashtable <key, value> */
template <typename K, typename V>
struct Entry {
    private:
        K key;
        V value;

    public:
        Entry(K _key, V _value): key(_key), value(_value) {};
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
class Hashtable {
    private:
        /* vector of lists -> chaining */
        vector<list<Entry<K, V> > > H;
        int size;

        /* hash func */
        int hash(K key) {
            std::hash<K> hashVal;
            return hashVal(key) % size;
        }
    
    public:
        Hashtable(int maxSize) {
            size = maxSize;
            // H =  vector<list<Entry<K, V> > > (maxSize);
            H.resize(maxSize);
        }

        /* default constructor */
        Hashtable() {
            size = MAXSIZE;
            H.resize(MAXSIZE);
        }

        /* destructor uses clear that separately calls the destructor for each
        element of the vector */
        ~Hashtable() {
            H.clear();
        }

        /* checks if key is in the Hashtable */
        bool hasKey(K key) {
            int index = hash(key);
            
            /* no list for key*/
            if (H[index].empty()) {
                return false;
            }

            /* key not found in the list */
            for (auto entry : H[index]) {
                if (entry.getKey() == key) {
                    return true;
                }
            }

            return false;          
        }

        void insert(K key, V value) {
            Entry<K, V> newEntry(key, value);
            int index = hash(key);
            bool found = false;

            /* update value if key already exists*/
            for (auto entry : H[index]) {
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

        V get(K key) {
            /* check if key exists in the Hashtable */
            if (!hasKey(key)) {
                return V();
            }

            /* look for the value */
            int index = hash(key);
            for (auto entry : H[index]) {
                if (entry.getKey() == key) {
                    return entry.getValue();
                }
            }
        }
};