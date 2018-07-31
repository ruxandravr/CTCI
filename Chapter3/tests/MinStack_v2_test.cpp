#include "../src/MinStack_v2.h"
#include <gtest/gtest.h>

TEST(MinStack_v2Test, IsEmpty)
{
  MinStack_v2<int> S;
  ASSERT_EQ(true, S.isEmpty());
}

TEST(MinStack_v2Test, IsNotEmpty)
{
  MinStack_v2<int> S1;
  S1.push(2);
  ASSERT_EQ(false, S1.isEmpty());

}

TEST(MinStack_v2Test, PushAndTop)
{
  MinStack_v2<int> S1;
  S1.push(2);
  ASSERT_EQ(2, S1.top());

  S1.push(3);
  ASSERT_EQ(3, S1.top());

  S1.push(4);
  S1.push(5);
  ASSERT_EQ(5, S1.top());

}
TEST(MinStack_v2Test, Pop)
{
  MinStack_v2<int> S1;
  bool result = S1.pop();
  ASSERT_EQ(false, result);

  S1.push(2);
  result = S1.pop();
  ASSERT_EQ(true, result);
  ASSERT_EQ(true, S1.isEmpty());

  S1.push(3);
  S1.push(4);
  S1.push(5);
  ASSERT_EQ(false, S1.isEmpty());

  result = S1.pop();
  ASSERT_EQ(true, result);
  ASSERT_EQ(4, S1.top());

}

TEST(MinStack_v2, Min)
{
  MinStack_v2<int> s1;
  s1.push(1);
  s1.push(5);

  ASSERT_EQ(1, s1.getMin());

  s1.push(-5);
  ASSERT_EQ(-5, s1.getMin());

  s1.pop();
  ASSERT_EQ(1, s1.getMin());

  s1.push(0);
  s1.push(0);
  s1.push(-2);
  s1.pop();
  s1.pop();
  ASSERT_EQ(0, s1.getMin());



}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}