/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

mainZoo.cpp

Main file runs the entire Zoo Tycoon program. Zoo tycoon is a game that allows
players to run a zoo business. Different types of animals cost different prices,
have different maintenance costs, and of course, return a different profit at the
end of each day. For this game, the player will be the proud owner of a virtual
zoo that has spaces to house tigers, penguins and turtles.

How to run:
Compile mainZoo.cpp, Zoo.cpp, Animal.cpp, Tiger.cpp, Penguin.cpp, and Turtle.cpp together.

*********************************************************************/

#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <iostream>
#include <limits>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

// function prototypes
int menu();
int inputValidation();
int oneTwoValidation();
int oneTwoThreeValidation();

// main function
int main() {
  int menuChoice;   // (1) play or (2) exit game
  int userInput = 0;
  int countTigers = 0;
  int countPenguins = 0;
  int countTurtles = 0;
  int tigArraySize = 0;
  int penArraySize = 0;
  int turtArraySize = 0;
  int tigerAge = 0;
  int penguinAge = 0;
  int turtleAge = 0;
  int dayCount = 1; // starting of game is day 1
  int userMoney = 100000; // starting money in bank
  int randomNum = 4;  // randomly generated number to pick random event
  double tigerDayProfit = 0.0;
  double penguinDayProfit = 0.0;
  double turtleDayProfit = 0.0;
  double dayProfit = 0.0;
  double bonus = 0.0;
  enum RandomEvent { SICK = 1, BOOM, BABY, NOTHING }; // for the 4 random possible events

  // asks user to start/quit game
  menuChoice = menu();

  // if user chooses to quit program
  if (menuChoice == 2) {
    cout << "Thank you. Goodbye!" << endl;
    return 0;
  }

  // loop for the game
  do {
    // create zoo object
    Zoo zooObj;

    // local copy for animal dynamic arrays
    Animal* tigers = zooObj.getTigersArray();
    Animal* penguins = zooObj.getPenguinsArray();
    Animal* turtles = zooObj.getTurtlesArray();

    // greets user
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << " W E L C O M E    T O    -- Z O O   T Y C O O N --" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl;

    // prompt user for number of each type of animal
    cout << "Instructions: " << endl;
    cout << "You will now be picking from three choices of animals: " << endl;
    cout << "*** TIGERS" << endl;
    cout << "*** PENGUINS" << endl;
    cout << "*** TURTLES" << endl;
    cout << endl;
    cout << "You must have at least one (1) animal of each type, and can have no more " << endl;
    cout << "than two (2) of each kind. Please choose your animals: " << endl;
    cout << endl;

    cout << "How many TIGER(S) would you like to add to your zoo? " << endl;
    // input validation
    userInput = oneTwoValidation();

    // if user chooses to buy 1 tiger
    if (userInput == 1) {
      // gets initial tiger count
      countTigers = zooObj.getTigerCount();

      // get initial tiger array size
      tigArraySize = zooObj.getSizeTiger();

      // creates tiger object with age of 1 day old
      Tiger tigerObj(1);

      // add tiger to the array (which also updates the tiger count)
      // (array, enum for animal type, animal obj, # to add, animal array size)
      zooObj.addAnimal(tigers, TIGER, tigerObj, userInput, tigArraySize);

      // subtract money from account
      userMoney = userMoney - tigers->getInitialCost();

    } else {  // for two tigers
      // gets initial tiger count
      countTigers = zooObj.getTigerCount();

      // get initial tiger array size
      tigArraySize = zooObj.getSizeTiger();

      // creates tiger objects with age of 1 day old
      Tiger tigerObj(1);
      Tiger tigerObj2(1);

      // add tigers to the array (which also updates the tiger count)
      zooObj.addAnimal(tigers, TIGER, tigerObj, 1, tigArraySize);
      zooObj.addAnimal(tigers, TIGER, tigerObj2, 1, tigArraySize);

      // subtract money from account
      userMoney = userMoney - (2 * tigers->getInitialCost());
    }

    cout << endl;

    cout << "How many PENGUIN(S) would you like to add to your zoo? " << endl;
    // input validation
    userInput = oneTwoValidation();

    // if user chooses to buy 1 penguin
    if (userInput == 1) {
      // gets initial penguin count
      countPenguins = zooObj.getPenguinCount();

      // get initial penguin array size
      penArraySize = zooObj.getSizePenguin();

      // creates penguin object with age of 1 day old
      Penguin penguinObj(1);

      // add penguin to the array (which also updates the penguin count)
      zooObj.addAnimal(penguins, PENGUIN, penguinObj, userInput, penArraySize);

      // subtract money from account
      userMoney = userMoney - penguins->getInitialCost();

    } else {  // for two penguin
      // gets initial penguin count
      countPenguins = zooObj.getPenguinCount();

      // get initial penguin array size
      penArraySize = zooObj.getSizePenguin();

      // creates penguin objects with age of 1 day old
      Penguin penguinObj(1);
      Penguin penguinObj2(1);

      // add penguin to the array (which also updates the penguin count)
      zooObj.addAnimal(penguins, PENGUIN, penguinObj, 1, penArraySize);
      zooObj.addAnimal(penguins, PENGUIN, penguinObj2, 1, penArraySize);

      // subtract money from account
      userMoney = userMoney - (2 * penguins->getInitialCost());
    }

    cout << endl;

    cout << "How many TURTLE(S) would you like to add to your zoo? " << endl;
    // input validation
    userInput = oneTwoValidation();

    // if user chooses to buy 1 turtle
    if (userInput == 1) {
      // gets initial turtle count
      countTurtles = zooObj.getTurtleCount();

      // get initial turtle array size
      int turtArraySize = zooObj.getSizeTurtle();

      // creates turtle object with age of 1 day old
      Turtle turtleObj(1);

      // add turtle to the array (which also updates the turtle count)
      zooObj.addAnimal(turtles, TURTLE, turtleObj, userInput, turtArraySize);

      // subtract money from account
      userMoney = userMoney - turtles->getInitialCost();

    } else {  // for two turtles
      // gets initial turtle count
      countTurtles = zooObj.getTurtleCount();

      // get initial turtle array size
      int turtArraySize = zooObj.getSizeTurtle();

      // creates turtle objects with age of 1 day old
      Turtle turtleObj(1);
      Turtle turtleObj2(1);

      // add turtle to the array (which also updates the turtle count)
      zooObj.addAnimal(turtles, TURTLE, turtleObj, 1, turtArraySize);
      zooObj.addAnimal(turtles, TURTLE, turtleObj2, 1, turtArraySize);

      // subtract money from account
      userMoney = userMoney - (2 * turtles->getInitialCost());
    }

    cout << endl;


    // loop for each day
      do {
        // Outputs:
        // *** day #
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "***** DAY " << dayCount << " has begun!! Rise and shine! *****" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;

        // *** number of each animal
        cout << "TIGER total count: ";
        countTigers = zooObj.getTigerCount();
        cout << countTigers << endl;

        cout << "PENGUIN total count: ";
        countPenguins = zooObj.getPenguinCount();
        cout << countPenguins << endl;

        cout << "TURTLE total count: ";
        countTurtles = zooObj.getTurtleCount();
        cout << countTurtles << endl;

        // *** current money in bank
        cout << "Bank balance (at start of the day): " << userMoney << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;

        // animals age 1 day  !!!
        // (at beginning of the game, animals are initially bought at 1 day old. when day actually
        // 'begins', they will be aged 2 days old. )
        tigers->animalAging();
        penguins->animalAging();
        turtles->animalAging();

        // subtract feeding cost from bank account !!!
        userMoney = userMoney - (countTigers * tigers->getFoodCost()) - (countPenguins * penguins->getFoodCost()) - (countTurtles * turtles->getFoodCost());

        // current money amount after feeding
        cout << "Bank balance (after feeding): " << userMoney << endl;
        cout << endl;


        // generate random event !!!!
        cout << "---------------------------------------------------------------" << endl;
        cout << " ***** R A N D O M   E V E N T   H A S   O C C U R R E D *****" << endl;
        cout << "---------------------------------------------------------------" << endl;
        /*
        source(s):

        https://stackoverflow.com/questions/13500494/rand-generating-the-same-number

        http://www.math.uaa.alaska.edu/~afkjm/csce211/fall2018/handouts/RandomFunctions.pdf

        https://stackoverflow.com/questions/26829421/true-random-integer-between-20-and-30-in-c

        */
        // uses the current time as the seed for random number generator
        srand(static_cast<int>(time(0)));

        // generates a random number between 1 and 4
        randomNum = (rand() % 4) + 1;

        // define random events with loops !!!!
        switch (randomNum) {
          case SICK:
            cout << "Sickness has occurred in the zoo!! D:" << endl;
            /*
            A sickness occurs to an animal in the zoo:
            *** Pick an animal at random that will die
            *** Remove one animal of that type from the exhibit. (dynamic array in the zoo)
            */

            // generates a number that will pick an animal type: 1) tiger, 2) penguin, 3) turtle
            randomNum = (rand() % 3) + 1;

            // removes animal of the type randomly generated above
            if (randomNum == 1) {   // tiger
              // removes tiger
              zooObj.removeAnimal(tigers, randomNum);
            } else if (randomNum == 2) {  // penguin
                // removes penguin
                zooObj.removeAnimal(penguins, randomNum);
            } else {  // turtle
                // removes turtle
                zooObj.removeAnimal(turtles, randomNum);
            }
            break;
          case BOOM:
            cout << "Wow, the zoo is popular today!! XD" << endl;
            /*
            A boom in zoo attendance occurs:
            *** Generate a random bonus between 250 and 500 dollars for each tiger in the zoo for the day
            *** Add the bonus payoff for each tiger to the total payoff of the day as a reward
            */

            // generates a random bonus between $250 and $500
            randomNum = (rand() % 250) + 250;

            cout << "Random bonus generated: " << randomNum << endl;

            // calculates bonus based on how many tigers there are
            bonus = zooObj.getTigerCount() * randomNum;

            cout << "TOTAL BONUS for " << zooObj.getTigerCount() << " tigers is: " << bonus << endl;

            break;
          case BABY:
            cout << "Congrats! A baby may be born today!! :D" << endl;
            cout << endl;
            /*
            A baby animal is born:
            *** Pick an animal at random to have a baby
            *** Check if there is an animal old enough to be a parent (age >= 3), add babies to the zoo depending on the “number of babies” specific to the type of animal.
            *** If no animal is old enough of the randomly selected type, pick another type of animal.
            *** Baby animals start at age 0.
            */

            // generates a number that will pick an animal type: 1) tiger, 2) penguin, 3) turtle
            randomNum = (rand() % 3) + 1;

            // checks to see if there is an animal old enough to be a parent amongst all of the animals (>= 3 days old)
            // the first animal in each array will be the oldest animal
            tigerAge = tigers[0].getAge();
            penguinAge = penguins[0].getAge();
            turtleAge = turtles[0].getAge();

            if (randomNum == 1) {   // tiger
              // checks if tiger is an adult
              if (tigerAge >= 3) {
                // creates tiger obj
                Tiger babyTiger;

                // adds tiger to array
                zooObj.addAnimal(tigers, TIGER, babyTiger, 1, tigArraySize);

                cout << "1 tiger was born today!" << endl;
              } else if (penguinAge >= 3) {  // if there's no adult tiger, check penguins for an adult
                  // creates penguin obj
                  Penguin babyPenguin;

                  // adds penguin to array
                  zooObj.addAnimal(penguins, PENGUIN, babyPenguin, 5, penArraySize);

                  cout << "5 baby penguins were born today!" << endl;
              } else if (turtleAge >= 3) { // if there's no adult penguin, check turtles for an adult
                  // creates turtle obj
                  Turtle babyTurtle;

                  // adds turtle to array
                  zooObj.addAnimal(turtles, TURTLE, babyTurtle, 10, turtArraySize);

                  cout << "10 baby turtles were born today!" << endl;
              } else {
                cout << "There are no adult animals available to have babies." << endl;
              }

            } else if (randomNum == 2) { // penguin
                // checks if penguin is an adult
                if (penguinAge >= 3) {

                  // creates penguin obj
                  Penguin babyPenguin;

                  // adds penguin to array
                  zooObj.addAnimal(penguins, PENGUIN, babyPenguin, 5, penArraySize);

                  cout << "5 baby penguins were born today!" << endl;

                } else if (tigerAge >= 3) {  // if there's no adult penguin, check tigers for an adult
                    // creates tiger obj
                    Tiger babyTiger;

                    // adds penguin to array
                    zooObj.addAnimal(tigers, TIGER, babyTiger, 1, tigArraySize);

                    cout << "1 tiger was born today!" << endl;

                } else if (turtleAge >= 3) { // if there's no adult tiger, check turtles for an adult
                    // creates turtle obj
                    Turtle babyTurtle;

                    // adds turtle to array
                    zooObj.addAnimal(turtles, TURTLE, babyTurtle, 10, turtArraySize);

                    cout << "10 baby turtles were born today!" << endl;

                } else {
                  cout << "There are no adult animals available to have babies." << endl;
                }

            } else {  // turtle
                // checks if turtle is an adult
                if (turtleAge >= 3) {

                  // creates turtle obj
                  Turtle babyTurtle;

                  // adds turtle to array
                  zooObj.addAnimal(turtles, TURTLE, babyTurtle, 10, turtArraySize);

                  cout << "10 baby turtles were born today!" << endl;

                } else if (penguinAge >= 3) {  // if there's no adult turtle, check penguins for an adult
                    // creates penguin obj
                    Penguin babyPenguin;

                    // adds penguin to array
                    zooObj.addAnimal(penguins, PENGUIN, babyPenguin, 5, penArraySize);

                    cout << "5 baby penguins were born today!" << endl;

                } else if (tigerAge >= 3) {  // if there's no adult penguin, check tigers for an adult
                    // creates tiger obj
                    Tiger babyTiger;

                    // adds penguin to array
                    zooObj.addAnimal(tigers, TIGER, babyTiger, 1, tigArraySize);

                    cout << "1 tiger was born today!" << endl;

                } else {
                  cout << "There are no adult animals available to have babies." << endl;
                }
            }
            break;
          case NOTHING:
            cout << "Nothing has happened. :/" << endl;
            break;
        }

        cout << endl;
        cout << endl;

        cout << "-------------------------------------------------------" << endl;
        cout << " *****     E N D   O F   D A Y   S T A T S     *****" << endl;
        cout << "-------------------------------------------------------" << endl;

        // *** number of each animal
        cout << "TIGER total count: ";
        countTigers = zooObj.getTigerCount();
        cout << countTigers << endl;

        cout << "PENGUIN total count: ";
        countPenguins = zooObj.getPenguinCount();
        cout << countPenguins << endl;

        cout << "TURTLE total count: ";
        countTurtles = zooObj.getTurtleCount();
        cout << countTurtles << endl;

        cout << endl;

        // calculate profit for the day for each animal: their payoff (and bonus) !!!!
        // loop through tiger array and add up the total payoff & account for bonus !!!
        for (int i = 0; i < zooObj.getTigerCount(); i++) {
          tigerDayProfit += tigers[i].getPayoff();

        }

        // add bonus
        tigerDayProfit += bonus;

        cout << "Your tigers made: " << tigerDayProfit << " today!" << endl;

        // loop through penguin array and add up total payoff
        for (int i = 0; i < zooObj.getPenguinCount(); i++) {
          penguinDayProfit += penguins[i].getPayoff();

        }

        cout << "Your penguins made: " << penguinDayProfit << " today!" << endl;

        // loop through turtle array and add up total payoff
        for (int i = 0; i < zooObj.getTurtleCount(); i++) {
          turtleDayProfit += turtles[i].getPayoff();

        }

        cout << "Your turtles made: " << turtleDayProfit << " today!" << endl;

        cout << endl;

        // add up total profit for the day
        dayProfit = tigerDayProfit + penguinDayProfit + turtleDayProfit;

        // add total day profit to user's money
        userMoney += dayProfit;

        // announce total profit for the day
        cout << "Your TOTAL PROFIT for DAY " << dayCount << " is " << dayProfit << endl;

        // bank balance
        cout << "End of day bank balance: " << userMoney << endl;

        cout << "--------------------------------------------------------" << endl;
        cout << endl;

        // prompts user to see if they want to buy another animal or else keep going !!!!!
        cout << "Would you like to buy an ADULT animal?" << endl;

        // displays the menu
        cout << "\n Options Menu\n\n";
        cout << "(1) YES\n";
        cout << "(2) NO\n\n";

        // input validation for menu choice
        menuChoice = oneTwoValidation();

        cout << endl;

        // if the user chooses to buy an animal, ask what type
        if (menuChoice == 1) {
          cout << "\n Choose Type of Animal\n\n";
          cout << "(1) TIGER\n";
          cout << "(2) PENGUIN\n";
          cout << "(3) TURTLE\n\n";

          // input validation
          menuChoice = oneTwoThreeValidation();

          // adds animal to zoo
          if (menuChoice == 1) {  // tiger
            // create a tiger with age 3 days old (adult)
            Tiger adultTiger(3);

            // get current array size
            int tigArraySize = zooObj.getSizeTiger();

            // add animal to tiger array
            zooObj.addAnimal(tigers, TIGER, adultTiger, 1, tigArraySize);

            // subtract tiger cost from money
            userMoney -= tigers->getInitialCost();

            cout << "You just bought an adult tiger! Congrats!" << endl;

          } else if (menuChoice == 2) {   // penguin
              // create a penguin with age 3 days old
              Penguin adultPenguin(3);

              // get current array size
              int penArraySize = zooObj.getSizePenguin();

              // add animal to penguin array
              zooObj.addAnimal(penguins, PENGUIN, adultPenguin, 1, penArraySize);

              // subtract penguin cost from money
              userMoney -= penguins->getInitialCost();

              cout << "You just bought an adult penguin! Congrats!" << endl;

          } else {    // turtle
              // create a turtle with age 3 days old
              Turtle adultTurtle(3);

              // get current array size
              int turtArraySize = zooObj.getSizeTurtle();

              // add animal to turtle array
              zooObj.addAnimal(turtles, TURTLE, adultTurtle, 1, turtArraySize);

              // subtract turtle cost from money
              userMoney -= turtles->getInitialCost();

              cout << "You just bought an adult turtle! Congrats!" << endl;
          }

        }


        cout << endl;
        cout << "Current bank balance: " << userMoney << endl;
        cout << endl;

        cout << "-------------------------------------------------------" << endl;

        // ask player if they want to keep playing or quit
        cout << "Would you like to keep playing or quit?" << endl;

        // displays the menu
        cout << "\n Options Menu\n\n";
        cout << "(1) CONTINUE\n";
        cout << "(2) EXIT\n\n";

        // input validation
        menuChoice = oneTwoValidation();

        // if user chooses to quit program
        if (menuChoice == 2) {
          cout << endl;
          cout << "---------------------------------------" << endl;
          cout << "Thank you for playing ZOO TYCOON. Goodbye!" << endl;
          cout << endl;
          return 0;
        }

        // reset each animal's day profits
        tigerDayProfit = 0;
        penguinDayProfit = 0;
        turtleDayProfit = 0;

        // reset tiger bonus
        bonus = 0;

        // increment day
        dayCount += 1;

        // // testing !!!
        // cout << "TESTING: Updated day count to --> Day" << dayCount << endl;
        // cout << "TESTING: userMoney is " << userMoney << endl;

      } while(userMoney > 0); // break out of do-while loop when account reaches 0


      // game ends message
      cout << "GAME OVER. You have no more money to run your zoo. ):" << endl;

      // asks if user wants to play again
      cout << endl;
      cout << "---------------------------------------" << endl;
      cout << "Play again? " << endl;
      menuChoice = menu();

      // if user chooses to quit program
      if (menuChoice == 2) {
        cout << endl;
        cout << "---------------------------------------" << endl;
        cout << "Thank you for playing ZOO TYCOON. Goodbye! ***" << endl;
        cout << endl;
        return 0;
      }

  } while(menuChoice == 1);

  return 0;
}


