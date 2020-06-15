/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Zoo class - Zoo.cpp


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

#include "Zoo.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*********************************************************************
**
SETTERS
void Zoo::setTigerCount(int);
void Zoo::setPenguinCount(int);
void Zoo::setTurtleCount(int);
void Zoo::setSizeTiger(int);
void Zoo::setSizePenguin(int);
void Zoo::setSizeTurtle(int);

Description:
Setters for tigerCount, penguinCount, turtleCount, sizeTiger, sizePenguin,
and sizeTurtle.

Arguments:
Integers.

Restrictions:
Only integers.

Returns:
Does not return anything.

*********************************************************************/
void Zoo::setTigerCount(int animalCount) {
  tigerCount = animalCount;
}

void Zoo::setPenguinCount(int animalCount) {
  penguinCount = animalCount;
}

void Zoo::setTurtleCount(int animalCount) {
  turtleCount = animalCount;
}

void Zoo::setSizeTiger(int animalSize) {
  sizeTiger = animalSize;
}

void Zoo::setSizePenguin(int animalSize) {
  sizePenguin = animalSize;
}

void Zoo::setSizeTurtle(int animalSize) {
  sizeTurtle = animalSize;
}



/*********************************************************************
**
GETTERS
Animal* getTigersArray();
Animal* getPenguinsArray();
Animal* getTurtlesArray();
int Zoo::getTigerCount();
int Zoo::getPenguinCount();
int Zoo::getTurtleCount();
int Zoo::getSizeTiger();
int Zoo::getSizePenguin();
int Zoo::getSizeTurtle();

Description:
Getters for tigersArray, penguinsArray, turtlesArray, tigerCount, penguinCount,
turtleCount, sizeTiger, sizePenguin, and sizeTurtle.

Arguments:
None.

Restrictions:
Only integers.

Returns:
Returns integers and pointers of the variables.

*********************************************************************/
Animal* Zoo::getTigersArray() {
  return tigersArray;
}

Animal* Zoo::getPenguinsArray() {
  return penguinsArray;
}

Animal* Zoo::getTurtlesArray() {
  return turtlesArray;
}

int Zoo::getTigerCount() {
  return tigerCount;
}

int Zoo::getPenguinCount() {
  return penguinCount;
}

int Zoo::getTurtleCount() {
  return turtleCount;
}

int Zoo::getSizeTiger() {
  return sizeTiger;
}

int Zoo::getSizePenguin() {
  return sizePenguin;
}

int Zoo::getSizeTurtle() {
  return sizeTurtle;
}



/*********************************************************************
**
DEFAULT CONSTRUCTOR

*********************************************************************/
Zoo::Zoo() {
  // sets the initial animal counts to 0
  tigerCount = 0;
  penguinCount = 0;
  turtleCount = 0;

  // sets the initial animal array sizes to 10
  sizeTiger = 10;
  sizePenguin = 10;
  sizeTurtle = 10;

  // creates dynamic array for each type of animal
  tigersArray = new Animal[sizeTiger];
  penguinsArray = new Animal[sizePenguin];
  turtlesArray = new Animal[sizeTurtle];
}



/*********************************************************************
**
DESTRUCTOR

*********************************************************************/
/*
source(s):

https://stackoverflow.com/questions/7104889/how-to-properly-define-destructor

https://www.geeksforgeeks.org/destructors-c/

*/
Zoo::~Zoo() {
  // frees dynamically allocated memory
  delete[] tigersArray;
  delete[] penguinsArray;
  delete[] turtlesArray;
}



