/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2 - Header file for the Animal class. Includes various getters and setters for private
**	variables.  Includes oneDayOlder function to increment the animal's age.
*******************************************************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class animal {

private:
	int Age;
	int* NumberOfBabies;
	int* Cost;
	int baseFoodCost;
	int* Payoff;

protected:



public:
	animal(int &numberOfBabies, int &cost, int &feedingCostMultiplier, int &payoff);
	void oneDayOlder();
	int getAge();
	void setAge(int age);
	int getBaseFoodCost();
	int getPayoff();
	int getCost();
	int getNumberOfBabies();
};
#endif

