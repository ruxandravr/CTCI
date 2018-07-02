#include <bits/stdc++.h>

template <typename V>
class Vector {
    private:
        V *array;
        int capacity;
        int size;

    public:
        /* Overloading [] operator */
        V& operator[](int pos) {
            return array[pos];
        }

        /* Overloading + operator */
        Vector<V> operator+(Vector<V> &other1) {
            int size1 = other1.getSize();
            int capacity1 = other1.getCapacity();
            
            Vector<V> newArray(capacity + capacity1);
            newArray.size = size + size1;
            newArray.capacity = capacity + capacity1;

            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            } 
            for (int i = size; i < size + size1; ++i) {
                newArray[i] = other1[i - size];
            }
            return newArray;
        }

        /* First constructor */
        Vector(int capacity) {
            this->capacity = capacity;
            this-> size = 0;
            this-> array =  new V[capacity];

        }

        /* Second constructor */
        Vector(int capacity, const V &initial) {
            this->capacity = capacity;
            this-> size = 0;
            this-> array =  new V[capacity];

            for (int i = 0; i < capacity; ++i) {
                array[i] = initial;
            }
        }

        /* Copy constructor */
        Vector(Vector<V> &other){
            array = new V[other.getCapacity()];
            size = other.getSize();
            capacity = other.getCapacity();

            for (int i = 0; i < other.getSize(); ++i) {
                array[i] = other[i];
            }
        }

        /* Destructor */
        ~Vector() {
            delete[] array;
        }

        /* Copy assignment */
        // Vector<V>& operator=(Vector<V> &other) {
        //     delete[] array;
        //     array = new V[other.getCapacity()];
        //     size = other.getSize();
        //     capacity = other.getCapacity();
            
        //     for (int i = 0; i < other.getSize(); ++i) {
        //         array[i] = other[i];
        //     }
            
        //     return *this;
        // }   

        /* Insert element at the end of the vector */
        void pushBack(const V value) {
            if (size < capacity) {
                array[size++] = value;
            } else {
                V *copy = new V[size];
                for (int i = 0; i < size; ++i) {
                    copy[i] = array[i];
                }
                capacity = capacity << 1;
                array = new V[capacity];
                for (int i = 0; i < size; ++i) {
                    array[i] = copy[i];
                }
                array[size++] = value;
                
                delete[] copy;
            }
        }

        /* Remove first element */
        void removeFirst() {
            if (!empty()) {
                for (int i = 0; i < size - 1; ++i) {
                    array[i] = array[i + 1];
                }
                size--;
            }
        }

        /* Remove last element */
        void removeLast() {
            if (!empty()) {
                size--;
            }
        }

        /* Remove first occurence of given element */
        void removeFirstOccurence(V value) {
            if (empty()) {
                return;
            }
            for (int i = 0; i < size; ++i) {
                if (array[i] ==  value) {
                    for (int j = i; j < size - 1; ++j) {
                        array[j] = array[j + 1];
                    }
                    size--;
                    break;
                }
            }
        }
        
        /* Remove last occurence of given element */
        void removeLastOccurence(V value) {
            if (empty()) {
                return;
            }
            for (int i = size - 1; i >= 0; --i) {
                if (array[i] ==  value) {
                    for (int j = i; j < size - 1; ++j) {
                        array[j] = array[j + 1];
                    }
                    size--;
                    break;
                }
            }
        }

        /* Print all inserted elements */
        void print() {
            for (int i = 0; i < size; ++i) {
                std::cout << array[i] << " ";
            }
            std::cout << "\n";

        }

        /* Print all elements - all capacity */
        void printAll() {
            for (int i = 0; i < capacity; ++i) {
                std::cout << array[i] << " ";
            }
            std::cout << "\n";

        }

        bool empty() {
            if (size == 0) {
                return true;
            }
            return false;
        }

        int getSize() {
            return size;
        }

        int getCapacity() {
            return capacity;
        }
};