/*********************************************************************
**
int menu()

Description:
A menu that asks the user to select from the following 2 choices:
  1)  Play game
  2)  Exit game
Has no parameters.

Arguments:
No arguments.

Restrictions:
Can only accept numbers that are the option choices (e.g. 1 or 2).

Returns:
The option the user chose from the menu as an integer.


*********************************************************************/
/*
source(s):
  C++ Early Objects 9th Edition (Gaddis, Walters, Muganda)
  Chapter 6.9 - Program 6-14 (page 351)

  http://www.cplusplus.com/forum/beginner/229334/

*/
int menu() {
  int choice;       // holds the user's menu choice

  do {
    // displays the menu
    cout << "\n Options Menu\n\n";
    cout << "(1) PLAY GAME\n";
    cout << "(2) EXIT\n\n";

    // user chooses from the menu options
    cout << "Please choose an option from the menu: " << endl;
    // cin >> choice;
    choice = inputValidation();

    // input validation
    while (choice < 1 || choice > 2) {
      cout << "That is not a valid choice. Choose either: (1) PLAY GAME, or (2) EXIT. Please re-enter a valid number. " << endl;
      // cin >> choice;
      choice = inputValidation();
    }
    cout << "You have chosen: ";

    switch (choice) {
      case 1: cout << "(1) PLAY GAME" << endl;
              break;
      case 2: cout << "(2) EXIT " << endl;
              break;
    }

  } while (choice < 1 || choice > 2);

  return choice;
}


