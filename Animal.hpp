/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Header for Animal class

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

*********************************************************************/

// include guards
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

// Animal class declaration
class Animal {
  protected:
    /*
    source(s):

    https://stackoverflow.com/questions/177437/what-does-const-static-mean-in-c-and-c

    https://stackoverflow.com/questions/26342286/how-is-in-class-static-const-initialization-of-float-different-from-int-in-c

    https://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const

    */
    static constexpr double BASE_FOOD_COST = 10.0;
    int animalAge;
    int numBabies;
    double initialCost;
    double foodCost;
    double payoff;

  public:
    // setters
    void setAge(int);
    void setNumBabies(int);
    void setInitialCost(double);
    void setFoodCost(double);
    void setPayoff(double);

    // getters
    int getAge();
    int getNumBabies();
    double getInitialCost();
    double getFoodCost();
    double getPayoff();

    // other functions
    int animalAging();

    // default constructor
    Animal();

    /*
    source(s):

    https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/

    https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor

    */
    // custom constructor
    Animal(int aAge);

};

#endif
