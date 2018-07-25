#include "../src/Entry.h"
#include <gtest/gtest.h>

TEST(EntryTest, StaticValue)
{
  Entry<int,std::string> Entry(3, "Ana");
  ASSERT_EQ(3, Entry.getKey());
  ASSERT_EQ("Ana", Entry.getValue());
}

TEST(EntryTest, AssignmentOperatorTest)
{
  Entry<std::string, int> e1("Ana", 10);
  Entry<std::string, int> e2 = e1;

  ASSERT_EQ(e1.getValue(), e2.getValue());
  ASSERT_EQ(e1.getKey(), e2.getKey());
}

TEST(EntryTest, CopyConstructor)
{
  Entry<std::string, int> e1("Ana", 10);
  Entry<std::string, int> e2(e1);

  ASSERT_EQ(e1.getValue(), e2.getValue());
  ASSERT_EQ(e1.getKey(), e2.getKey());
}

TEST(EntryTest, SetValue)
{
  Entry<std::string, int> e1("Ana", 10);
  e1.setValue(6);

  ASSERT_EQ(e1.getValue(), 6);
  ASSERT_EQ(e1.getKey(), "Ana");
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}