#include "../src/Trie.h"
#include <gtest/gtest.h>

TEST(TrieTest, InsertAndHas)
{
  Trie t;
  t.insert("apple");
  t.insert("app");
  t.insert("applm");
  t.insert("addle");
  t.insert("add");
  ASSERT_EQ(false, t.hasWord("apps"));
  ASSERT_EQ(true, t.hasWord("app"));

}
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}