#include <bits/stdc++.h>


template <typename V>
struct Node {
    public:
        V value;
        Node<V> *prev;
        Node<V> *next;

        //  Node() {
        //     prev = next = nullptr;
        // }

        Node(V value) {
            this->value = value;
            prev = next = nullptr;
        }

        Node<V>& operator=(Node<V> &other) {
            this->value = other.value;
            this->prev = other.prev;
            this->next = other.next;

            return *this;
        }

};

template <typename V>
struct LinkedList {
    private:
        Node<V> *first, *last;
        int *x;
    public:
        LinkedList() {
            first = last = nullptr;
        }

        /* Destructor */
        ~LinkedList() {
            std::cout << "Destructor\n";
            /* Option 1 */
            // Node<V> *current = first;
            // while (first != last) {
            //     delete current;
            //     current = first->next;
            //     first = current;
            // }
            // delete first, last, current;
            /* Option 2 */
            while (!isEmpty()) {
                removeFirst();
            }
        }

        Node<V>* getFirst() {
            return first;
        }

        Node<V>* getLast() {
            return last;
        }

        /* copy constructor */
        LinkedList (LinkedList<V> &other) {
            first = last = nullptr;
            if (!other.isEmpty()) {
                Node<V> *otherFirst = other.getFirst();
                Node<V> *otherLast = other.getLast();
                
                while (otherFirst != otherLast) {
                    addLast(otherFirst->value);
                    otherFirst = otherFirst->next;
                }
                addLast(otherLast->value);
                
            }
        }
        
        LinkedList<V>& operator=(LinkedList<V> &other) {
            first = last = nullptr;
            if (!other.isEmpty()) {
                Node<V> *otherFirst = other.getFirst();
                Node<V> *otherLast = other.getLast();
                
                while (otherFirst != otherLast) {
                    addLast(otherFirst->value);
                    otherFirst = otherFirst->next;
                }
                addLast(otherLast->value);
                
                delete otherFirst, otherLast;
            }
            return *this;
        }

        bool isEmpty() {
            return (first == nullptr) && (last == nullptr);
        }

        void addFirst(V value) {
            Node<V> *newNode = new Node<V>(value);
            
            if (isEmpty()) {
                first = last = newNode;
            }
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        
        void addLast(V value) {
            Node<V> *newNode = new Node<V>(value);
            
            if (isEmpty()) {
                first = last = newNode;
            } else {
                newNode->prev = last;
                last->next = newNode;
                last = newNode;
            }
        }

        void print() {
            Node<V> *current = first;
            if (!isEmpty()) {
                while (current != last) {
                    std::cout << current->value << " ";
                    current = current->next;
                }
                std::cout << current->value;   
            }
            std::cout <<"\n";
        }

        void removeFirst() {
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
            delete current;
        }   

        void removeLast() {
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
            delete current;
        }
};


