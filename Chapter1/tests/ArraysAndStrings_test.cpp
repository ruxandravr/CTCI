#include "../src/ArraysAndStrings.h"
#include <gtest/gtest.h>

#include <string>

TEST(ArraysAndStrings, CheckDuplicates_V1)
{
  std::string testString = "aaaaaaa";
  ASSERT_EQ(true, ArraysAndStrings::checkDuplicates_v1(testString));

  testString = "";
  ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v1(testString));

  testString = "abcdef";
  ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v1(testString));

  testString = "';   ds";
  ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v1(testString));
}

TEST(ArraysAndStrings, CheckDuplicates_V2)
{
  std::string testString = "aaaaaaa";
  ASSERT_EQ(true, ArraysAndStrings::checkDuplicates_v2(testString));

  testString = "";
  ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v2(testString));

  testString = "abcdef";
  ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v2(testString));

  testString = "';   ds";
  ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v2(testString));
}

TEST(ArraysAndStrings, CheckPermutation_V1)
{
  std::string testString1 = "aaaaaaa";
  std::string testString2 = "bbbbbbb";

  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v1(testString1, testString2));

  testString2 = "";
  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v1(testString1, testString2));

  testString2 = "aaaaaa";
  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v1(testString1, testString2));

  testString2 = "aaaaaaa";
  ASSERT_EQ(true, ArraysAndStrings::checkPermutation_v1(testString1, testString2));

  testString1 = "";
  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v1(testString1, testString2));

  testString1 = "aabcdeef";
  testString2 = "bcdefeaaa";
  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v1(testString1, testString2));

  testString2 = "bcdefeaa";
  ASSERT_EQ(true, ArraysAndStrings::checkPermutation_v1(testString1, testString2));

  testString1 = "";
  testString2 = "";
  ASSERT_EQ(true, ArraysAndStrings::checkPermutation_v1(testString1, testString2));

}

TEST(ArraysAndStrings, CheckPermutation_V2)
{
  std::string testString1 = "aaaaaaa";
  std::string testString2 = "bbbbbbb";

  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v2(testString1, testString2));

  testString2 = "";
  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v2(testString1, testString2));

  testString2 = "aaaaaa";
  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v2(testString1, testString2));

  testString2 = "aaaaaaa";
  ASSERT_EQ(true, ArraysAndStrings::checkPermutation_v2(testString1, testString2));

  testString1 = "";
  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v2(testString1, testString2));

  testString1 = "aabcdeef";
  testString2 = "bcdefeaaa";
  ASSERT_EQ(false, ArraysAndStrings::checkPermutation_v2(testString1, testString2));

  testString2 = "bcdefeaa";
  ASSERT_EQ(true, ArraysAndStrings::checkPermutation_v2(testString1, testString2));

  testString1 = "";
  testString2 = "";
  ASSERT_EQ(true, ArraysAndStrings::checkPermutation_v2(testString1, testString2));

}

TEST(ArraysAndStrings, URLify)
{
  std::vector<char> v = {'a', 'n', 'a', ' ' ,'a', 'r', 'e', ' ', 'm', 'e', 'r',
                         'e'
                        };
  ASSERT_EQ("ana%20are%20mere", ArraysAndStrings::URLify(v));

  v.clear();
  ASSERT_EQ("", ArraysAndStrings::URLify(v));

  v = {'a', 'n', 'a'};
  ASSERT_EQ("ana", ArraysAndStrings::URLify(v));

  v = {' ', ' '};
  ASSERT_EQ("%20%20", ArraysAndStrings::URLify(v));

}

TEST(ArraysAndStrings, palindromePermutation_V1)
{
  std::string testString = "Tact coa";
  ASSERT_EQ(true, ArraysAndStrings::palindromePermutation_v1(testString));

  testString = " c";
  ASSERT_EQ(true, ArraysAndStrings::palindromePermutation_v1(testString));

  testString = " ";
  ASSERT_EQ(true, ArraysAndStrings::palindromePermutation_v1(testString));

  testString = "AAAA";
  ASSERT_EQ(true, ArraysAndStrings::palindromePermutation_v1(testString));

  testString = "AabA";
  ASSERT_EQ(false, ArraysAndStrings::palindromePermutation_v1(testString));
}

