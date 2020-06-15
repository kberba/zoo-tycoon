/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Header for Zoo class

Zoo class
- Private
    - Pointers to dynamic arrays
    - Int variables for count and size of animal arrays
- Public
    - Setters
        - Set sizes and counts for each animal
    - Getters
        - Pointers for each animal
        - Get sizes and counts for each animal
    - Other functions
        - Resize array function
            - resize the dynamic array by doubling the starting capacity to hold more animals
        - Add animal function
        - Remove animal function
    - Default constructor
    - Destructor

    NOTES:

        Age:
        Adult if age >= 3 days
        Baby if age < 3 days
        ** babies start at 0 days old
        ** newly bought animals start at 1 day old
        *** Dead animals will be set -1 days old

*********************************************************************/

// include guards
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"

// enum declaration
enum ZooAnimalType { TIGER = 1, PENGUIN, TURTLE }; // to be used in add/remove animal functions

// Zoo class declaration
class Zoo {
  private:
    // pointers to dynamic arrays
    Animal* tigersArray;
    Animal* penguinsArray;
    Animal* turtlesArray;

    // int variables for count and size of animal arrays
    int tigerCount;
    int penguinCount;
    int turtleCount;
    int sizeTiger;
    int sizePenguin;
    int sizeTurtle;

  public:
    // setters
    void setTigerCount(int);
    void setPenguinCount(int);
    void setTurtleCount(int);
    void setSizeTiger(int);
    void setSizePenguin(int);
    void setSizeTurtle(int);

    // getters
    Animal* getTigersArray();
    Animal* getPenguinsArray();
    Animal* getTurtlesArray();
    int getTigerCount();
    int getPenguinCount();
    int getTurtleCount();
    int getSizeTiger();
    int getSizePenguin();
    int getSizeTurtle();

    // other functions
    void resizeArray(Animal*, ZooAnimalType, int);
    void addAnimal(Animal*, ZooAnimalType, Animal, int, int);
    void removeAnimal(Animal*, int);

    // default constructor
    Zoo();

    // destructor
    ~Zoo();
};



#endif
