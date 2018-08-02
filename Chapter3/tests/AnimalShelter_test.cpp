#include "../src/AnimalShelter.h"
#include <gtest/gtest.h>
#include <ctime>

TEST(AnimalShelter, Enqueue)
{
  AnimalShelter shelter;
  Animal c1("cat", std::time(NULL));
  shelter.enqueue(c1);
  Animal d1("dog", std::time(NULL));
  shelter.enqueue(d1);
  Animal d2("dog", std::time(NULL));
  shelter.enqueue(d2);
  Animal c2("cat", std::time(NULL));
  shelter.enqueue(c2);

  ASSERT_EQ("cat", shelter.dequeueAny().getName());
  ASSERT_EQ("cat", shelter.dequeueCat().getName());

  ASSERT_EQ("dog", shelter.dequeueAny().getName());
}
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}