/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2 - Header file for the tiger class.
*******************************************************************************************************************/
#include "animal.hpp"

#ifndef TIGER_HPP
#define TIGER_HPP

class tiger : public animal {

private:
	int numberOfBabies;
	int cost;
	int payoff;
	int feedingCostMultiplier;

protected:

public:
	tiger();
	int getFeedingCost();
};
#endif