/*********************************************************************
**
RESIZE ARRAY FUNCTION
void Zoo::resizeArray(Animal* oldArray, ZooAnimalType zooAnimal, int arraySize)

Description:
When more animals are added to the array and exceeds the previous capacity
of the array, this function resizes the dynamic array by doubling the
starting capacity to hold more animals. The function iterates through the array,
doubles the previous arraySize, creates a new bigger array, copies the old
values to the new array, frees the memory of the old array, and then finally
points to the new array.

Arguments:
Animal array, and integer array size.

Restrictions:
Must be an array, and an integer.

Returns:
Does not return anything.

*********************************************************************/
/*
source(s):

http://www.fredosaurus.com/notes-cpp/newdelete/55dynexample.html

https://stackoverflow.com/questions/7031326/what-is-the-difference-between-prefix-and-postfix-operators

https://stackoverflow.com/questions/33523585/how-do-sizeofarr-sizeofarr0-work

*/
void Zoo::resizeArray(Animal* oldArray, ZooAnimalType zooAnimal, int arraySize) {
  // double the previous size of the array
  arraySize *= 2;

  // create a new bigger array
  Animal* newArray = new Animal[arraySize];

  // copy the old values to new array
  for(int i = 0; i < sizeof(oldArray) / sizeof(oldArray[0]); i++) {
    newArray[i] = oldArray[i];
  }

  // depending on what animal it is, sets the new array size
  if (zooAnimal == TIGER) {
    // sets new array size for tiger array
    setSizeTiger(arraySize);
  } else if (zooAnimal == PENGUIN) {
    // sets new array size for penguin array
    setSizePenguin(arraySize);
  } else {
    // sets new array size for turtle array
    setSizeTurtle(arraySize);
  }

  // free dynamically allocated memory of the old array
  delete[] oldArray;

  // points to the new array
  oldArray = newArray;


  // // for testing!!
  // cout << "Array resized!!" << endl;

}


/*********************************************************************
**
ADD ANIMAL FUNCTION
void Zoo::addAnimal(Animal* animalArray, ZooAnimalType zooAnimal, Animal animalObj, int numAnimalsToAdd, int animalArraySize)

Description:
Adds animal to the animal count and array.

Arguments:
Animal* animal array, enum animal, Animal object, integer number of animals to add, and integer animal array size.

Restrictions:
Animal pointer, zoo animal type enum, and integers.

Returns:
Does not return anything.

*********************************************************************/
void Zoo::addAnimal(Animal* animalArray, ZooAnimalType zooAnimal, Animal animalObj, int numAnimalsToAdd, int animalArraySize) {
  int animalCount;

  // based on which animal, it will add to the total animal count
  if (zooAnimal == TIGER) {
    // gets current tiger count for placement of tiger obj in array
    animalCount = this->getTigerCount();

    // get current tiger count and add the amount of animals to be added to get the new tiger count
    int newTigerCount = this->getTigerCount() + numAnimalsToAdd;

    // check to see if the new tiger count is more than the array size (thus will need to be resized)
    if (newTigerCount >= animalArraySize) {
      // resize the tiger array (also updates tiger array size )
      resizeArray(animalArray, zooAnimal, animalArraySize);
    }

    // if the number of tigers to be added is greater than 1
    if (numAnimalsToAdd > 1) {
      // keep adding tiger objects to array equal to the amount asked for
      for (int i = 0; i < numAnimalsToAdd; i++) {
        // add tiger obj to array
        animalArray[animalCount + i] = animalObj;
      }
    } else {  // for just one tiger to be added to array
      // add tiger obj to array
      animalArray[animalCount] = animalObj;
    }


    // set the new amount to the total tiger count
    this->setTigerCount(newTigerCount);

    // // TESTING !!!
    // animalCount = this->getTigerCount();
    // cout << "TESTING: new tiger count after using addAnimal function is --> " << animalCount << endl;

  } else if (zooAnimal == PENGUIN) {
      // gets current penguin count for placement of penguin obj in array
      animalCount = this->getPenguinCount();

      // get current penguin count and add the amount of animals to be added to get the new penguin count
      int newPenguinCount = this->getPenguinCount() + numAnimalsToAdd;

      // check to see if the new penguin count is more than the array size (thus will need to be resized)
      if (newPenguinCount >= animalArraySize) {
        // resize the penguin array (also updates penguin array size )
        resizeArray(animalArray, zooAnimal, animalArraySize);
      }

      // if the number of penguins to be added is greater than 1
      if (numAnimalsToAdd > 1) {
        // keep adding penguin objects to array equal to the amount asked for
        for (int i = 0; i < numAnimalsToAdd; i++) {
          // add penguin obj to array
          animalArray[animalCount + i] = animalObj;
        }
      } else {  // for just one penguin to be added to array
        // add penguin obj to array
        animalArray[animalCount] = animalObj;
      }

      // set the new amount to the total penguin count
      this->setPenguinCount(newPenguinCount);

      // // TESTING !!!
      // animalCount = this->getPenguinCount();
      // cout << "TESTING: new penguin count after using addAnimal function is --> " << animalCount << endl;

  } else {  // turtles
      // gets current turtle count for placement of turtle obj in array
      animalCount = this->getTurtleCount();

      // get current turtle count and add the amount of animals to be added to get the new turtle count
      int newTurtleCount = this->getTurtleCount() + numAnimalsToAdd;

      // check to see if the new turtle count is more than the array size (thus will need to be resized)
      if (newTurtleCount >= animalArraySize) {
        // resize the turtle array (also updates turtle array size )
        resizeArray(animalArray, zooAnimal, animalArraySize);
      }

      // if the number of turtles to be added is greater than 1
      if (numAnimalsToAdd > 1) {
        // keep adding turtle objects to array equal to the amount asked for
        for (int i = 0; i < numAnimalsToAdd; i++) {
          // add turtle obj to array
          animalArray[animalCount + i] = animalObj;
        }
      } else {  // for just one turtle to be added to array
        // add turtle obj to array
        animalArray[animalCount] = animalObj;
      }

      // set the new amount to the total turtle count
      this->setTurtleCount(newTurtleCount);

      // // TESTING !!!
      // animalCount = this->getTurtleCount();
      // cout << "TESTING: new turtle count after using addAnimal function is --> " << animalCount << endl;
  }
}



