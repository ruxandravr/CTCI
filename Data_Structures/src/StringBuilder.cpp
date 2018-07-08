#include "StringBuilder.h"

int main() {
    StringBuilder S;
    std::cout << "Testing append:\n";
    S.append("Ana ");
    S.append("are ");
    S.append("mere");

    S.print();
    
    std::cout << "Testing copy constructor:\n";
    StringBuilder S1(S);
    S1.print();

    std::cout << "Testing copy assignemnt:\n";
    StringBuilder S2 = S;
    S2.print();

    std::cout << "Testing clear:\n";
    S.clear();
    S.print();

    
    return 0;
}