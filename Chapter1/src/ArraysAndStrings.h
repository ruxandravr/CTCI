#ifndef CTCI_ARRAYS_AND_STRINGS_H
#define CTCI_ARRAYS_AND_STRINGS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ArraysAndStrings
{
public:
  /* For ACII characters 'a' to 'z' */
  static bool checkDuplicates_v1(const std::string &s);
  static bool checkDuplicates_v2(const std::string &s);

  static bool checkPermutation_v1(const std::string& s1, const std::string& s2);
  /* Dangerous method: modifies s1 and s2 */
  static bool checkPermutation_v2(std::string& s1, std::string& s2);

  /*  Assume we get a URL array with the size before URLify.
  	We return a string formed from the URLified array */
  static std::string URLify(std::vector<char>& url);

};

/* Returns true if a string has duplicates
   [additional data structure] */
bool ArraysAndStrings::checkDuplicates_v1(const std::string &s)
{
  std::vector<bool> charApparences(26, 0);
  if (s.length() > 26) {
    return true;
  }

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' < 0 || s[i] - 'a' > 25) {
      std::cerr << "Error processing string\n";
      return false;
    }

    if (charApparences[s[i] - 'a']) {
      return true;
    }
    charApparences[s[i] - 'a'] = true;
  }
  return false;
}

/* Returns true if a string has duplicates
   [bit manipulation] */
bool ArraysAndStrings::checkDuplicates_v2(const std::string &s)
{
  int charApparences = 0;

  if (s.length() > 26) {
    return true;
  }

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' < 0 || s[i] - 'a' > 26) {
      std::cerr << "Error processing string\n";
      return false;
    }

    if (charApparences & (1 << (s[i] - 'a'))) {
      return true;
    }
    charApparences ^=  (1 << (s[i] - 'a'));
  }
  return false;
}


/*  checks if each character has the same number of apparences in each string
    [uses additional data structure] */
bool ArraysAndStrings::checkPermutation_v1(const std::string &s1,
    const std::string &s2)
{
  //* count how many times a char appears in one string */
  std::vector<int> apparences(26, 0);

  if (s1.length() != s2.length()) {
    return false;
  }

  /* compute the first string */
  for (int i = 0; i < s1.length(); ++i) {
    apparences[s1[i] - 'a']++;
  }

  /* compute the second string */
  for (int i = 0; i < s2.length(); ++i) {
    apparences[s2[i] - 'a']--;
  }

  /* check equality of apparences */
  for (int i = 0; i < 26; ++i) {
    if (apparences[i] != 0) {
      return false;
    }
  }
  return true;
}

/* sorts both strings and verifies their equality */
bool ArraysAndStrings::checkPermutation_v2(std::string &s1,
    std::string &s2)
{

  if (s1.length() != s2.length()) {
    return false;
  }

  std::sort(s2.begin(), s2.end());
  std::sort(s1.begin(), s1.end());

  return s1 == s2;
}

/*  Add multiple spaces at the end of the vector and then compute the string
    from its end to its begining */
std::string ArraysAndStrings::URLify(std::vector<char>& url)
{
  int size = url.size(), newIndex;

  for (int i = 0; i < size; i++) {
    if (url[i] == ' ') {
      url.push_back(' ');
      url.push_back(' ');
    }
  }

  newIndex = url.size() - 1;
  for (int i = size - 1; i >= 0; --i) {
    if (url[i] != ' ') {
      url[newIndex--] = url[i];
    } else {
      url[newIndex--] = '0';
      url[newIndex--] = '2';
      url[newIndex--] = '%';
    }
  }
  return std::string(url.begin(), url.end());
}

#endif
