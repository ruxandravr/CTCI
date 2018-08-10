#include "../src/MinHeap.h"
#include <gtest/gtest.h>

TEST(MinHeapTest, AddHeap)
{
  MinHeap<int> s;
  s.insert(10);
  s.insert(7);
  s.insert(1);
  s.insert(2);

  std::vector<int> result = {1, 2, 7, 10};
  ASSERT_EQ(result, s.getHeap());
  s.extractMin();
}

TEST(MinHeapTest, ExtractHeap)
{
  MinHeap<int> s;
  s.insert(10);
  s.insert(7);
  s.insert(1);
  s.insert(2);

  s.extractMin();
  std::vector<int> result = {2, 10, 7};
  ASSERT_EQ(result, s.getHeap());
}
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}