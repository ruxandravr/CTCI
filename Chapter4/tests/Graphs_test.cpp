#include "../src/Graphs.h"
#include <gtest/gtest.h>

TEST(Graphs, Inserting)
{
  Graph g(7, 6);
  g.insertUndirected(1, 6);
  g.insertUndirected(2, 5);
  g.insertUndirected(6, 3);
  g.insertUndirected(3, 5);
  g.insertUndirected(4, 6);
  g.insertUndirected(5, 6);


  ASSERT_EQ(true, g.isPath(1, 2));
  ASSERT_EQ(true, g.isPath(1, 5));
  ASSERT_EQ(true, g.isPath(4 ,5));
  ASSERT_EQ(false , g.isPath(1, 7));

}

TEST(Graphs, Topsort)
{
  Graph g(6, 5);
  g.insertDirected(1, 4);
  g.insertDirected(4, 3);
  g.insertDirected(2, 4);
  g.insertDirected(6, 1);
  g.insertDirected(6, 2);

  g.sort();
  std::vector<int> result = {6, 5, 2, 1, 4, 3};
  ASSERT_EQ(result, g.getTopsort());
}

TEST(Graphs, KhanTopsort)
{
  Graph g(6, 5);
  g.insertDirected(1, 4);
  g.insertDirected(4, 3);
  g.insertDirected(2, 4);
  g.insertDirected(6, 1);
  g.insertDirected(6, 2);

  g.khan();
  std::vector<int> result = {5, 6, 1, 2, 4, 3};
  ASSERT_EQ(result, g.getTopsort());
}
/* MORE TO COME */

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}