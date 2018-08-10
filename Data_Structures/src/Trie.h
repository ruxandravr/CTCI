#ifndef CTCI_TRIE_H
#define CTCI_TRIE_H

#include <iostream>
#include <string>

#define ALPHABET_SIZE 26

class Trie
{
private:
  Trie *children[ALPHABET_SIZE];
  bool isWord;

public:
  Trie();
  void insert(std::string word);
  bool hasWord(std::string word);
};

#endif