#include "../src/LinkedList.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, EmptyList) {
    LinkedList<int> l;
    ASSERT_EQ(true, l.isEmpty());
}

TEST(LinkedListTest, NotEmptyListAfterAddFirst) {
    LinkedList<int> l;
    l.addFirst(2);
    ASSERT_EQ(false, l.isEmpty());
}

TEST(LinkedListTest, NotEmptyListAfterAddLast) {
    LinkedList<int> l;
    l.addLast(2);
    ASSERT_EQ(false, l.isEmpty());
}

TEST(LinkedListTest, AddFirst) {
    LinkedList<int> l;
    l.addLast(2);
    ASSERT_EQ(2, l.getFirstPtr()->value);
    ASSERT_EQ(2, l.getLastPtr()->value);
}

TEST(LinkedListTest, AddLast) {
    LinkedList<int> l;
    l.addLast(2);
    ASSERT_EQ(2, l.getFirstPtr()->value);
    ASSERT_EQ(2, l.getLastPtr()->value);
}

TEST(LinkedListTest, RemoveFirst) {
    LinkedList<int> l;
    l.removeFirst();
    ASSERT_EQ(true, l.isEmpty());
    l.addFirst(2);
    l.addLast(3);
    l.addFirst(1);
    l.removeFirst();
    ASSERT_EQ(2, l.getFirstPtr()->value);
}

TEST(LinkedListTest, Equals) {
    LinkedList<int> l1, l2;
    l1.addFirst(1);
    l1.addFirst(2);
    l1.addFirst(3);
    l2.addFirst(1);
    l2.addFirst(2);
    l2.addFirst(3);
    ASSERT_EQ(true, l1.equals(l2));
}

TEST(LinkedListTest, CopyConstructorAssignmentOperator) {
    LinkedList<std::string> l1;
    l1.addLast("Last");
    l1.addFirst("Middle");
    l1.addFirst("First");
    LinkedList<std::string> l2(l1);
    ASSERT_EQ(true, l1.equals(l2));
    LinkedList<std::string> l3 = l1;
    ASSERT_EQ(true, l1.equals(l3));
}

/* MORE TO COME */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}