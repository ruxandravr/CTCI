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

/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}