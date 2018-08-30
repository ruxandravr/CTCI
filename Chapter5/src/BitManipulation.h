#ifndef CTCI_BIT_MANIPULATION_H
#define CTCI_BIT_MANIPULATION_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

class BitManipulation
{
private:
  static int longestOneSeq(int n);

public:
  static void printBits(int number);
  static void printBits(uint8_t number);
  static int insertion(int n, int m, int i, int j);
  static std::string zecimalBinary(double n);
  static int bitFlip(int n);
  static int bitFlip_v2(int n);
  static int getNext(int n);
  static int getPrevious(int n);
  static int conversion(int n, int m);
  static int pairwiseSwap(int n);
  static void drawLine(std::vector<uint8_t> &arr, int width, int x1, int x2,
                       int y);


};

#endif