/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Header for Turtle class

Inherits from Animal class. Has a default constructor and a custom constructor that takes in an integer age.

NOTES:
- Turtle cost $100
- Turtles have 10 babies
- Turtles have a feeding cost that is 50% the base cost
- A turtle’s payoff per day is 5% of their cost per animal

*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"


/*
source(s):

https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/

https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor

*/
// Turtle class declaration - child class of Animal
class Turtle : public Animal {
  public:
    // default constructor
    Turtle();

    // custom constructor
    Turtle(int tAge);

};



#endif
