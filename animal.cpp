/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2- Animal class implementation file. Includes various getters and setters for the class and
**  a function to increase the age of the animal by 1.
*******************************************************************************************************************/

#include "animal.hpp"
#include <iostream>

animal::animal(int &numberOfBabies, int &cost, int &feedingCostMultiplier, int &payoff) {
	NumberOfBabies = &numberOfBabies;
	Cost = &cost;
	Payoff = &payoff;
	baseFoodCost = 10;
}

int animal::getAge() {
	return Age;
}

void animal::setAge(int age) {
	Age = age;
}

//adds one to the animal's age
void animal::oneDayOlder() {
	Age += 1;
}

int animal::getBaseFoodCost() {
	return baseFoodCost;
}

int animal::getPayoff() {
	return *Payoff;
}

int animal::getCost() {
	return *Cost;
}

int animal::getNumberOfBabies() {
	return *NumberOfBabies;
}