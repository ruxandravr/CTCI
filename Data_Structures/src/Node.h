#ifndef CTCI_NODE_H_
#define CTCI_NODE_H_

template <typename V>
class Node {
public:
    V value;
    Node<V> *prev;
    Node<V> *next;

    Node() = delete;
    ~Node() = default;
    Node(V value);
    Node<V>& operator=(const Node<V> &other);
    Node(const Node<V> &other);
    /*  Checks if the node has the same value as other node;
        For checking if it actually is the "same" node, use == operator */
    bool equals(const Node<V> &other);
};

template <typename V>
Node<V>::Node(V value) {
    this->value = value;
    prev = next = nullptr;
}

template <typename V>
Node<V>& Node<V>::operator=(const Node<V> &other) {
    this->value = other.value;
    this->prev = other.prev;
    this->next = other.next;

    return *this;
}

template <typename V>
Node<V>::Node(const Node<V> &other) {
    this->value = other.value;
    this->prev = other.prev;
    this->next = other.next;
}

template <typename V>
bool Node<V>::equals(const Node<V> &other) {
    return value == other.value;
}

#endif