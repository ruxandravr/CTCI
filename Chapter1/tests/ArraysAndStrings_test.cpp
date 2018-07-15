#include "../src/ArraysAndStrings.h"
#include <gtest/gtest.h>

#include <string>

TEST(ArraysAndStrings, CheckDuplicates_V1) {
    ArraysAndStrings a;
    
    std::string testString = "aaaaaaa";
    ASSERT_EQ(true, a.checkDuplicates_v1(testString));
    
    testString = "";
    ASSERT_EQ(false, a.checkDuplicates_v1(testString));

    testString = "abcdef";
    ASSERT_EQ(false, a.checkDuplicates_v1(testString));

    testString = "';   ds";
    ASSERT_EQ(false, a.checkDuplicates_v1(testString));
}

TEST(ArraysAndStrings, CheckDuplicates_V2) {
    ArraysAndStrings a;
    
    std::string testString = "aaaaaaa";
    ASSERT_EQ(true, a.checkDuplicates_v2(testString));
    
    testString = "";
    ASSERT_EQ(false, a.checkDuplicates_v2(testString));

    testString = "abcdef";
    ASSERT_EQ(false, a.checkDuplicates_v2(testString));

    testString = "';   ds";
    ASSERT_EQ(false, a.checkDuplicates_v2(testString));
}

TEST(ArraysAndStrings, CheckPermutation_V1) {
    ArraysAndStrings a;
    
    std::string testString1 = "aaaaaaa";
    std::string testString2 = "bbbbbbb";
    
    ASSERT_EQ(false, a.checkPermutation_v1(testString1, testString2));
    
    testString2 = "";
    ASSERT_EQ(false, a.checkPermutation_v1(testString1, testString2));

    testString2 = "aaaaaa";
    ASSERT_EQ(false, a.checkPermutation_v1(testString1, testString2));

    testString2 = "aaaaaaa";
    ASSERT_EQ(true, a.checkPermutation_v1(testString1, testString2));

    testString1 = "";
    ASSERT_EQ(false, a.checkPermutation_v1(testString1, testString2));

    testString1 = "aabcdeef";
    testString2 = "bcdefeaaa";
    ASSERT_EQ(false, a.checkPermutation_v1(testString1, testString2));

    testString2 = "bcdefeaa";
    ASSERT_EQ(true, a.checkPermutation_v1(testString1, testString2));
    
    testString1 = "";
    testString2 = "";
    ASSERT_EQ(true, a.checkPermutation_v1(testString1, testString2));

}

TEST(ArraysAndStrings, CheckPermutation_V2) {
    ArraysAndStrings a;
    
    std::string testString1 = "aaaaaaa";
    std::string testString2 = "bbbbbbb";
    
    ASSERT_EQ(false, a.checkPermutation_v2(testString1, testString2));
    
    testString2 = "";
    ASSERT_EQ(false, a.checkPermutation_v2(testString1, testString2));

    testString2 = "aaaaaa";
    ASSERT_EQ(false, a.checkPermutation_v2(testString1, testString2));

    testString2 = "aaaaaaa";
    ASSERT_EQ(true, a.checkPermutation_v2(testString1, testString2));

    testString1 = "";
    ASSERT_EQ(false, a.checkPermutation_v2(testString1, testString2));

    testString1 = "aabcdeef";
    testString2 = "bcdefeaaa";
    ASSERT_EQ(false, a.checkPermutation_v2(testString1, testString2));

    testString2 = "bcdefeaa";
    ASSERT_EQ(true, a.checkPermutation_v2(testString1, testString2));
    
    testString1 = "";
    testString2 = "";
    ASSERT_EQ(true, a.checkPermutation_v2(testString1, testString2));

}

TEST(ArraysAndStrings, URLify) {
    ArraysAndStrings a;
    
    std::vector<char> v = {'a', 'n', 'a', ' ' ,'a', 'r', 'e', ' ', 'm', 'e', 'r',
    'e'};
    ASSERT_EQ("ana%20are%20mere", a.URLify(v));

    v.clear();
    ASSERT_EQ("", a.URLify(v));

    v = {'a', 'n', 'a'};
    ASSERT_EQ("ana", a.URLify(v));

    v = {' ', ' '};
    ASSERT_EQ("%20%20", a.URLify(v));

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}