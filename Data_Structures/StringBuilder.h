#include <bits/stdc++.h>

class StringBuilder {
    private:
        /* array containing all characters in strings*/
        std::vector<char> charArray;

    public:
        StringBuilder() {
            charArray = std::vector<char>();
        }

        ~StringBuilder() {
            charArray.clear();
        }

        /* copy assignment */
        StringBuilder& operator=(StringBuilder &other) {
            charArray.clear();
            charArray = std::vector<char>(other.size());
            
            for (int i = 0; i < other.size(); ++i) {
                charArray[i] = other.charArray[i];
            }

            return *this;
        }

        /* copy constructor */
        StringBuilder(StringBuilder &other) {
            charArray = std::vector<char>(other.size());
            
            for (int i = 0; i < other.size(); ++i) {
                charArray[i] = other.charArray[i];
            }
        }

        /* joining strings */
        void append(std::string word) {
            for (int i = 0; i < word.length(); ++i) {
                charArray.push_back(word[i]);
            }
        }

        /* printing strings */
        void print () {
            for (auto c : charArray) {
                std::cout << c;
            }
            std::cout << "\n";
        }

        int size() {
            return charArray.size();
        }

        void clear() {
            charArray.clear();
        }
};