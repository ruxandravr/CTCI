#ifndef CTCI_ENTRY_H
#define CTCI_ENTRY_H

/* Entry is a pair <key, value> */
template <typename K, typename V>
class Entry {
private:
    K key;
    V value;

public:
    Entry(K _key, V _value);
    Entry();  // cannot be used
    ~Entry() = default;

    Entry& operator=(const Entry<K, V> &other);
    Entry(const Entry<K, V> &other);
    K getKey();
    V getValue();
    void setValue(V value);
};

template <typename K, typename V>
Entry<K, V>::Entry(K _key, V _value): key(_key), value(_value) {}

template <typename K, typename V>
Entry<K, V>::Entry() {
    this->key = K();
    this->value = V();            
}

template <typename K, typename V>
Entry<K, V>& Entry<K, V>::operator=(const Entry<K, V> &other) {
    this->key = other.key;
    this->value = other.value;
    return *this;
}

template <typename K, typename V>
Entry<K, V>::Entry(const Entry<K, V> &other) {
    this->key = other.key;
    this->value = other.value;            
}

template <typename K, typename V>
K Entry<K,V>::getKey() {
    return key;
}

template <typename K, typename V>
V Entry<K, V>::getValue() {
    return value;
}

template <typename K, typename V>
void Entry<K, V>::setValue(V value) {
    this->value = value;
}

#endif