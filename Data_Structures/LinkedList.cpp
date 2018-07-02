#include "LinkedList.h"

int main() {
    LinkedList<int> L1;


    L1.addLast(1);
    L1.print();
    
    std::cout << "Testing remove first on one element.....";
    L1.removeFirst();
    L1.print();
    L1.addLast(1);
    
    std::cout << "Testing remove last on one element.....";
    L1.removeLast();
    L1.print();
    
    L1.addFirst(2);
    L1.addFirst(3);
    L1.addFirst(4);
    L1.addLast(5);
    std::cout << "Testing adding....";
    L1.print();

    std::cout << "Testing remove first.....";
    L1.removeFirst();
    L1.print();

    std::cout << "Testing remove last.....";
    L1.removeLast();
    L1.print();
    
    std::cout << "Testing copy constructor....";
    LinkedList<int> L2(L1);
    L2.print();

    std::cout << "Testing assignment operator....";
    LinkedList<int> L3;
    L3 = L1;
    L3.print();
    L3.addFirst(1);
    L3.print();
    L3.removeFirst();
    L3.removeFirst();
    L3.removeLast();
    L3.removeLast();
    L3.print();

    return 0;
}