/*********************************************************************
**
REMOVE ANIMAL FUNCTION
void Zoo::removeAnimal(Animal* animalArray, ZooAnimalType zooAnimal, int randomAnimalDies)

Description:
Removes animal from array.

Arguments:
Animal pointer to array and integer random animal dies.

Restrictions:
Animal pointer and integer.

Returns:
Does not return anything.

*********************************************************************/
/*

source(s):

https://stackoverflow.com/questions/9511096/c-deleting-1-element-of-dynamic-array

https://www.reddit.com/r/learnprogramming/comments/5eojx0/c_removing_element_from_dynamic_array_and/

*/
void Zoo::removeAnimal(Animal* animalArray, int randomAnimalDies) {

  bool removed = false;

  if (randomAnimalDies == 1) {     // tiger
    while (removed == false) {
      // loops through tiger array
      for (int i = 0; i < sizeTiger; i++) {

        // if the age of the current tiger element is less than 3
        if (animalArray[i].getAge() < 3) {

          // lets user know which tiger was removed from the zoo
          cout << "RIP tiger " << i << endl;

          // sets age to -1 days old for dead tiger
          animalArray[i].setAge(-1);

          // decrement the tiger count
          setTigerCount(getTigerCount() - 1);

          // if the tiger count becomes negative because there are no tigers and remove animal was called
          // set tiger count to 0
          if (getTigerCount() < 0) {
            setTigerCount(0);
          }

          // change removed status to true
          removed = true;

          // breaks out of the for-loop after finding the first tiger that is less than 3 days old
          break;

        }
      }
    }
  } else if (randomAnimalDies == 2) { // penguin
    while (removed == false) {
      // loops through penguin array
      for (int i = 0; i < sizePenguin; i++) {

        // if the age of the current penguin element is less than 3
        if (animalArray[i].getAge() < 3) {

          // lets user know which penguin was removed from the zoo
          cout << "RIP penguin " << i << endl;

          // sets age to -1 days old for dead penguin
          animalArray[i].setAge(-1);

          // decrement the penguin count
          setPenguinCount(getPenguinCount() - 1);

          // if the penguin count becomes negative because there are no penguins and remove animal was called
          // set penguin count to 0
          if (getPenguinCount() < 0) {
            setPenguinCount(0);
          }

          // change removed status to true
          removed = true;

          // breaks out of the for-loop after finding the first penguin that is less than 3 days old
          break;
        }
      }
    }
  } else {    // turtle
    while (removed == false) {
      // loops through turtle array
      for (int i = 0; i < sizeTurtle; i++) {

        // if the age of the current turtle element is less than 3
        if (animalArray[i].getAge() < 3) {

          // lets user know which turtle was removed from the zoo
          cout << "RIP turtle " << i << endl;

          // sets age to -1 days old for dead turtle
          animalArray[i].setAge(-1);

          // decrement the turtle count
          setTurtleCount(getTurtleCount() - 1);

          // if the turtle count becomes negative because there are no turtles and remove animal was called
          // set turtle count to 0
          if (getTurtleCount() < 0) {
            setTurtleCount(0);
          }

          // change removed status to true
          removed = true;

          // breaks out of the for-loop after finding the first turtle that is less than 3 days old
          break;
        }
      }
    }
  }

}
