#ifndef CTCI_ANIMAL_SHELTER
#define CTCI_ANIMAL_SHELTER

#include <string>
#include "../../Data_Structures/src/Queue.h"

class Animal
{
private:
  bool dog;
  bool cat;
  int timestamp;
public:
  Animal()
  {

  }
  Animal(std::string name, int timestamp)
  {
    if (name == "dog") {
      dog = true;
      cat = false;
    } else {
      cat = true;
      dog = false;
    }
  }

  bool isDog()
  {
    return dog;
  }

  bool isCat()
  {
    return cat;
  }

  int getTimestamp()
  {
    return timestamp;
  }

  std::string getName()
  {
    if (dog) {
      return "dog";
    }
    return "cat";
  }
};

class AnimalShelter
{
private:
  Queue<Animal> dogQueue;
  Queue<Animal> catQueue;

public:
  void enqueue(Animal animal);
  Animal dequeueAny();
  Animal dequeueCat();
  Animal dequeueDog();
};

#endif