/*********************************************************************
**
int inputValidation()

Description:
Checks to see if the user has inputted a number.
Will keep looping until a valid number has been entered. Has no parameters.

Arguments:
No arguments.

Restrictions:
Only accepts integers greater than 0.

Returns:
Returns the number the user enters.


*********************************************************************/
/*
source(s):

https://stackoverflow.com/questions/19018294/c-to-check-if-user-input-is-a-number-not-a-character-or-a-symbol

https://www.hackerearth.com/practice/notes/validating-user-input-in-c/

https://stackoverflow.com/questions/9612839/is-there-a-way-to-check-if-a-variable-is-a-whole-number-c

https://www.programiz.com/cpp-programming/library-function/cmath/floor

https://stackoverflow.com/questions/20446373/cin-ignorenumeric-limitsstreamsizemax-n-max-not-recognize-it

https://stackoverflow.com/questions/4798936/numeric-limits-was-not-declared-in-this-scope-no-matching-function-for-call-t

*/
int inputValidation()
{
    int input;
    // takes in user input
    cin >> input;

    // if the user enters a non-numeric value
    while(cin.fail() || input <= 0) {
      // clears error flags
      cin.clear();
      // gets rid of wrong input in stream
      cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      cout << "That is not a valid choice. Please re-enter a valid number: " << endl;
      cin >> input;
      cout << endl;
    }

    return input;
}


