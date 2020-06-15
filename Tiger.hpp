/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Header for Tiger class

Inherits from Animal class. Has a default constructor and a custom constructor that takes in an integer age.

NOTES:
- Tiger cost $10,000
- Tigers have 1 baby
- Tigers have a feeding cost of 5 times the base cost
- A tiger’s payoff per day is 20% of their cost per animal. (not counting bonus)

*********************************************************************/

// include guards
#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

/*
source(s):

https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/

https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor

*/
// Tiger class declaration - child class of Animal
class Tiger : public Animal {
  public:
    // default constructor
    Tiger();

    // custom constructor
    Tiger(int tAge);

};



#endif
