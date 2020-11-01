/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2 - Header file for the zoo class.  See below for function descriptions.
*******************************************************************************************************************/

#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

#ifndef ZOO_HPP
#define ZOO_HPP

class zoo {
	
private:
	int totalCash;
	int zooFeedingCost;
	int dailyProfit;
	int numberOfTigers;
	int numberOfPenguins;
	int numberOfTurtles;
	tiger* tigerArray;
	penguin* penguinArray;
	turtle* turtleArray;

protected:


public:
	zoo();
	//adds a penguin to the array of penguins
	void addPenguin(int age);
	//adds a turtle to the array of turtles
	void addTurtle(int age);
	//deletes all arrays in the zoo
	void closeZoo();
	//adds a tiger to the array of tigers
	void addTiger(int age);
	//gets the total feeding cost for the zoo
	int getFeedingCost();
	//goes to the next day, increments all the ages, and performs all other functions for the day
	void nextDay();
	//returns the total cash in the bank
	int getCash();
};
#endif