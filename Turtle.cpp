/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Turtle class

Inherits from Animal class. Has a default constructor and a custom constructor that takes in an integer age.

NOTES:
- Turtle cost $100
- Turtles have 10 babies
- Turtles have a feeding cost that is 50% the base cost
- A turtle’s payoff per day is 5% of their cost per animal

*********************************************************************/

#include "Turtle.hpp"

/*
source(s):

https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/

https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor

*/
// default constructor
Turtle::Turtle() : Animal(0) {    // age is 0 for baby turtles
  Turtle::setNumBabies(10);
  Turtle::setInitialCost(100);
  Turtle::setFoodCost(0.5 * BASE_FOOD_COST);
  Turtle::setPayoff(0.05 * 100);
}


// custom constructor
Turtle::Turtle(int tAge) : Animal(tAge) {     // for newly bought turtles
  Turtle::setNumBabies(10);
  Turtle::setInitialCost(100);
  Turtle::setFoodCost(0.5 * BASE_FOOD_COST);
  Turtle::setPayoff(0.05 * 100);
}
