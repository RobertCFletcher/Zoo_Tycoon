/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2- Penguin implementation file.  
*******************************************************************************************************************/

#include "penguin.hpp"

penguin::penguin() : animal(numberOfBabies, cost, feedingCostMultiplier, payoff) {
	numberOfBabies = 5;
	cost = 1000;
	payoff = 100;
	feedingCostMultiplier = 1;
}

//calculates and returns the feeding cost for the penguin
int penguin::getFeedingCost() {
	return animal::getBaseFoodCost() * feedingCostMultiplier;
}