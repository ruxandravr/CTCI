#include "Trie.h"

Trie::Trie() {
    isWord = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        children[i] = nullptr;
    }
}

void Trie::insert(std::string word) {
    Trie *current = this;

    for (int i = 0; i < word.size(); ++i) {
        if (current->children[word[i] - 'a'] == nullptr) {
            Trie *newChild = new Trie();
            current->children [word[i] - 'a'] = newChild;
            current = newChild;
        } else {
            current = current->children[word[i] - 'a'];
        }
    }
    current->isWord = true;
}


bool Trie::hasWord(std::string word) {
    Trie *current = this;

    for (int i = 0; i < word.size(); ++i) {
        if (current->children[word[i] - 'a'] == nullptr) {
            return false;
        }
        current = current->children[word[i] - 'a'];
    }
    return (current->isWord == true);
}