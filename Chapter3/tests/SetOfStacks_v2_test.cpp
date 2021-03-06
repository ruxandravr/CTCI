#include "../src/SetOfStacks_v2.h"
#include <gtest/gtest.h>

TEST(SetOfStacksTest, IsEmpty)
{
  SetOfStacks<int> S(2);
  ASSERT_EQ(true, S.isEmpty());
}

TEST(SetOfStacksTest, IsNotEmpty)
{
  SetOfStacks<int> S1(2);
  S1.push(2);
  ASSERT_EQ(false, S1.isEmpty());

}

TEST(SetOfStacksTest, PushAndTop)
{
  SetOfStacks<int> S1(2);
  S1.push(2);
  ASSERT_EQ(2, S1.top());

  S1.push(3);
  ASSERT_EQ(3, S1.top());

  S1.push(4);
  S1.push(5);
  ASSERT_EQ(5, S1.top());
  // S1.print();

}
TEST(SetOfStacksTest, Pop)
{
  SetOfStacks<int> S1(2);
  bool result = S1.pop();
  ASSERT_EQ(false, result);

  S1.push(2);
  result = S1.pop();
  ASSERT_EQ(true, result);
  ASSERT_EQ(true, S1.isEmpty());

  S1.push(3);
  S1.push(4);
  S1.push(5);
  // S1.print();
  ASSERT_EQ(false, S1.isEmpty());

  result = S1.pop();
  ASSERT_EQ(true, result);
  ASSERT_EQ(4, S1.top());
  // S1.print();
}

TEST(SetOfStacksTest, PopAtIndex)
{
  SetOfStacks<int> S1(2);
  bool result = S1.popAtIndex(1);
  ASSERT_EQ(false, result);

  S1.push(2);
  result = S1.popAtIndex(2);
  ASSERT_EQ(false, result);

  result = S1.popAtIndex(1);
  ASSERT_EQ(true, result);

  ASSERT_EQ(true, S1.isEmpty());

  S1.push(3);
  S1.push(4);
  S1.push(5);
  // S1.print();
  ASSERT_EQ(false, S1.isEmpty());

  result = S1.popAtIndex(1);
  ASSERT_EQ(true, result);
  ASSERT_EQ(5, S1.top());

  S1.push(6);
  S1.push(7);
  S1.push(8);

  // S1.print();
  result = S1.popAtIndex(1);
  ASSERT_EQ(8, S1.top());

  result = S1.popAtIndex(2);
  ASSERT_EQ(7, S1.top());
}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}