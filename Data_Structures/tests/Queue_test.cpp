#include "../src/Queue.h"
#include <gtest/gtest.h>


#include <string>

TEST(QueueTest, IsEmpty)
{
  Queue<int> S;
  ASSERT_EQ(true, S.isEmpty());
}

TEST(QueueTest, IsNotEmpty)
{
  Queue<int> Q1;
  Q1.push_back(2);
  ASSERT_EQ(false, Q1.isEmpty());

}

TEST(QueueTest, push_backAndfront)
{
  Queue<int> Q1;
  Q1.push_back(2);
  ASSERT_EQ(2, Q1.front());

  Q1.push_back(3);
  ASSERT_EQ(2, Q1.front());

  Q1.push_back(4);
  Q1.push_back(5);
  ASSERT_EQ(2, Q1.front());

}
TEST(QueueTest, pop_front)
{
  Queue<int> Q1;
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

TEST(QueueTest, Equals)
{
  Queue<int> Q1, Q2;
  Q1.push_back(1);
  Q1.push_back(2);
  Q1.push_back(3);
  Q1.pop_front();
  Q2.push_back(1);
  Q2.push_back(2);
  Q2.push_back(3);
  Q2.pop_front();
  ASSERT_EQ(true, Q1.equals(Q2));
}

TEST(QueueTest, CopyConstructorAssignmenfronterator)
{
  Queue<std::string> Q1;
  Q1.push_back("first");
  Q1.push_back("middle");
  Q1.push_back("last");
  Queue<std::string> Q2(Q1);
  ASSERT_EQ(true, Q1.equals(Q2));
  Queue<std::string> Q3 = Q1;
  Q1.pop_front();
  Q3.pop_front();
  ASSERT_EQ(true, Q1.equals(Q3));
}

/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}