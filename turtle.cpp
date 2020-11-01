/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2- Implementation file for the turtle class.
*******************************************************************************************************************/

#include "turtle.hpp"

turtle::turtle() : animal(numberOfBabies, cost, feedingCostMultiplier, payoff) {
	numberOfBabies = 10;
	cost = 100;
	payoff = 5;
	feedingCostMultiplier = 2;
}

//calculates and returns the feeding cost for a turtle
int turtle::getFeedingCost() {
	return animal::getBaseFoodCost() / feedingCostMultiplier;
}