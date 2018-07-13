#include "../src/MyHashtable.h"
#include <gtest/gtest.h>

#define SIZE 64

TEST(MyHashtableTest, HasKey) {
    MyHashtable<int, std::string> H1;
    H1.insert(1, "Ana");
    H1.insert(2, "Radu");
    H1.insert(11, "Maria");

    ASSERT_EQ(true, H1.hasKey(1));
    ASSERT_EQ(false, H1.hasKey(22));
}

TEST(MyHashtableTest, DefaultHashFuncInsertAndGet) {
    MyHashtable<int, std::string> H1;
    H1.insert(1, "Ana");
    H1.insert(2, "Radu");
    H1.insert(11, "Maria");

    ASSERT_EQ("Ana", H1.get(1));
    ASSERT_EQ("Radu", H1.get(2));
    ASSERT_EQ("Maria", H1.get(11));

    H1.insert(11,"Mary");
    ASSERT_EQ("Mary", H1.get(11));

}

TEST(MyHashtableTest, GivenHashFuncInsertAndGet) {
    MyHashtable<std::string, int> H2(SIZE, [](std::string x) {
        int sum = 0;
        for (int i = 0; i < x.size(); i++) {
            sum += x[i];
        }
        return  sum % SIZE;});
    
    H2.insert("Ana", 2);
    H2.insert("Radu", 6);
    H2.insert("Aaa", 10);

    ASSERT_EQ(2, H2.get("Ana"));
    ASSERT_EQ(6, H2.get("Radu"));
    ASSERT_EQ(10, H2.get("Aaa"));

    H2.insert("Aaa", 8);
    ASSERT_EQ(8, H2.get("Aaa"));

}

TEST(MyHashtableTest, CopyConstructor) {
    MyHashtable<int, std::string> H1;
    H1.insert(1, "Ana");
    H1.insert(2, "Radu");
    H1.insert(11, "Maria");

    MyHashtable<int, std::string> H2(H1);
    ASSERT_EQ(H1.get(1), H2.get(1));
    ASSERT_EQ(H1.get(2), H2.get(2));
    ASSERT_EQ(H1.get(11), H2.get(11));
}

TEST(MyHashtableTest, AssignemntOperator) {
    MyHashtable<int, std::string> H1;
    H1.insert(1, "Ana");
    H1.insert(2, "Radu");
    H1.insert(11, "Maria");

    MyHashtable<int, std::string> H2 = H1;
    ASSERT_EQ(H1.get(1), H2.get(1));
    ASSERT_EQ(H1.get(2), H2.get(2));
    ASSERT_EQ(H1.get(11), H2.get(11));
}
/* MORE TO COME */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}