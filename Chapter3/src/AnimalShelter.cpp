#include "AnimalShelter.h"

void AnimalShelter::enqueue(Animal animal)
{
  if (animal.isCat()) {
    catQueue.push_back(animal);
  } else {
    dogQueue.push_back(animal);
  }
}

Animal AnimalShelter::dequeueCat()
{
  Animal cat = catQueue.front();
  catQueue.pop_front();
  return cat;
}

Animal AnimalShelter::dequeueDog()
{
  Animal dog = dogQueue.front();
  dogQueue.pop_front();
  return dog;
}

Animal AnimalShelter::dequeueAny()
{
  if (catQueue.isEmpty() || dogQueue.front().getTimestamp() > catQueue.front().getTimestamp()) {
    return dequeueDog();
  }

  return dequeueCat();
}