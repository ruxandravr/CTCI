#include "BitManipulation.h"

/* Helper function to print the number in binary. */
void BitManipulation::printBits(int number)
{
  for (int i = 16; i >= 0; --i) {
    int bit  =  number & (1 << i) ? 1 : 0;
    std::cout << bit << " ";
  }
  std::cout << "\n";
}

/* Helper function to print a byte in binary. */
void BitManipulation::printBits(uint8_t number)
{
  for (int i = 7; i >= 0; --i) {
    int bit  =  number & (1 << i) ? 1 : 0;
    std::cout << bit << " ";
  }
  std::cout << "\n";
}

/* Insert m number into n from position i to j. */
int BitManipulation::insertion(int n, int m, int i, int j)
{
  int mask = -1;
  for (int k = i; k <= j; k++) {
    mask ^= (1 << k);
  }
  return (n & mask) | (m << i) ;
}

/* Represent a double number in binary by multiplying by 2 and checking when
the number becomes greater than 1. */
std::string BitManipulation::zecimalBinary(double n)
{
  if (n > 1 || n < 0) {
    std::cout << "ERROR\n";
    return "";
  }

  std::string result = "";
  while (n > 0) {
    if (result.size() > 32) {
      std::cout << "ERROR\n";  // too large number
      return result;
    }

    n *= 2;
    if (n >= 1) {
      result += "1";  // if number greater than 1, print 1
      n -= 1;
    } else {
      result += "0";  // else print 0
    }
  }

  return result;
}

/* Helper function that calculates the longest sequence of 1 bits in an integer n.*/
int BitManipulation::longestOneSeq(int n)
{
  int max = 0, curr = 0;
  for (int i = n; i > 0; i = i >> 1) {
    if (i & 1) {
      curr++;
      if (curr > max) {
        max = curr;
      }
    } else {
      curr = 0;
    }
  }
  return max;
}

/* Brute force: flip all the bits and check the maximum length of 1s from
all the posibilites.  */
int BitManipulation::bitFlip(int n)
{
  int max = 0, curr = 0;
  for (int i = 0; i < 32; ++i) {
    if ((n & (1 << i)) == 0) {
      curr = longestOneSeq(n | (1 << i));
      if (curr > max) {
        max = curr;
      }
    }
  }
  return max;
}


/* Keep track of the current 1s sequence and the previous one because when
we flip a bit we can join the two. */
int BitManipulation::bitFlip_v2(int n)
{
  int previousSeq = 0, currentSeq = 0, maxSeq = 0;
  for (int i = 0; i < 32; i++) {
    if ((n & (1 << i)) > 0) {
      currentSeq++;  // we found a one, so the currentSeq is bigger
    } else {
      /* If the next bit is also 0, the previous 1s sequence is empty, else
      the previous 1s sequence is the current one, and the current one is
      a new one. */
      previousSeq =  (n & (1 << (i + 1))) == 0 ? 0 : currentSeq;
      currentSeq = 0;
    }

    /* Update maximum. */
    maxSeq = (previousSeq + currentSeq + 1) > maxSeq ?
             (previousSeq + currentSeq + 1) : maxSeq;
  }
  return maxSeq;
}

/* The the next greater number than the given one with the same number of one
bits in it. */
int BitManipulation::getNext(int n)
{
  int c0 = 0, c1 = 0;

  /* Count the zeros and the ones. */
  int copy = n;
  while  ((copy & 1) == 0 && (copy != 0)) {
    c0++;
    copy = (copy >> 1);
  }
  while  ((copy & 1) == 1) {
    c1++;
    copy = (copy >> 1);
  }

  if (c0 + c1 > 31) {
    std::cout << "ERROR\n";
  }

  /* Set the first zero found next to a one to 1. */
  n |= (1 << (c0 + c1));
  /* Clear all the bits which follow the previous one. */
  n &= (-1 << (c0 + c1));
  /* Insert all the other ones found at the beggining. */
  n |= ~ (-1 << (c1 - 1));

  return n;
}

/* The the next smaller number than the given one with the same number of one
bits in it. */
int BitManipulation::getPrevious(int n)
{
  int c0 = 0, c1 = 0;

  int copy = n;
  while  ((copy & 1) == 1 && (copy != 0)) {
    c1++;
    copy = (copy >> 1);
  }
  while  ((copy & 1) == 0) {
    c0++;
    copy = (copy >> 1);
  }

  if (c0 + c1 > 31) {
    std::cout << "ERROR\n";
  }

  /* Clear the first one followed by a zero. */
  n ^= (1 << (c0 + c1));
  /* Clear all the bits after the previous one. */
  n &= (-1 << (c0 + c1));
  /* Insert the other ones found after the cleared one. */
  n |= ~ (-1 << (c1 + 1)) << (c0 - 1);

  return n;
}

/* Return the number of bits we need to flip to transform n to m by counting
the number of 1 bits in the xor between n and m. n = n & (n - 1) clears the
least significant bit.  */
int BitManipulation::conversion(int n, int m)
{
  int count = 0;
  for (int x = n ^ m; x > 0; x = x & (x - 1)) {
    count++;
  }
  return count;
}

/* Form the two components, shift them, and then combine them. */
int BitManipulation::pairwiseSwap(int n)
{
  return ((n & 0x55555555) << 1) | ((n & 0xaaaaaaaa) >> 1);
}

/* Draw a line from (x1, y) to (x2, y). */
void BitManipulation::drawLine(std::vector<uint8_t> &arr, int width, int x1, int x2, int y)
{
  int firstOffset = x1 % 8;
  int firstFullByte = x1 / 8;

  int lastOffset = x2 % 8;
  int lastFullByte = x2 / 8;

  /* Create masks for first bytes.*/
  uint8_t firstMask = (uint8_t) (0xFF >> firstOffset);
  uint8_t lastMask =  (uint8_t) (~( 0xFF >> (lastOffset + 1)));

  /* If we are in the same byte, the mask should be a combination of the 2. */
  if (firstFullByte == lastFullByte) {
    arr[(width / 8) * y + firstFullByte] |= (firstMask & lastMask);
  } else {
    /* Update the first byte. */
    if (firstOffset != 0) {
      arr[(width / 8) * y + firstFullByte] |= firstMask;
    }
    /* Update the last byte. */
    if (lastOffset != 0) {
      arr[(width / 8) * y + lastFullByte] |= lastMask;
    }
  }

  /* Check the limits for the full bytes. */
  if (firstOffset != 0) {
    firstFullByte++;
  }

  if (lastOffset != 7) {
    lastFullByte--;
  }

  /* Update the full bytes. */
  for (int i = firstFullByte; i <= lastFullByte; ++i) {
    arr[(width / 8) * y + i] = 0xFF;
  }
}

