#include "../src/Node.h"
#include <gtest/gtest.h>

TEST(NodeTest, CheckStaticValueTest)
{
  Node<int> node(3);
  ASSERT_EQ(3, node.value);
}

TEST(NodeTest, LinkNodesTest)
{
  Node<int> *n1 = new Node<int>(2);
  Node<int> *n2 = new Node<int>(3);

  n1->next = n2;
  n2->prev = n1;

  /* Check associativity */
  ASSERT_EQ(n1->value, n2->prev->value);
  ASSERT_EQ(n2->value, n1->next->value);

  /* Check reflexivity */
  ASSERT_EQ(n1->value, n1->next->prev->value);
  ASSERT_EQ(n2->value, n2->prev->next->value);

  delete n1;
  delete n2;
}

/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}