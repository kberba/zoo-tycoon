/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Tiger class

Inherits from Animal class. Has a default constructor and a custom constructor that takes in an integer age.

NOTES:
- Tiger cost $10,000
- Tigers have 1 baby
- Tigers have a feeding cost of 5 times the base cost
- A tiger’s payoff per day is 20% of their cost per animal. (not counting bonus)

*********************************************************************/

#include "Tiger.hpp"

/*
source(s):

https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/

https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor

*/
// default constructor
Tiger::Tiger() : Animal(0) {  // age is 0 for baby tigers
  Tiger::setNumBabies(1);
  Tiger::setInitialCost(10000);
  Tiger::setFoodCost(5 * BASE_FOOD_COST);
  Tiger::setPayoff(0.20 * 10000);
}


// custom constructor
Tiger::Tiger(int tAge) : Animal(tAge) {   // for newly bought tigers
  Tiger::setNumBabies(1);
  Tiger::setInitialCost(10000);
  Tiger::setFoodCost(5 * BASE_FOOD_COST);
  Tiger::setPayoff(0.20 * 10000);
}