TEST(ArraysAndStrings, palindromePermutation_V2)
{
  std::string testString = "Tact coa";
  ASSERT_EQ(true, ArraysAndStrings::palindromePermutation_v2(testString));

  testString = " c";
  ASSERT_EQ(true, ArraysAndStrings::palindromePermutation_v2(testString));

  testString = " ";
  ASSERT_EQ(true, ArraysAndStrings::palindromePermutation_v2(testString));

  testString = "AAAA";
  ASSERT_EQ(true, ArraysAndStrings::palindromePermutation_v2(testString));

  testString = "AabA";
  ASSERT_EQ(false, ArraysAndStrings::palindromePermutation_v2(testString));
}

TEST(ArraysAndStrings, oneAway)
{
  std::string testString1 = "pale";
  std::string testString2 = "ale";
  ASSERT_EQ(true, ArraysAndStrings::oneAway(testString1, testString2));

  testString1 = "pales";
  testString2 = "pale";
  ASSERT_EQ(true, ArraysAndStrings::oneAway(testString1, testString2));
  ASSERT_EQ(true, ArraysAndStrings::oneAway(testString2, testString1));

  testString1 = "pale";
  testString2 = "bale";
  ASSERT_EQ(true, ArraysAndStrings::oneAway(testString1, testString2));
  ASSERT_EQ(true, ArraysAndStrings::oneAway(testString2, testString1));

  testString1 = "pale";
  testString2 = "bae";
  ASSERT_EQ(false, ArraysAndStrings::oneAway(testString1, testString2));
  ASSERT_EQ(false, ArraysAndStrings::oneAway(testString2, testString1));

  testString1 = "aabc";
  testString2 = "abcd";
  ASSERT_EQ(false, ArraysAndStrings::oneAway(testString1, testString2));
  ASSERT_EQ(false, ArraysAndStrings::oneAway(testString2, testString1));

  testString1 = "aabc";
  testString2 = "    ";
  ASSERT_EQ(false, ArraysAndStrings::oneAway(testString1, testString2));
  ASSERT_EQ(false, ArraysAndStrings::oneAway(testString2, testString1));

}

TEST(ArraysAndStrings, stringCompression)
{
  std::string testString = "aaabbccd";
  ASSERT_EQ("a3b2c2d1", ArraysAndStrings::stringCompression(testString));

  testString = "abcd";
  ASSERT_EQ("abcd", ArraysAndStrings::stringCompression(testString));

  testString = " a  ";
  ASSERT_EQ(" a  ", ArraysAndStrings::stringCompression(testString));

}
TEST(ArraysAndStrings, rotateMatrix)
{
  std::vector<std::vector<int> > M = {{1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };

  std::vector<std::vector<int> > newM = {{13, 9, 5, 1},
    {14, 10, 6, 2},
    {15, 11, 7, 3},
    {16, 12, 8, 4}
  };

  ArraysAndStrings::rotateMatrix(M);
  ASSERT_EQ(M, newM);

  M = {{1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
  };

  newM = {{21,16, 11, 6, 1},
    {22,17, 12, 7, 2},
    {23,18, 13, 8, 3},
    {24,19, 14, 9, 4},
    {25,20, 15, 10, 5}
  };

  ArraysAndStrings::rotateMatrix(M);
  ASSERT_EQ(M, newM);

  M = {{1, 2}, {3, 4}};

  newM = {{3, 1}, {4, 2}};

  ArraysAndStrings::rotateMatrix(M);
  ASSERT_EQ(M, newM);

}

TEST(ArraysAndStrings, zeroMatrix)
{
  std::vector<std::vector<int> > M = {{1, 0, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 0, 0},
    {13, 0, 15, 16}
  };

  std::vector<std::vector<int> > newM = {{0, 0, 0, 0},
    {5, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  };

  ArraysAndStrings::zeroMatrix(M);
  ASSERT_EQ(M, newM);

  M = {{0, 2, 3, 4, 5},
    {6, 0, 8, 9, 10},
    {11, 12, 0, 14, 15},
    {16, 17, 0, 11, 20},
    {21, 22, 0, 24, 0}
  };

  newM = {{0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };

  ArraysAndStrings::zeroMatrix(M);
  ASSERT_EQ(M, newM);

  M = {{1, 2}, {3, 4}};

  newM = {{1, 2}, {3, 4}};

  ArraysAndStrings::zeroMatrix(M);
  ASSERT_EQ(M, newM);

}
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}