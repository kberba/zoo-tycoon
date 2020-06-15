/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Header for Penguin class

Inherits from Animal class. Has a default constructor and a custom constructor that takes in an integer age.

NOTES:
- Penguin cost $1,000
- Penguins have 5 babies
- Penguins have a feeding cost that is the same as the base cost
- A penguin’s payoff per day is 10% of their cost per animal

*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

/*
source(s):

https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/

https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor

*/
// Penguin class declaration - child class of Animal
class Penguin : public Animal {
  public:
    // default constructor
    Penguin();

    // custom constructor
    Penguin(int pAge);
};


#endif
