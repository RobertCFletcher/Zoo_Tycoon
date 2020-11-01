/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2 - Header file for the turtle class.
*******************************************************************************************************************/

#include "animal.hpp"

#ifndef TURTLE_HPP
#define TURTLE_HPP

class turtle : public animal {

private:
	int numberOfBabies;
	int cost;
	int payoff;
	int feedingCostMultiplier;
	
protected:

public:
	turtle();
	int getFeedingCost();
};
#endif