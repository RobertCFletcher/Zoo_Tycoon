/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2 - Header file for the penguin class.
*******************************************************************************************************************/

#include "animal.hpp"

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class penguin : public animal {

private:
	int numberOfBabies;
	int cost;
	int payoff;
	int feedingCostMultiplier;

protected:

public:
	penguin();
	int getFeedingCost();
};
#endif