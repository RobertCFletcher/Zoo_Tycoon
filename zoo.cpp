/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2- Zoo implementation file.  Creates a dynamic array of tigers, penguins, and turtles.  Keeps
**	track of the total cash on hand and the number of each type of animal.  Implements the nextDay() function which
**	handles updating all of the variables associated with a new day.
*******************************************************************************************************************/


#include "zoo.hpp"
#include <iostream>
#include <cstdlib>


zoo::zoo() {
	numberOfTigers = 0;
	numberOfPenguins = 0;
	numberOfTurtles = 0;
	dailyProfit = 0;
	zooFeedingCost = 0;
	totalCash = 100000;
	tigerArray = new tiger[10];
	penguinArray = new penguin[10];
	turtleArray = new turtle[10];
}

//clears the memory for all the dynamic animal arrays
void zoo::closeZoo() {
	delete[] tigerArray;
	delete[] penguinArray;
	delete[] turtleArray;
}

//add a tiger to the tiger array for the zoo
void zoo::addTiger(int age) {
	numberOfTigers++;
	if (numberOfTigers % 10 == 0) {
		int* saveTigerAges = new int[numberOfTigers - 1];
		//save all the tiger ages from the array
		for (int i = 0; i < numberOfTigers - 1; i++) {
			saveTigerAges[i] = tigerArray[i].getAge();
		}
		//delete the original tiger array
		delete[] tigerArray;

		//calculate the size for the new tiger array
		int newArraySize = ((numberOfTigers / 10) + 1) * 10;

		//set the new size for tigerArray
		tigerArray = new tiger[newArraySize];

		//add all the tigers back into the tiger array with the correct ages
		for (int i = 0; i < numberOfTigers; i++) {
			tigerArray[i].setAge(saveTigerAges[i]);
		}
		tigerArray[numberOfTigers - 1].setAge(age);
		//set the amount of cash that the user now has
		totalCash -= tigerArray[numberOfTigers - 1].getCost();

		//set the zoo feeding cost to reflect the cost after the new tiger is added
		zooFeedingCost += tigerArray[numberOfTigers - 1].getFeedingCost();

		//free the memory for the saveTigerAges array
		delete[] saveTigerAges;
		std::cout << "A baby tiger has been added!" << std::endl;
	}

	//if dynamic array doesn't need to be adjusted, add a baby tiger to the array
	else {
		tigerArray[numberOfTigers - 1].setAge(age);
		totalCash -= tigerArray[numberOfTigers - 1].getCost();
		zooFeedingCost += tigerArray[numberOfTigers - 1].getFeedingCost();
		std::cout << "A baby tiger has been added!" << std::endl;
	}
}


//add a penguin to the penguin array for the zoo
void zoo::addPenguin(int age) {
	numberOfPenguins++;
	if (numberOfPenguins % 10 == 0) {
		int* savePenguinAges = new int[numberOfPenguins - 1];
		//save all the penguin ages from the array
		for (int i = 0; i < numberOfPenguins - 1; i++) {
			savePenguinAges[i] = penguinArray[i].getAge();
		}
		//delete the original penguin array
		delete[] penguinArray;

		//calculate the size for the new penguin array
		int newArraySize = ((numberOfPenguins / 10) + 1) * 10;

		//set the new size for penguinArray
		penguinArray = new penguin[newArraySize];

		//add all the penguins back into the penguin array with the correct ages
		for (int i = 0; i < numberOfPenguins; i++) {
			penguinArray[i].setAge(savePenguinAges[i]);
		}
		penguinArray[numberOfPenguins - 1].setAge(age);
		//set the amount of cash that the user now has
		totalCash -= penguinArray[numberOfPenguins - 1].getCost();

		//set the zoo feeding cost to reflect the cost after the new penguin is added
		zooFeedingCost += penguinArray[0].getFeedingCost();

		//free the memory for the savePenguinAges array
		delete[] savePenguinAges;
		std::cout << "A baby penguin has been added!" << std::endl;
	}

	//if dynamic array doesn't need to be adjusted, add a baby tiger to the array
	else {
		penguinArray[numberOfPenguins - 1].setAge(age);
		totalCash -= penguinArray[numberOfPenguins - 1].getCost();
		zooFeedingCost += penguinArray[numberOfPenguins - 1].getFeedingCost();
		std::cout << "A baby penguin has been added!" << std::endl;
	}
}

