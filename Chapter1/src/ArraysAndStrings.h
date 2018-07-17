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
  static void zeroMatrix(std::vector <std::vector<int> > &M);

private:
  /* Helper functions. */
  static void markApparences(std::vector<int> &apparences, const std::string &s);
  static bool letterCheck(const std::string &s);
  static int compressedLength(const std::string &s);
  static void zeroRow(std::vector <std::vector<int> > &M, int row);
  static void zeroColumn(std::vector <std::vector<int> > &M, int column);
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
  markApparences(apparences, s1);

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

/* check how many times each character appears */
bool ArraysAndStrings::palindromePermutation_v1(std::string s)
{
  std::vector<int> apparences(26, 0);
  int oddApparences = 0;

  std::transform(s.begin(), s.end(), s.begin(), ::tolower);

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
      apparences[s[i] - 'a']++;
      /* [OPTION 1] In place check */
      if (apparences[s[i] - 'a'] % 2) {
        oddApparences++;
      } else {
        oddApparences--;
      }
    }
  }
  /* [OPTION 2] Additional traversal of the array */
//   for (auto charApparence : apparences) {
//       if (charApparence % 2) {
//         oddApparences++;
//       }
//     }

  /* if the length of the array is even -> oddApparences should be 0
  	if the length is odd -> oddAparences should be 1 */
  return oddApparences <= 1;

}

/* check how many times each character appears
	[bitwise operations] */
bool ArraysAndStrings::palindromePermutation_v2(std::string s)
{
  int apparences = 0, oddApparences = 0;

  std::transform(s.begin(), s.end(), s.begin(), ::tolower);

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
      apparences ^= (1 << (s[i] - 'a'));
      /* [OPTION 1] In place check */
      if (apparences & (1 << (s[i] - 'a'))) {
        oddApparences++;
      } else {
        oddApparences--;

      }
    }
  }

  /* if the length of the array is even -> oddApparences should be 0
  	if the length is odd -> oddAparences should be 1 */
  return oddApparences <= 1;

  /* using only the apparenes counter -> it should have 0 or 1 bits of 1*/
  // return (apparences == 0) || (apparences & (apparences - 1)) == 0;
}


/* traverse both strings simultaneously and check the characters at the same
  position and accept only one different character*/
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

/* Swap rows from exterior to interior */
void ArraysAndStrings::rotateMatrix(std::vector<std::vector <int> > &M) {
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

void ArraysAndStrings::zeroMatrix(std::vector<std::vector <int> > &M) {
	std::unordered_set<int> rows;
	std::unordered_set<int> columns;

	for (int i = 0; i < M.size(); ++i) {
		for (int j = 0; j < M[0].size(); ++j) {
			if (M[i][j] == 0) {
				rows.insert(i);
				columns.insert(j);
			}
		}
	}

	for (auto row : rows) {
		zeroRow(M, row);
	}

	for (auto column : columns) {
		zeroColumn(M, column);
	}
}

/* Helper functions: */

/* @apparences = a vector with 26 positions corresponding to each alphabet
  letter which countes the number of apparences of each letter in string s */
void ArraysAndStrings::markApparences(std::vector<int> &apparences, const std::string &s)
{
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] - 'a' < 0 || s[i] - 'a' > 26) {
      std::cerr << "Error processing string\n";
    } else {
      apparences[s[i] - 'a']++;
    }
  }
}

bool ArraysAndStrings::letterCheck(const std::string &s)
{
  for (auto ch : s) {
    if (ch > 'z' || ch < 'A' || (ch > 'Z' && ch < 'a'))
      return false;
  }

  return true;
}

/* returns the length of a compressed string
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

void ArraysAndStrings::zeroRow(std::vector<std::vector <int> > &M, int row) {
	for (int i = 0; i < M[0].size(); ++i) {
		M[row][i] = 0;
	}
}

void ArraysAndStrings::zeroColumn(std::vector<std::vector <int> > &M, int column) {
	for (int i = 0; i < M.size(); ++i) {
		M[i][column] = 0;
	}
}

#endif