/*********************************************************************
**
int oneTwoValidation()

Description:
Checks to see if the user has inputted either 1 or 2.
Will keep looping until a valid number (1 or 2) has been entered. Has no parameters.

Arguments:
No arguments.

Restrictions:
Only accepts the integers 1 or 2.

Returns:
Returns the number the user enters.

*********************************************************************/
int oneTwoValidation()
{
    int input;

    do {
      input = inputValidation();

      while (input < 1 || input > 2) {
        cout << "Invalid number. Please choose either one (1) or two (2): " << endl;
        input = inputValidation();
      }

    } while (input < 1 || input > 2);

    return input;
}



/*********************************************************************
**
int oneTwoThreeValidation()

Description:
Checks to see if the user has inputted either 1, 2, 3.
Will keep looping until a valid number (1 or 2 or 3) has been entered. Has no parameters.

Arguments:
No arguments.

Restrictions:
Only accepts the integers 1 or 2 or 3.

Returns:
Returns the number the user enters.

*********************************************************************/
int oneTwoThreeValidation()
{
    int input;

    do {
      input = inputValidation();

      while (input < 1 || input > 3) {
        cout << "Invalid number. Please choose either: one (1) or two (2) or three (3): " << endl;
        input = inputValidation();
      }

    } while (input < 1 || input > 3);

    return input;
}