//add a turtle to the turtle array for the zoo
void zoo::addTurtle(int age) {
	numberOfTurtles++;
	if (numberOfTurtles % 10 == 0) {
		int* saveTurtleAges = new int[numberOfTurtles - 1];
		//save all the turtle ages from the array
		for (int i = 0; i < numberOfTurtles - 1; i++) {
			saveTurtleAges[i] = turtleArray[i].getAge();
		}
		//delete the original turtle array
		delete[] turtleArray;

		//calculate the size for the new turtle array
		int newArraySize = ((numberOfTurtles / 10) + 1) * 10;

		//set the new size for turtleArray
		turtleArray = new turtle[newArraySize];

		//add all the turtles back into the turtle array with the correct ages
		for (int i = 0; i < numberOfTurtles; i++) {
			turtleArray[i].setAge(saveTurtleAges[i]);
		}
		turtleArray[numberOfTurtles - 1].setAge(age);
		//set the amount of cash that the user now has
		totalCash -= turtleArray[numberOfTurtles - 1].getCost();

		//set the zoo feeding cost to reflect the cost after the new tiger is added
		zooFeedingCost += turtleArray[numberOfTurtles - 1].getFeedingCost();

		//free the memory for the saveTurtleAges array
		delete[] saveTurtleAges;
		std::cout << "A baby tiger has been added!" << std::endl;
	}
	//if dynamic array doesn't need to be adjusted, add a baby turtle to the array
	else {
		turtleArray[numberOfTurtles - 1].setAge(age);
		totalCash -= turtleArray[numberOfTurtles - 1].getCost();
		zooFeedingCost += turtleArray[numberOfTurtles - 1].getFeedingCost();
		std::cout << "A baby turtle has been added!" << std::endl;
	}

}

//getter for the feeding cost of the zoo
int zoo::getFeedingCost() {
	return zooFeedingCost;
}

