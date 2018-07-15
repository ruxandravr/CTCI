#ifndef CTCI_STRING_BUILDER_H
#define CTCI_STRING_BUILDER_H

#include <iostream>
#include <vector>

class StringBuilder {
private:
    /* array containing all characters in strings*/
    std::vector<char> charArray;

public:
    StringBuilder();
    ~StringBuilder();
    StringBuilder& operator=(StringBuilder &other);/* copy assignment */
    StringBuilder(StringBuilder &other); /* copy constructor */
    void append(std::string word); /* joining strings */
    void print (); /* printing strings */
    int size();
    void clear();
};


StringBuilder::StringBuilder() {
    charArray = std::vector<char>();
}

StringBuilder::~StringBuilder() {
    charArray.clear();
}

/* copy assignment */
StringBuilder& StringBuilder::operator=(StringBuilder &other) {
    charArray.clear();
    charArray = std::vector<char>(other.size());

    for (int i = 0; i < other.size(); ++i) {
        charArray[i] = other.charArray[i];
    }

    return *this;
}

/* copy constructor */
StringBuilder::StringBuilder(StringBuilder &other) {
    charArray = std::vector<char>(other.size());

    for (int i = 0; i < other.size(); ++i) {
        charArray[i] = other.charArray[i];
    }
}

/* joining strings */
void StringBuilder::append(std::string word) {
    for (int i = 0; i < word.length(); ++i) {
        charArray.push_back(word[i]);
    }
}

/* printing strings */
void StringBuilder::print () {
    for (auto c : charArray) {
        std::cout << c;
    }
    std::cout << "\n";
}

int StringBuilder::size() {
    return charArray.size();
}

void StringBuilder::clear() {
    charArray.clear();
}


#endif