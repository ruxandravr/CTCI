// #include <bits/stdc++.h>

#include "Hashtable.h"

int main() {
    Hashtable<int, std::string> H1;
    Hashtable<std::string, int> H2(10);

    H1.insert(1, "Ana");
    H1.insert(2, "Radu");
    H1.insert(11, "Maria");

    H2.insert("Ana", 2);
    H2.insert("Radu", 6);
    H2.insert("Aaa", 10);

    std::cout << H1.get(1) << " " << H1.get(11) << " " << H1.get(2) << "\n";
    std::cout << H2.get("Ana") << " " << H2.get("Radu") << " " << H2.get("Aaa") 
        << "\n";

    return 0;
}