void zoo::nextDay() {
	dailyProfit = 0;
	totalCash -= zooFeedingCost;
	std::cout << "The animals have been fed. Total cash left over: " << totalCash << std::endl;
	//adds a day to the age of all the tigers and gets the payoff per tiger, adds to total cash
	for (int i = 0; i < numberOfTigers; i++) {
		tigerArray[i].oneDayOlder();
		dailyProfit += tigerArray[i].getPayoff();
	}
	for (int i = 0; i < numberOfPenguins; i++) {
		penguinArray[i].oneDayOlder();
		dailyProfit += penguinArray[i].getPayoff();
	}
	for (int i = 0; i < numberOfTurtles; i++) {
		turtleArray[i].oneDayOlder();
		dailyProfit += turtleArray[i].getPayoff();
	}
	//subtract the feeding cost for the day
	totalCash -= zooFeedingCost;

	//generate a random number between 1 and 100 for the random event
	int randomNumber = rand() % 100 + 1;

	//a sickness occurs and an animal dies
	if (randomNumber >= 1 && randomNumber <= 30) {
		randomNumber = rand() % 3 + 1;
		//Tiger dies
		if (randomNumber == 1 && numberOfTigers > 0) {
			std::cout << "A tiger has died!" << std::endl;
			//random number between 1 and number of tigers
			int randomTiger = rand() % numberOfTigers + 1;
			//dynamic array to save tiger ages
			int* saveTigerAges = new int[numberOfTigers - randomTiger];
			//save all tiger ages AFTER the one being removed
			for (int i = 0; i < numberOfTigers - randomTiger; i++) {
				saveTigerAges[i] = tigerArray[randomTiger + i].getAge();
			}
			//add the tiger ages back into the array overwriting the old one
			for (int i = 0; i < numberOfTigers - randomTiger; i++) {
				tigerArray[randomTiger - 1 + i].setAge(saveTigerAges[i]);
			}
			//decrease the number of tigers at the zoo
			numberOfTigers -= 1;
			zooFeedingCost -= penguinArray[0].getFeedingCost();
			delete[] saveTigerAges;
		}
		//Penguin dies
		else if (randomNumber == 2 && numberOfPenguins > 0) {
			std::cout << "A penguin has died!" << std::endl;
			//random number between 1 and number of penguins
			int randomPenguin = rand() % numberOfPenguins + 1;
			//dynamic array to save penguin ages
			int* savePenguinAges = new int[numberOfPenguins - randomPenguin];
			//save all penguin ages AFTER the one being removed
			for (int i = 0; i < numberOfPenguins - randomPenguin; i++) {
				savePenguinAges[i] = penguinArray[randomPenguin + i].getAge();
			}
			//add the penguin ages back into the array overwriting the old one
			for (int i = 0; i < numberOfPenguins - randomPenguin; i++) {
				penguinArray[randomPenguin - 1 + i].setAge(savePenguinAges[i]);
			}
			//decrease the number of penguins at the zoo
			numberOfPenguins -= 1;
			zooFeedingCost -= penguinArray[0].getFeedingCost();
			delete[] savePenguinAges;
		}
		//Turtle dies
		else if (randomNumber == 3 && numberOfTurtles > 0) {
			std::cout << "A turtle has died!" << std::endl;
			//random number between 1 and number of turtles
			int randomTurtle = rand() % numberOfTurtles + 1;
			//dynamic array to save penguin ages
			int* saveTurtleAges = new int[numberOfTurtles - randomTurtle];
			//save all turtle ages AFTER the one being removed
			for (int i = 0; i < numberOfTurtles - randomTurtle; i++) {
				saveTurtleAges[i] = turtleArray[randomTurtle + i].getAge();
			}
			//add the turtle ages back into the array overwriting the old one
			for (int i = 0; i < numberOfTurtles - randomTurtle; i++) {
				turtleArray[randomTurtle - 1 + i].setAge(saveTurtleAges[i]);
			}
			//decrease the number of penguins at the zoo
			numberOfTurtles -= 1;
			zooFeedingCost -= turtleArray[0].getFeedingCost();
			delete[] saveTurtleAges;
		}
	}

	//there is a boom in zoo attendence
	else if (randomNumber > 30 && randomNumber <= 40) {
		int randomBonus = 0;
		randomBonus = rand() % 250 + 250;
		std::cout << "You received a random bonus of " << randomBonus << " dollars per tiger!" << std::endl;
		for (int i = 0; i < numberOfTigers; i++) {
			//random bonus between 250 and 500
			randomBonus = rand() % 250 + 250;
			dailyProfit += randomBonus;
		}
	}

	//a baby is born
	else if (randomNumber > 40 && randomNumber <= 60) {
		int tigerCounter = 0;
		int penguinCounter = 0;
		int turtleCounter = 0;
		bool babyLoop = true;

		//check to see if there are any tigers, penguins or turtles that can have a baby
		for (int i = 0; i < numberOfTigers; i++) {
			if (tigerArray[i].getAge() >= 3) {
				tigerCounter++;
			}
		}
		for (int i = 0; i < numberOfPenguins; i++) {
			if (penguinArray[i].getAge() >= 3) {
				penguinCounter++;
			}
		}
		for (int i = 0; i < numberOfTurtles; i++) {
			if (turtleArray[i].getAge() >= 3) {
				turtleCounter++;
			}
		}

		//if none of the animals are old enough to give birth, says that none can give birth and then
		//nothing happens (option 4)
		if (tigerCounter == 0 && penguinCounter == 0 && turtleCounter == 0) {
			std::cout << "No parents are old enough to give birth!  :(" << std::endl;
			babyLoop = false;
		}

		//if there is an animal able to give birth, pick an animal at random and have it give birth
		while (babyLoop) {
			int randomAnimal = rand() % 3 + 1;
			if (randomAnimal == 1 && tigerCounter > 0) {
				std::cout << "One of your tigers gave birth!" << std::endl;
				addTiger(0);
				babyLoop = false;
			}
			else if (randomAnimal == 2 && penguinCounter > 0) {
				std::cout << "One of your penguins gave birth!" << std::endl;
				for (int i = 0; i < penguinArray[0].getNumberOfBabies(); i++) {
					addPenguin(0);
				}
				babyLoop = false;
			}
			else if (randomAnimal == 3 && turtleCounter > 0) {
				std::cout << "One of your turtles gave birth!" << std::endl;
				for (int i = 0; i < turtleArray[0].getNumberOfBabies(); i++) {
					addTurtle(0);
				}
				babyLoop = false;
			}

		}
	}
	
	//add daily profit to total cost
	totalCash += dailyProfit;
	std::cout << "Daily Profit: " << dailyProfit << std::endl;
	//subtract the feeding cost from the 
	std::cout << "Cash at end of day: " << totalCash << std::endl;
}

int zoo::getCash() {
	return totalCash;
}