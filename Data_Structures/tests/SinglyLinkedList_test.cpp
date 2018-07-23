#include "../src/SinglyLinkedList.h"
#include <gtest/gtest.h>

TEST(SinglyLinkedListTest, EmptyList)
{
  SinglyLinkedList<int> l;
  ASSERT_EQ(true, l.isEmpty());
}

TEST(SinglyLinkedListTest, NotEmptyListAfterAddFirst)
{
  SinglyLinkedList<int> l;
  l.addFirst(2);
  ASSERT_EQ(false, l.isEmpty());
}

TEST(SinglyLinkedListTest, NotEmptyListAfterAddLast)
{
  SinglyLinkedList<int> l;
  l.addLast(2);
  ASSERT_EQ(false, l.isEmpty());
}

TEST(SinglyLinkedListTest, AddLast)
{
  SinglyLinkedList<int> l;
  l.addLast(2);
  l.addFirst(1);
  l.addLast(3);
  ASSERT_EQ(1, l.getFirstPtr()->value);
  ASSERT_EQ(3, l.getLastPtr()->value);
}

TEST(SinglyLinkedListTest, AddFirst)
{
  SinglyLinkedList<int> l;
  l.addFirst(2);
  ASSERT_EQ(2, l.getLastPtr()->value);
  l.addFirst(1);
  ASSERT_EQ(1, l.getFirstPtr()->value);
}

TEST(SinglyLinkedListTest, RemoveFirst)
{
  SinglyLinkedList<int> l;
  l.removeFirst();
  ASSERT_EQ(true, l.isEmpty());
  l.addFirst(2);
  l.addLast(3);
  l.addFirst(1);
  l.removeFirst();
  ASSERT_EQ(2, l.getFirstPtr()->value);
  l.removeFirst();
  ASSERT_EQ(3, l.getFirstPtr()->value);
}
TEST(SinglyLinkedListTest, RemoveLast)
{
  SinglyLinkedList<int> l;
  l.removeLast();
  ASSERT_EQ(true, l.isEmpty());
  l.addFirst(2);
  l.addLast(3);
  l.addFirst(1);
  l.removeLast();
  ASSERT_EQ(2, l.getLastPtr()->value);
  l.removeLast();
  ASSERT_EQ(1, l.getLastPtr()->value);
}
TEST(SinglyLinkedListTest, Equals)
{
  SinglyLinkedList<int> l1, l2;
  l1.addFirst(1);
  l1.addFirst(2);
  l1.addFirst(3);
  l2.addFirst(1);
  l2.addFirst(2);
  l2.addFirst(3);
  ASSERT_EQ(true, l1.equals(l2));
}

TEST(SinglyLinkedListTest, CopyConstructorAssignmentOperator)
{
  SinglyLinkedList<std::string> l1;
  l1.addLast("Last");
  l1.addFirst("Middle");
  l1.addFirst("First");
  SinglyLinkedList<std::string> l2(l1);
  ASSERT_EQ(true, l1.equals(l2));
  SinglyLinkedList<std::string> l3 = l1;
  ASSERT_EQ(true, l1.equals(l3));
}

TEST(SinglyLinkedListTest, Size)
{
  SinglyLinkedList<int> l1;
  l1.addFirst(3);
  l1.addLast(4);
  l1.addFirst(5);
  ASSERT_EQ(3, l1.getSize());
  l1.removeFirst();
  l1.removeLast();
  ASSERT_EQ(1, l1.getSize());
  l1.removeFirst();
  l1.removeLast();
  ASSERT_EQ(0, l1.getSize());
}

TEST(SinglyLinkedList, GetNthNode)
{
  SinglyLinkedList<int> l1;
  l1.addLast(1);
  l1.addLast(2);
  l1.addLast(3);
  l1.addLast(4);
  l1.addLast(5);
  l1.addLast(6);
  l1.addLast(7);

  ASSERT_EQ(2, l1.getNthNode(2)->value);
}

TEST(LinkedLists, DeleteNode)
{
  SinglyLinkedList<int> l1;
  l1.addFirst(6);
  l1.addFirst(5);
  l1.addFirst(4);
  l1.addFirst(3);
  l1.addFirst(2);
  l1.addFirst(1);

  SinglyLinkedList<int> l2;
  l2.addFirst(6);
  l2.addFirst(5);
  l2.addFirst(3);
  l2.addFirst(2);
  l2.addFirst(1);

  SNode<int> *n = l1.getNthNode(4);

  l1.deleteNode(n);
  ASSERT_EQ(true, l1.equals(l2));

}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}