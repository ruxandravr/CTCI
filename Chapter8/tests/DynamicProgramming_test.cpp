#include "../src/DynamicProgramming.h"
#include <gtest/gtest.h>

#include <vector>

TEST(DynamicProgramming, TripleStep)
{
  ASSERT_EQ(4, DP::tripleStep(3));
  ASSERT_EQ(13, DP::tripleStep(5));
}

TEST(DynamicProgramming, GetPath)
{
  std::vector<std::vector<int> > maze = { {0,1,0,0},
    {0,0,1,0},
    {1,0,0,1},
    {0,0,0,0}
  };
  std::vector<std::pair<int, int> > path;
  path = DP::getPath(maze);
  std::vector<std::pair<int, int> > result = { {0, 0}, {1, 0}, {1, 1}, {2, 1},
    {3, 1}, {3, 2}, {3, 3}
  };

  ASSERT_EQ(result, path);
}

TEST(DynamicProgramming, MagicIndex)
{
  std::vector<int> v = {-2, -1, 0, 1, 2, 3, 7, 7, 7, 7, 11, 12, 13};
  ASSERT_EQ(7, DP::magicIndex(v));
}

TEST(DynamicProgramming, Subsets)
{
  std::vector<int> v = {1, 2, 3, 4};
  ASSERT_EQ(16, DP::subsets(v));
  ASSERT_EQ(16, DP::subsets_2(v));

}

TEST(DynamicProgramming, Multiply)
{
  ASSERT_EQ(26304, DP::recursiveMultiply(137, 192));
  ASSERT_EQ(2008781808, DP::recursiveMultiply(443244, 4532));
  ASSERT_EQ(2008324971, DP::recursiveMultiply(443241, 4531));

}

TEST(DynamicProgramming, TowersOfHanoi)
{
  int n = 10;
  std::stack<int> expected;
  for (int i = 0; i < n; ++i) {
    expected.push(n - i);
  }

  std::stack<int> result =  DP::towersOfHanoi(n);

  for (int i = 0; i < n; ++i) {
    ASSERT_EQ(result.top(), expected.top());
    expected.pop();
    result.pop();
  }
}

TEST(DynamicProgramming, PERMS)
{
  std::vector<int> domain = {1, 2, 3, 4};
  ASSERT_EQ(24, DP::permutations_back(domain));
}

TEST(DynamicProgramming, PERMS2)
{
  std::string s = "1234";
  ASSERT_EQ(24, DP::permutations_v1(s));
}

TEST(DynamicProgramming, PERMS3)
{
  std::string s = "1234";
  ASSERT_EQ(24, DP::permutations_v2(s));
}

TEST(DynamicProgramming, PERMS_DUPS)
{
  std::string s = "1234";
  s[2]  = 'a';
  ASSERT_EQ(24, DP::permutation_dups(s));
}

TEST(DynamicProgramming, Parens)
{
  ASSERT_EQ(5, DP::parens(3));

}

TEST(DynamicProgramming, Parens2)
{
  ASSERT_EQ(5, DP::parens2(3));

}

TEST(DynamicProgramming, PaintFill)
{
  std::vector<std::vector<int> > canvas = {{1, 0, 0, 1, 1},
    {1, 1, 0, 1, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1}
  };

  std::vector<std::vector<int> > result = {{1, 2, 2, 1, 1},
    {1, 1, 2, 1, 1},
    {1, 2, 2, 1, 1},
    {1, 1, 1, 0, 1}
  };


  DP::paintFill(canvas, 2, 2,0, 2);
  ASSERT_EQ(canvas, result);
}

TEST(DynamicProgramming, Coins)
{
  ASSERT_EQ(DP::coins_v1(55), DP::coins_v2(55));
}


TEST(DynamicProgramming, Queens)
{
  /* for checking unocmment the printing section in src/DynamicPrograming.cpp*/
  DP::queens(4);
}

TEST(DynamicProgramming, Boolean)
{
  ASSERT_EQ(10, DP::booleanExpression("0&0&0&1^1|0", true));
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}