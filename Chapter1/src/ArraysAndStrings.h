#ifndef CTCI_ARRAYS_AND_STRINGS_H
#define CTCI_ARRAYS_AND_STRINGS_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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

  /* dismiss characters different from 'a'-'z' */
  static bool palindromePermutation_v1(std::string s);
  static bool palindromePermutation_v2(std::string s);

  static bool oneAway(const std::string &s1, const std::string &s2);
  static std::string stringCompression(const std::string &s);
  static void rotateMatrix(std::vector <std::vector<int> > &M);
  static void zeroMatrix_v1(std::vector <std::vector<int> > &M);
  static void zeroMatrix_v2(std::vector <std::vector<int> > &M);
  static bool isRotation(const std::string &s, const std::string &s2);

private:
  /* Helper functions. */
  static void markAppearences(std::vector<int> &appearences, const std::string &s);
  static bool letterCheck(const std::string &s);
  static int compressedLength(const std::string &s);
  static void zeroRow(std::vector <std::vector<int> > &M, int row);
  static void zeroColumn(std::vector <std::vector<int> > &M, int column);
  static bool isSubstring(const std::string &s, const std::string &s1);
};

#endif
