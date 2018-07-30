#include "../src/FixedMultiStack.h"
#include <gtest/gtest.h>


/* Uncomment the prints for better understanding. */
TEST(FixedMultiStacks, PushAndPeek)
{
  FixedMultiStack<int> m(3, 4);
  m.push(1, 1);
  m.push (3, 3);
  m.push (3, 3);
  m.push (3, 3);
  m.push (3, 3);
  m.push (3, 3);

  m.push(2, 2);
  m.push(1, 1);
  ASSERT_EQ(1, m.peek(1));
  ASSERT_EQ(2, m.peek(2));
  ASSERT_EQ(3, m.peek(3));
//   m.print();

}

TEST(FixedMultiStack, PushAndPop)
{
  FixedMultiStack<int> m(3, 4);
  m.push(1, 1);
  m.push (3, 3);
  m.push (3, 3);
  m.push (3, 3);
  m.push (3, 3);
  m.push (3, 3);
  m.push(2, 2);
  m.push(1, 1);

  ASSERT_EQ(1, m.pop(1));
  ASSERT_EQ(1, m.peek(1));
  ASSERT_EQ(2, m.peek(2));
  ASSERT_EQ(3, m.peek(3));
  // m.print()

  m.push (3, 3);
  m.push(1, 1);
  m.push (2, 2);
  m.push (2, 2);
  m.push (3, 3);

  ASSERT_EQ(3, m.pop(3));
  ASSERT_EQ(3, m.pop(3));
  ASSERT_EQ(3, m.pop(3));

  ASSERT_EQ(1, m.peek(1));
  ASSERT_EQ(2, m.peek(2));
  ASSERT_EQ(3, m.peek(3));
  // m.print();

  m.push (2, 22);
  m.push (2, 22);

  ASSERT_EQ(22, m.peek(2));
  // m.print();

}
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}