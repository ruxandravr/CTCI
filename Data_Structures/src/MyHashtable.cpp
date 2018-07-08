// #include <bits/stdc++.h>

#include "MyHashtable.h"
#include <functional>

#define SIZE 64

int main() {
    MyHashtable<int, std::string> H1;
    MyHashtable<std::string, int> H2(SIZE, [](std::string x) {
        int sum = 0;
        for (int i = 0; i < x.size(); i++) {
            sum += x[i];
        }
        return  sum % SIZE;});

    H1.insert(1, "Ana");
    H1.insert(2, "Radu");
    H1.insert(11, "Maria");

    H2.insert("Ana", 2);
    H2.insert("Radu", 6);
    H2.insert("Aaa", 10);

    std::cout << H1.get(1) << " " << H1.get(11) << " " << H1.get(2) << "\n";
    std::cout << H2.get("Ana") << " " << H2.get("Radu") << " " << H2.get("Aaa") 
        << "\n";

    MyHashtable<int, std::string> H3 = H1;
    H3.insert(12134, "Crap");
    std::cout << "Testing copy assingment operator:\n";
    std::cout << H3.get(1) << " " << H3.get(11) << " " << H3.get(2) << " "
        << H3.get(12134) << "\n";
    
    MyHashtable<int, std::string> H4(H1);
    H4.insert(12134, "SchaiBe");
    std::cout << "Testing copy constructor :\n";
    std::cout << H4.get(1) << " " << H4.get(11) << " " << H4.get(3332) << " "
        << H4.get(12134) << "\n";

    MyHashtable<std::string, int> H5(H2);
    std::cout << H5.get("Ana") << " " << H5.get("Radu") << " " << H5.get("Aaa") 
        << "\n";

    return 0;
}