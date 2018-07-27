#include "../src/Stack.h"
#include <gtest/gtest.h>

#include <string>

TEST(StackTest, IsEmpty)
{
  Stack<int> S;
  ASSERT_EQ(true, S.isEmpty());
}

TEST(StackTest, IsNotEmpty)
{
  Stack<int> S1;
  S1.push(2);
  ASSERT_EQ(false, S1.isEmpty());

}

TEST(StackTest, PushAndTop)
{
  Stack<int> S1;
  S1.push(2);
  ASSERT_EQ(2, S1.top());

  S1.push(3);
  ASSERT_EQ(3, S1.top());

  S1.push(4);
  S1.push(5);
  ASSERT_EQ(5, S1.top());

}
TEST(StackTest, Pop)
{
  Stack<int> S1;
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
TEST(StacktTest, Equals)
{
  Stack<int> S1, S2;
  S1.push(1);
  S1.push(2);
  S1.push(3);
  S1.pop();
  S2.push(1);
  S2.push(2);
  S2.push(3);
  S2.pop();
  ASSERT_EQ(true, S1.equals(S2));
}

TEST(StackTest, CopyConstructorAssignmentOperator)
{
  Stack<std::string> S1;
  S1.push("first");
  S1.push("middle");
  S1.push("last");
  Stack<std::string> S2(S1);
  ASSERT_EQ(true, S1.equals(S2));
  Stack<std::string> S3 = S1;
  ASSERT_EQ(true, S1.equals(S3));
}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}