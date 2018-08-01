#include "../src/SortedStack.h"
#include <gtest/gtest.h>

TEST(SortedStackTest, IsEmpty)
{
  SortedStack<int> S;
  ASSERT_EQ(true, S.isEmpty());
}

TEST(SortedStackTest, IsNotEmpty)
{
  SortedStack<int> S1;
  S1.push(2);
  ASSERT_EQ(false, S1.isEmpty());
}


TEST(SortedStackTest, IsSorted)
{
  SortedStack<int> S1;
  S1.push(2);
  S1.push(5);
  S1.push(6);
  ASSERT_EQ(2, S1.top());

  S1.push(1);
  ASSERT_EQ(1, S1.top());

  S1.push(10);
  ASSERT_EQ(1, S1.top());

  S1.push(7);
  S1.push(532);

  S1.pop();
  S1.push(-1);
  ASSERT_EQ(-1, S1.top());

  S1.push(14);
  S1.pop();
  ASSERT_EQ(2, S1.top());




}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}