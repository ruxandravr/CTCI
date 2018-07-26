#include "../src/SNode.h"
#include <gtest/gtest.h>

TEST(SSNodeTest, CheckStaticValueTest)
{
  SNode<int> node(3);
  ASSERT_EQ(3, node.value);
}

TEST(SNodeTest, LinkSNodesTest)
{
  SNode<int> *n1 = new SNode<int>(2);
  SNode<int> *n2 = new SNode<int>(3);

  n1->next = n2;

  /* Check associativity */
  ASSERT_EQ(n2->value, n1->next->value);

  delete n1;
  delete n2;
}

TEST(SNodeTest, Intersection)
{
  SNode<int> *n1 = new SNode<int>(1);
  SNode<int> *n2 = new SNode<int>(2);
  SNode<int> *n3 = new SNode<int>(3);
  SNode<int> *n4 = new SNode<int>(4);
  SNode<int> *n5 = new SNode<int>(5);

  n1->next = n2;
  n2->next = n3;

  n5->next = n4;

  SNode<int> *result = SNode<int>::intersect(n1, n5);
  ASSERT_EQ(true, result == nullptr);

  /* Intersect the lists. */
  n4->next = n2;
  result = SNode<int>::intersect(n1, n5);
  if (result != nullptr) {
    ASSERT_EQ(2, result->value);
  }

}


TEST(SNodeTest, detectLoop)
{
  SNode<int> *n1 = new SNode<int>(1);
  SNode<int> *n2 = new SNode<int>(2);
  SNode<int> *n3 = new SNode<int>(3);

  n1->next = n2;
  n2->next = n3;
  n3->next = n2;

  SNode<int> *result = SNode<int>::loop(n1);
  if (result != nullptr) {
    ASSERT_EQ(2, result->value);
  }

}



/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}