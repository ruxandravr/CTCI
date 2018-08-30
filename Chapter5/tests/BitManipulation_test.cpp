#include "../src/BitManipulation.h"
#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(BitManipulation, ZecimalBinary)
{
  ASSERT_EQ("01",BitManipulation::zecimalBinary(0.25));
}

TEST(BitManipulation, BitFlip)
{
  ASSERT_EQ(9, BitManipulation::bitFlip(4059));
  ASSERT_EQ(8, BitManipulation::bitFlip(1775));
}

TEST(BitManipulation, BitFlip_v2)
{
  ASSERT_EQ(9, BitManipulation::bitFlip_v2(4059));
  ASSERT_EQ(8, BitManipulation::bitFlip_v2(1775));
}

TEST(BitManipulation, GetNext)
{
  ASSERT_EQ(74, BitManipulation::getNext(73));
  ASSERT_EQ(76, BitManipulation::getNext(74));
  ASSERT_EQ(79, BitManipulation::getNext(62));
  ASSERT_EQ(76, BitManipulation::getNext(74));
  ASSERT_EQ(87, BitManipulation::getNext(79));
  ASSERT_EQ(82, BitManipulation::getNext(81));
}

TEST(BitManipulation, GetPrevious)
{
  ASSERT_EQ(73, BitManipulation::getPrevious(74));
  ASSERT_EQ(74, BitManipulation::getPrevious(76));
  ASSERT_EQ(62, BitManipulation::getPrevious(79));
  ASSERT_EQ(74, BitManipulation::getPrevious(76));
  ASSERT_EQ(79, BitManipulation::getPrevious(87));
  ASSERT_EQ(81, BitManipulation::getPrevious(82));
}

TEST(BitManipulation, Conversion)
{
  ASSERT_EQ(2, BitManipulation::conversion(29, 15));
}

TEST(BitManipulation, BitwiseSwap)
{
  ASSERT_EQ(2392, BitManipulation::pairwiseSwap(1700));
}

TEST(BitManipulation, Drawline)
{
  std::vector<uint8_t> screen = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  BitManipulation::drawLine(screen, 24, 25, 40, 1);

  // for (int i = 0; i < screen.size(); ++i) {
  //   BitManipulation::printBits(screen[i]);
  // }

  ASSERT_EQ(127, (int) screen[6]);
  ASSERT_EQ(255, (int) screen[7]);

}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}