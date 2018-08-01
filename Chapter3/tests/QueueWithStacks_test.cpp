#include "../src/QueueWithStacks.h"
#include <gtest/gtest.h>


#include <string>

TEST(QueueWithStacksTest, IsEmpty)
{
  QueueWithStacks<int> S;
  ASSERT_EQ(true, S.isEmpty());
}

TEST(QueueWithStacksTest, IsNotEmpty)
{
  QueueWithStacks<int> Q1;
  Q1.push_back(2);
  ASSERT_EQ(false, Q1.isEmpty());

}

TEST(QueueWithStacksTest, push_backAndfront)
{
  QueueWithStacks<int> Q1;
  Q1.push_back(2);
  ASSERT_EQ(2, Q1.front());

  Q1.push_back(3);
  ASSERT_EQ(2, Q1.front());

  Q1.push_back(4);
  Q1.push_back(5);
  ASSERT_EQ(2, Q1.front());

}
TEST(QueueWithStacksTest, pop_front)
{
  QueueWithStacks<int> Q1;
  bool result = Q1.pop_front();
  ASSERT_EQ(false, result);

  Q1.push_back(2);
  result = Q1.pop_front();
  ASSERT_EQ(true, result);
  ASSERT_EQ(true, Q1.isEmpty());

  Q1.push_back(3);
  Q1.push_back(4);
  Q1.push_back(5);
  ASSERT_EQ(false, Q1.isEmpty());

  result = Q1.pop_front();
  ASSERT_EQ(true, result);
  ASSERT_EQ(4, Q1.front());

}

/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}