/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Animal class

Animal class is the parent/base class for Tiger class, Penguin class, and Turtle class.

Animal class
- Protected
    - Static constexpr double base food cost
    - Age, babies, starting cost, food cost, payoff
- Public
    - Setters
        - Set age, babies, starting cost, food cost, payoff
    - Getters
        - Get age, babies, starting cost, food cost, payoff
    - Other functions
        - Animal aging function
    - Default constructor
    - Custom constructor that takes in an integer age

NOTES:

    Age
    Adult if age >= 3 days
    Baby if age < 3 days
    ** babies start at 0 days old
    ** newly bought animals start at 1 day old
    *** Dead animals will be set -1 days old

*********************************************************************/

#include "Animal.hpp"



/*********************************************************************
**
SETTERS

Description:
Setters for animalAge, numBabies, initialCost, foodCost, and payoff.

Arguments:
Integers and doubles.

Restrictions:
Only integers and doubles.

Returns:
Does not return anything.


*********************************************************************/
void Animal::setAge(int numAge) {
  animalAge = numAge;
}

void Animal::setNumBabies(int baby) {
  numBabies = baby;
}

void Animal::setInitialCost(double icost) {
  initialCost = icost;
}

void Animal::setFoodCost(double fcost) {
  foodCost = fcost;
}

void Animal::setPayoff(double pay) {
  payoff = pay;
}


/*********************************************************************
**
GETTERS

Description:
Getters for animalAge, numBabies, initialCost, foodCost, and payoff.

Arguments:
No arguments.

Restrictions:
No restrictions.

Returns:
Returns integers and doubles of the variables.


*********************************************************************/
int Animal::getAge() {
  return animalAge;
}

int Animal::getNumBabies() {
  return numBabies;
}

double Animal::getInitialCost() {
  return initialCost;
}

double Animal::getFoodCost() {
  return foodCost;
}

double Animal::getPayoff() {
  return payoff;
}


/*********************************************************************
**
DEFAULT CONSTRUCTOR

*********************************************************************/
Animal::Animal() {
  setAge(0);  // initial age for baby animal
}


/*********************************************************************
**
CUSTOM CONSTRUCTOR

*********************************************************************/
Animal::Animal(int aAge) {
  setAge(aAge); // age for newly bought adult
}


/*********************************************************************
**
int Animal::animalAging()

Description:
Adds 1 day to the animal's current age.

Arguments:
No arguments.

Restrictions:
Only integers.

Returns:
Integer animalAge.

*********************************************************************/
int Animal::animalAging() {
  // adds 1 day to the animal's current age
  animalAge += 1;

  // returns the new animal age
  return animalAge;
}
