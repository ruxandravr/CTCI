#include "../src/ArraysAndStrings.h"
#include <gtest/gtest.h>

#include <string>

TEST(ArraysAndStrings, CheckDuplicates_V1) {
    std::string testString = "aaaaaaa";
    ASSERT_EQ(true, ArraysAndStrings::checkDuplicates_v1(testString));

    testString = "";
    ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v1(testString));

    testString = "abcdef";
    ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v1(testString));

    testString = "';   ds";
    ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v1(testString));
}

TEST(ArraysAndStrings, CheckDuplicates_V2) {
    std::string testString = "aaaaaaa";
    ASSERT_EQ(true, ArraysAndStrings::checkDuplicates_v2(testString));

    testString = "";
    ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v2(testString));

    testString = "abcdef";
    ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v2(testString));

    testString = "';   ds";
    ASSERT_EQ(false, ArraysAndStrings::checkDuplicates_v2(testString));
}

TEST(ArraysAndStrings, CheckPermutation_V1) {
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

TEST(ArraysAndStrings, CheckPermutation_V2) {
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

TEST(ArraysAndStrings, URLify) {
    std::vector<char> v = {'a', 'n', 'a', ' ' ,'a', 'r', 'e', ' ', 'm', 'e', 'r',
    'e'};
    ASSERT_EQ("ana%20are%20mere", ArraysAndStrings::URLify(v));

    v.clear();
    ASSERT_EQ("", ArraysAndStrings::URLify(v));

    v = {'a', 'n', 'a'};
    ASSERT_EQ("ana", ArraysAndStrings::URLify(v));

    v = {' ', ' '};
    ASSERT_EQ("%20%20", ArraysAndStrings::URLify(v));

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}