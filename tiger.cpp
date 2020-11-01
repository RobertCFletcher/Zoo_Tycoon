/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2 - Implementation file for the tiger class.
*******************************************************************************************************************/

#include "tiger.hpp"

tiger::tiger() : animal(numberOfBabies, cost, feedingCostMultiplier, payoff) {
	numberOfBabies = 1;
	cost = 10000;
	payoff = 2000;
	feedingCostMultiplier = 5;
}

//calculates and returns the feeding cost for a tiger
int tiger::getFeedingCost() {
	return animal::getBaseFoodCost() * feedingCostMultiplier;
}