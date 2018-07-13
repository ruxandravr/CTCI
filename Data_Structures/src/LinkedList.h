#ifndef CTCI_LINKED_LIST_H
#define CTCI_LINKED_LIST_H

#include "Node.h"
#include <iostream>

template <typename V>
class LinkedList {
    private:
        Node<V> *first, *last;
        int size;

    public:
        LinkedList();
        ~LinkedList();

        Node<V>* getFirstPtr() const;
        Node<V>* getLastPtr() const;
        LinkedList(const LinkedList<V> &other);
        LinkedList<V>& operator=(const LinkedList<V> &other);
        bool isEmpty() const;
        void addFirst(V value);
        void addLast(V value);
        void print();
        void removeFirst();
        void removeLast();
        bool contains(V value);
        bool equals(const LinkedList<V> &other);
        int getSize();
};

template<typename V>
LinkedList<V>::LinkedList() {
    first = last = nullptr;
    size = 0;
}

template<typename V>
LinkedList<V>::~LinkedList() {
    while (!isEmpty()) {
        removeFirst();
    }
    size = 0;
}

template<typename V>
Node<V>* LinkedList<V>::getFirstPtr() const {
    return first;
}

template<typename V>
Node<V>* LinkedList<V>::getLastPtr() const {
    return last;
}

template<typename V>
LinkedList<V>::LinkedList(const LinkedList<V> &other) {
    first = last = nullptr;
    if (!other.isEmpty()) {
        Node<V> *otherFirst = other.getFirstPtr();
        Node<V> *otherLast = other.getLastPtr();

        while (otherFirst != otherLast) {
            addLast(otherFirst->value);
            otherFirst = otherFirst->next;
        }
        addLast(otherLast->value);
    }

    size = other.size;
}

template<typename V>
LinkedList<V>& LinkedList<V>::operator=(const LinkedList<V> &other) {
    first = last = nullptr;
    if (!other.isEmpty()) {
        Node<V> *otherFirst = other.getFirstPtr();
        Node<V> *otherLast = other.getLastPtr();

        while (otherFirst != otherLast) {
            addLast(otherFirst->value);
            otherFirst = otherFirst->next;
        }
        addLast(otherLast->value);
    }
    size = other.size;
    return *this;
}

template<typename V>
bool LinkedList<V>::isEmpty() const {
    return (first == nullptr) && (last == nullptr);
}

template<typename V>
void LinkedList<V>::addFirst(V value) {
    Node<V> *newNode = new Node<V>(value);

    if (isEmpty()) {
        first = last = newNode;
    } else {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
    size++;
}

template<typename V>
void LinkedList<V>::addLast(V value) {
    Node<V> *newNode = new Node<V>(value);

    if (isEmpty()) {
        first = last = newNode;
    } else {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
    size++;
}

template<typename V>
void LinkedList<V>::print() {
    if (isEmpty()) return;

    Node<V> *current = first;
    while (current != last) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << current->value;
    std::cout <<"\n";
}

template<typename V>
void LinkedList<V>::removeFirst() {
    if (isEmpty()) {
        return;
    }

    Node<V> *current = first;
    if (first != last) {
        first->next->prev = nullptr;
        first = first->next;
    } else {
        first = last = nullptr;
    }
    size--;
    delete current;
}

template<typename V>
void LinkedList<V>::removeLast() {
    if (isEmpty()) {
        return;
    }

    Node<V> *current = last;
    if (first != last) {
        last->prev->next = nullptr;
        last = last->prev;
    } else {
        first = last = nullptr;
    }
    size--;
    delete current;
}

template<typename V>
bool LinkedList<V>::contains(V value) {
    if (isEmpty()) {
        return false;
    } else {
        Node<V> *current = first;
        while (current != last) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        if (last->value == value) {
            return true;
        }
        return false;
    }
}

template<typename V>
bool LinkedList<V>::equals(const LinkedList<V> &other) {
    if (size != other.size) {
        return false;
    }

    Node<V> *current = first, *otherCurrent = other.first;
    while (current != last && otherCurrent != other.last) {
        if (current->value != otherCurrent->value) {
            return false;
        }
        current = current->next;
        otherCurrent = otherCurrent->next;
    }

    if (current != last || otherCurrent != other.last) {
        return false;
    }

    return true;
}

template <typename V>
int LinkedList<V>::getSize() {
    return size;
}

#endif