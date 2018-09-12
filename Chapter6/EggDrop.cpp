#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>


/* maxSteps * (maxSteps - 1) / 2  = n*/
int maxSteps(int n)
{
  return sqrt(2 * n);
}

void love()
{
  for (unsigned int i = 100; i > 0; --i) {
    std::cout << "I love you\n";
  }
}

int main ()
{
  srand((unsigned)time(0));
  int level = (rand()%100)+1;
  std::cout << "Level: " << level << "\n";

  int step = maxSteps(100);
  int totalSteps = 0, lastLevel = 1;

  for (int i = step; i <= 100; i = i + step) {
    totalSteps++;
    if (level < i) {
      for (int j = lastLevel; j < i; j++) {
        if (j != level) {
          totalSteps++;
        } else {
          break;
        }
      }
      break;
    } else if (level == i) {
      break;
    } else {
      lastLevel = i;
      step--;
    }
  }
  love();
  std::cout << "TotalStepsMade: " << totalSteps << "\n";
  return 0;
}