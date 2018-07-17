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

/* Returns true if a string has duplicates
   [additional data structure]. */
bool ArraysAndStrings::checkDuplicates_v1(const std::string &s)
{
  std::vector<bool> charAppearences(26, 0);
  if (s.length() > 26) {
    return true;
  }

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' < 0 || s[i] - 'a' > 25) {
      std::cerr << "Error processing string\n";
      return false;
    }

    if (charAppearences[s[i] - 'a']) {
      return true;
    }
    charAppearences[s[i] - 'a'] = true;
  }
  return false;
}

/* Returns true if a string has duplicates
   [bit manipulation]. */
bool ArraysAndStrings::checkDuplicates_v2(const std::string &s)
{
  int charAppearences = 0;

  if (s.length() > 26) {
    return true;
  }

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' < 0 || s[i] - 'a' > 26) {
      std::cerr << "Error processing string\n";
      return false;
    }

    if (charAppearences & (1 << (s[i] - 'a'))) {
      return true;
    }
    charAppearences ^=  (1 << (s[i] - 'a'));
  }
  return false;
}


/*  Checks if each character has the same number of appearences in each string
    [uses additional data structure]. */
bool ArraysAndStrings::checkPermutation_v1(const std::string &s1,
    const std::string &s2)
{
  //* count how many times a char appears in one string */
  std::vector<int> appearences(26, 0);

  if (s1.length() != s2.length()) {
    return false;
  }

  /* compute the first string */
  markAppearences(appearences, s1);

  /* compute the second string */
  for (int i = 0; i < s2.length(); ++i) {
    appearences[s2[i] - 'a']--;
  }

  /* check equality of appearences */
  for (int i = 0; i < 26; ++i) {
    if (appearences[i] != 0) {
      return false;
    }
  }
  return true;
}

/* Sorts both strings and verifies their equality. */
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
    from its end to its begining. */
std::string ArraysAndStrings::URLify(std::vector<char>& url)
{
  int size = url.size(), newIndex;

  for (int i = 0; i < size; ++i) {
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

/* Check how many times each character appears. */
bool ArraysAndStrings::palindromePermutation_v1(std::string s)
{
  std::vector<int> appearences(26, 0);
  int oddAppearences = 0;

  std::transform(s.begin(), s.end(), s.begin(), ::tolower);

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
      appearences[s[i] - 'a']++;
      /* [OPTION 1] In place check */
      if (appearences[s[i] - 'a'] % 2) {
        oddAppearences++;
      } else {
        oddAppearences--;
      }
    }
  }
  /* [OPTION 2] Additional traversal of the array */
//   for (auto charApparence : appearences) {
//       if (charApparence % 2) {
//         oddAppearences++;
//       }
//     }

  /* if the length of the array is even -> oddAppearences should be 0
  	if the length is odd -> oddAparences should be 1 */
  return oddAppearences <= 1;

}

/* Check how many times each character appears
  [bitwise operations]. */
bool ArraysAndStrings::palindromePermutation_v2(std::string s)
{
  int appearences = 0, oddAppearences = 0;

  std::transform(s.begin(), s.end(), s.begin(), ::tolower);

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
      appearences ^= (1 << (s[i] - 'a'));
      /* [OPTION 1] In place check */
      if (appearences & (1 << (s[i] - 'a'))) {
        oddAppearences++;
      } else {
        oddAppearences--;

      }
    }
  }

  /* if the length of the array is even -> oddAppearences should be 0
  	if the length is odd -> oddAparences should be 1 */
  return oddAppearences <= 1;

  /* using only the apparenes counter -> it should have 0 or 1 bits of 1*/
  // return (appearences == 0) || (appearences & (appearences - 1)) == 0;
}


/* Traverse both strings simultaneously and check the characters at the same
  position and accept only one different character. */
bool ArraysAndStrings::oneAway(const std::string &s1, const std::string &s2)
{
  int size1 = s1.length();
  int size2 = s2.length();

  if (abs (size1 - size2) > 1) {
    return false;
  }

  int index1 = 0, index2 = 0;
  bool faults = false;

  while (index1 < size1 && index2 < size2) {
    if (s1[index1] == s2[index2]) {
      index1++;
      index2++;
    } else {
      if (faults) { // previous fault found
        return false;
      }
      faults = true;  // one fault found
      if (size1 == size2) { // move forward in both strings
        index1++;
        index2++;
      } else if (size1 < size2) { // only move in the longer string
        index2++;
      } else {
        index1++;
      }
    }
  }
  return true;
}

/* Compress a string -> [letter][number_of_appearences]. */
std::string ArraysAndStrings::stringCompression(const std::string &s)
{
  // saftey check <- check if the string has only letter components
  if (!letterCheck(s)) {
    return s;
  }

  if (compressedLength(s) > s.length()) {
    return s;
  }

  /* Commented option is using a string instead of the char vector which
    is slower */
  // std::string newString = "";
  // newString += s[0];

  std::vector<char> newString;
  newString.push_back(s[0]);
  int counter = 1;

  for (int i = 1; i < s.length(); ++i) {
    if (s[i] == s[i - 1]) {
      counter++;
    } else {
      // newString += (counter + '0');
      newString.push_back(counter + '0');
      counter = 1;
      // newString += s[i];
      newString.push_back(s[i]);
    }
  }
  // newString += (counter + '0');
  newString.push_back(counter + '0');

  // return (newString.length() > s.length())? s : newString;
  return (newString.size() > s.length())? s :
         std::string(newString.begin(), newString.end());
}

