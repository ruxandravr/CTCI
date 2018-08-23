#include "../src/Graphs.h"
#include <gtest/gtest.h>

TEST(Graphs, Inserting)
{
  Graph g(7, 6);
  g.insert(1, 6);
  g.insert(2, 5);
  g.insert(6, 3);
  g.insert(3, 5);
  g.insert(4, 6);
  g.insert(5, 6);


  ASSERT_EQ(true, g.isPath(1, 2));
  ASSERT_EQ(true, g.isPath(1, 5));
  ASSERT_EQ(true, g.isPath(4 ,5));
  ASSERT_EQ(false , g.isPath(1, 7));

}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}