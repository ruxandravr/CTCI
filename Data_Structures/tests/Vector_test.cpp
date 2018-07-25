#include "../src/Vector.h"
#include <gtest/gtest.h>

TEST(VectorTest, Empty)
{
  Vector<int> v(10);
  ASSERT_EQ(true, v.empty());
  v.pushBack(1);
  ASSERT_EQ(false, v.empty());

}

TEST(VectorTest, pushBack)
{
  Vector<std::string> v(100);
  v.pushBack("first");
  v.pushBack("second");
  v.pushBack("third");
  ASSERT_EQ("first", v[0]);
  ASSERT_EQ("second",v[1]);
  ASSERT_EQ("third", v[2]);
}

TEST(VectorTest, ConstructorWithInitialValue)
{
  Vector<int> v(10, 1);
  ASSERT_EQ(1, v[0]);
  ASSERT_EQ(1, v[1]);
  ASSERT_EQ(1, v[2]);
}


TEST(VectorTest, RemoveFirst)
{
  Vector<std::string> v(100);
  v.removeFirst();
  ASSERT_EQ(true, v.empty());
  v.pushBack("first");
  v.pushBack("second");
  v.pushBack("third");
  v.removeFirst();
  ASSERT_EQ("second", v[0]);
}

TEST(VectorTest, RemoveLast)
{
  Vector<std::string> v(100);
  v.removeLast();
  ASSERT_EQ(true, v.empty());
  v.pushBack("first");
  v.pushBack("second");
  v.pushBack("third");
  v.removeLast();
  v.pushBack("fourth");
  ASSERT_EQ("first", v[0]);
  ASSERT_EQ("second", v[1]);
  ASSERT_EQ("fourth", v[2]);
}

TEST(VectorTest, Equals)
{
  Vector<int> v1(10);
  Vector<int> v2(10);
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(3);
  v2.pushBack(1);
  v2.pushBack(2);
  v2.pushBack(3);
  ASSERT_EQ(true, v1.equals(v2));
}

TEST(VectorTest, CopyConstructorAssignmentOperator)
{
  Vector<std::string> v1(100);
  v1.pushBack("Last");
  v1.pushBack("Middle");
  v1.pushBack("First");
  Vector<std::string> v2(v1);
  ASSERT_EQ(true, v1.equals(v2));
  Vector<std::string> v3 = v1;
  ASSERT_EQ(true, v1.equals(v3));
}

TEST(VectorTest, RemoveFirstOccurence)
{
  Vector<int> v1(100);
  v1.removeFirstOccurence(1);
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(1);
  v1.pushBack(1);
  v1.pushBack(2);
  v1.removeFirstOccurence(1);
  ASSERT_EQ(2, v1[0]);
  ASSERT_EQ(1, v1[1]);
  ASSERT_EQ(1, v1[2]);
  ASSERT_EQ(2, v1[3]);

  v1.removeFirstOccurence(1);
  ASSERT_EQ(2, v1[0]);
  ASSERT_EQ(1, v1[1]);
  ASSERT_EQ(2, v1[2]);

  ASSERT_EQ(3, v1.getSize());
}

TEST(VectorTest, RemoveLastOccurence)
{
  Vector<int> v1(100);
  v1.removeLastOccurence(1);
  v1.pushBack(1);
  v1.pushBack(2);
  v1.pushBack(1);
  v1.pushBack(1);
  v1.pushBack(2);
  v1.removeLastOccurence(1);
  ASSERT_EQ(1, v1[0]);
  ASSERT_EQ(2, v1[1]);
  ASSERT_EQ(1, v1[2]);
  ASSERT_EQ(2, v1[3]);

  v1.removeLastOccurence(1);
  ASSERT_EQ(1, v1[0]);
  ASSERT_EQ(2, v1[1]);
  ASSERT_EQ(2, v1[2]);

  ASSERT_EQ(3, v1.getSize());
}

TEST(VectorTest, Resize)
{
  Vector<int> v1(100);
  v1.pushBack(1);
  v1.resize(200);
  ASSERT_EQ(200, v1.getCapacity());
  ASSERT_EQ(0, v1.getSize());

  v1.pushBack(2);
  ASSERT_EQ(200, v1.getCapacity());
  ASSERT_EQ(1, v1.getSize());

}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}