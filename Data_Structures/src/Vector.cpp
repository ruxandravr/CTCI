#include "Vector.h"

int main() {
    Vector<int> arr(2);
    
    std::cout << "First array: testing push and remove operations\n";
    arr.removeFirst();
    arr.pushBack(1);
    arr.pushBack(2);
    arr.print();
    
    arr.pushBack(3);
    arr.removeFirst();
    arr.pushBack(4);
    arr.print();
    arr.removeLast();

    arr.pushBack(5);
    arr.print();
    
    Vector<int> arr2(arr);
    std::cout << "Second array: testing copy constructor\n";
    arr2.print();

    Vector<int> arr3(1, 1);
    std::cout << "Third array:testing second constructor\n";
    arr3.printAll();
    arr3.pushBack(2);
    arr3.print();
    arr3.pushBack(2);
    arr3.pushBack(3);
    arr3.print();
    arr3.printAll();

    std::cout << "Fourth array: testing copy assignemnt\n";
    Vector<int> arr4(2);
    arr4 = arr2;
    arr4.print();
    
    arr4.pushBack(3);
    arr4.pushBack(3);
    std::cout << "Testing remove first occurence\n";
    std::cout << "Before: ";
    arr4.print();
    arr4.removeFirstOccurence(3);
    std::cout << "After: ";
    arr4.print();

    std::cout << "Testing remove last occurence\n";
    std::cout << "Before: ";
    arr4.print();
    arr4.removeLastOccurence(3);
    std::cout << "After: ";
    arr4.print();
    arr4.removeLastOccurence(3);
    arr4.print();
    arr4.removeLastOccurence(3);
    arr4.print();
    arr4.removeFirstOccurence(5);
    arr4.removeFirstOccurence(2);
    arr4.removeFirstOccurence(2);
    arr4.removeLastOccurence(2);
    arr4.print();

    std::cout << "Testing operator +\nFirst array: ";
    arr.print();
    std::cout << "Second array: ";
    arr2.print();
    std::cout << "Sum: ";
    (arr + arr2).print();

    return 0;
}