/* Swap rows from exterior to interior. */
void ArraysAndStrings::rotateMatrix(std::vector<std::vector <int> > &M)
{
  int n = M.size(), tmp;

  for (int row = 0; row < n / 2; ++row) {
    for (int column = row; column < n - row - 1; ++column) {
      // store the element from the upper row
      tmp = M[row][column];

      // swap upper row with left row
      M[row][column] = M[n - column - 1][row];

      // swap left row with bottom row
      M[n - column - 1][row] = M[n - row - 1][n - column - 1];

      // swap bottom row with right row
      M[n- row - 1][n - column - 1] = M[column][n - row - 1];

      // swap right row with upper row
      M[column][n - row - 1] = tmp;
    }
  }
}


/* Traverese the matrix to check which rows and columns should be made 0 and
	zero-ify the found ones. [uses aditional space]. */
void ArraysAndStrings::zeroMatrix_v1(std::vector<std::vector <int> > &M)
{
  /* Commented option uses extra space to memorise rows/columns to be made 0 */
  // std::unordered_set<int> rows;
  // std::unordered_set<int> columns;

  /* Each 1-bit of these numbers represents one row/column to be made 0 */
  int rows = 0;
  int columns = 0;
  for (int i = 0; i < M.size(); ++i) {
    for (int j = 0; j < M[0].size(); ++j) {
      if (M[i][j] == 0) {
        // rows.insert(i);
        // columns.insert(j);
        rows |= (1 << i); // mark the row
        columns |= (1 << j);  // mark the column
      }
    }
  }

  // for (auto row : rows) {
  // 	zeroRow(M, row);
  // }

  // for (auto column : columns) {
  // 	zeroColumn(M, column);
  // }

  for (int i = 0; i < M.size(); ++i) {
    if (rows & (1 << i)) {
      zeroRow(M, i);
    }
  }


  for (int j = 0; j < M[0].size(); ++j) {
    if (columns & (1 << j)) {
      zeroColumn(M, j);
    }
  }
}

/* Use the first row to mark which columns should be made 0 and first column to
  mark which rows should be made 0. [no additional space]. */
void ArraysAndStrings::zeroMatrix_v2(std::vector<std::vector <int> > &M)
{
  bool firstRow = false;
  bool firstCol = false;

  // check if first row should be made 0
  for (int i = 0; i < M[0].size(); ++i) {
    if (M[0][i] == 0) {
      firstRow = true;
      break;
    }
  }

  // check if first column should be made 0
  for (int i = 0; i < M.size(); ++i) {
    if (M[i][0] == 0) {
      firstCol = true;
      break;
    }
  }

  /* check the rest of the matrix */
  for (int i = 1; i < M.size(); ++i) {
    for (int j = 1; j < M[0].size(); ++j) {
      if (M[i][j] == 0) {
        M[i][0] = 0;
        M[0][j] = 0;
      }
    }
  }

  /* zero-ify found rows/columns */
  for (int i = 0; i < M[0].size(); ++i) {
    if (M[0][i] == 0) {
      zeroColumn(M, i);
    }
  }

  for (int i = 0; i < M.size(); ++i) {
    if (M[i][0] == 0) {
      zeroRow(M, i);
    }
  }

  /* if needed zero-ify the first row/column */
  if (firstCol) {
    for (int i = 0; i < M.size(); ++i) {
      M[i][0] = 0;
    }
  }

  if (firstRow) {
    for (int i = 0; i < M[0].size(); ++i) {
      M[0][i] = 0;
    }
  }
}

/* Checks if s1 is a rotation of the string s1. */
bool ArraysAndStrings::isRotation(const std::string &s1, const std::string &s2)
{
  if (s1.length() != s2.length()) {
    return false;
  }

  /* Concatenate the first string with itself and check if the second one is its
  substring. */
  std::string doubleS1 = s1 + s1;
  return isSubstring(doubleS1, s2);
}

/* Helper functions: */

/* @appearences = a vector with 26 positions corresponding to each alphabet
  letter which countes the number of appearences of each letter in string s. */
void ArraysAndStrings::markAppearences(std::vector<int> &appearences, const std::string &s)
{
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' < 0 || s[i] - 'a' > 26) {
      std::cerr << "Error processing string\n";
    } else {
      appearences[s[i] - 'a']++;
    }
  }
}

/* Checks if a string only contains literal characters. */
bool ArraysAndStrings::letterCheck(const std::string &s)
{
  for (auto ch : s) {
    if (ch > 'z' || ch < 'A' || (ch > 'Z' && ch < 'a'))
      return false;
  }

  return true;
}

/* Returns the length of a compressed string.
   eg: "aaabbcd" -> "a3b2c1d2" -> returns 8 */
int ArraysAndStrings::compressedLength(const std::string &s)
{
  int length = 2; // first and last letters

  for (int i = 1; i < s.length(); ++i) {
    if (s[i] != s[i - 1]) {
      length += 2;
    }
  }
  return length;
}

/* Make all the elements in the given row 0. */
void ArraysAndStrings::zeroRow(std::vector<std::vector <int> > &M, int row)
{
  for (int i = 0; i < M[0].size(); ++i) {
    M[row][i] = 0;
  }
}

/* Make all the elements in the given column 0. */
void ArraysAndStrings::zeroColumn(std::vector<std::vector <int> > &M, int column)
{
  for (int i = 0; i < M.size(); ++i) {
    M[i][column] = 0;
  }
}

/* Checks if smallString is a substring of bigString. */
bool ArraysAndStrings::isSubstring(const std::string &bigString,
                                   const std::string &smallString)
{
  if (smallString.length() > bigString.length()) {
    return false;
  }

  /* Iterate through all possible substrings. */
  for (int i = 0; i < bigString.length() - smallString.length(); ++i) {
    std::string check = bigString.substr(i, smallString.length());
    if (check == smallString) {
      return true;
    }
  }
  return false;
}

#endif
