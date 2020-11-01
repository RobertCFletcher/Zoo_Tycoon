/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2- Main class for the program.  Creates the zoo, verifies user selections.
*******************************************************************************************************************/

#include "zoo.hpp"
#include "menu.hpp"
#include <iostream>
#include <sstream>

int main() {
	int someNumber, animalSelection;
	menu m2, m3, m4;
	zoo z;
	bool myLoop = true;
	bool secondaryLoop = true;

	//starting menu
	m2.setMenuItem("Start Game");
	m2.setMenuItem("Exit");

	//game menu
	m3.setMenuItem("Check Stats");
	m3.setMenuItem("Add Animal");
	m3.setMenuItem("Next Day");
	m3.setMenuItem("Quit");

	//animal type menu
	m4.setMenuItem("Add Tiger");
	m4.setMenuItem("Add Penguin");
	m4.setMenuItem("Add Turtle");


	//prints the starting menu and verifies whether the selection is valid
	while (myLoop) {
		//prints the starting menu
		m2.printMenu();
		std::string s1;
		std::getline(std::cin, s1);
		std::stringstream stream1(s1);
		//checks to make sure only an integer value is being read in
		if (stream1 >> someNumber && !(stream1 >> s1) && (someNumber == 1 || someNumber == 2)) {
			myLoop = false;
			break;
		}
	}
	myLoop = true;
	
	//if the user selected to play
	if (someNumber == 1) {
		//gets the initial number of tigers to start
		while (myLoop) {
			std::cout << "Please enter either 1 or 2 for number of tigers to start. " << std::endl;
			std::string s1;
			std::getline(std::cin, s1);
			std::stringstream stream1(s1);
			//checks to make sure only an integer value is being read in
			if (stream1 >> animalSelection && !(stream1 >> s1) && (animalSelection >= 1 || animalSelection == 2)) {
				if (animalSelection == 1) {
					z.addTiger(1);
					myLoop = false;
				}
				else if (animalSelection == 2) {
					z.addTiger(1);
					z.addTiger(1);
					myLoop = false;
				}
			}
		}
		//gets the number of starting penguins
		myLoop = true;
		while (myLoop) {
			std::cout << "Please enter either 1 or 2 for number of penguins to start. " << std::endl;
			std::string s1;
			std::getline(std::cin, s1);
			std::stringstream stream1(s1);
			//checks to make sure only an integer value is being read in
			if (stream1 >> animalSelection && !(stream1 >> s1) && (animalSelection >= 1 || animalSelection == 2)) {
				if (animalSelection == 1) {
					z.addPenguin(1);
					myLoop = false;
				}
				else if (animalSelection == 2) {
					z.addPenguin(1);
					z.addPenguin(1);
					myLoop = false;
				}
			}
		}
		//gets the number of starting turtles
		myLoop = true;
		while (myLoop) {
			std::cout << "Please enter either 1 or 2 for number of turtles to start. " << std::endl;
			std::string s1;
			std::getline(std::cin, s1);
			std::stringstream stream1(s1);
			//checks to make sure only an integer value is being read in
			if (stream1 >> animalSelection && !(stream1 >> s1) && (animalSelection >= 1 || animalSelection == 2)) {
				if (animalSelection == 1) {
					z.addTurtle(1);
					myLoop = false;
				}
				else if (animalSelection == 2) {
					z.addTurtle(1);
					z.addTurtle(1);
					myLoop = false;
				}
			}
		}

		//start game loop
		myLoop = true;
		while (myLoop) {
			while (secondaryLoop) {
				std::cout << "Press 1 to buy an adult animal.  Press 2 to skip this step." << std::endl;
				int newAnimalSelection = 0;
				std::string s1;
				std::getline(std::cin, s1);
				std::stringstream stream1(s1);
				//checks to validate user input
				if (stream1 >> newAnimalSelection && !(stream1 >> s1) && (newAnimalSelection == 1 || newAnimalSelection == 2)) {
					//if the user wants to buy a new animal
					if (newAnimalSelection == 1) {
						int selection = 0;
						//prints the animal type menu
						m4.printMenu();
						std::string s2;
						std::getline(std::cin, s2);
						std::stringstream stream2(s2);
						if (stream2 >> selection && !(stream2 >> s2) && (selection >= 1 || selection <= 3)) {
							//if the user chooses to add an adult tiger
							if (selection == 1) {
								z.addTiger(3);
								secondaryLoop = false;
							}
							//if the user chooses to add an adult penguin
							else if (selection == 2) {
								z.addPenguin(3);
								secondaryLoop = false;
							}
							//if the user chooses to add an adult turtle
							else if (selection == 3) {
								z.addTurtle(3);
								secondaryLoop = false;
							}
						}
					}
					else if (newAnimalSelection == 2) {
						secondaryLoop = false;
					}
				}
			}

			//checks to see if the user wants to keep playing or not
			std::cout << "Press 1 to keep playing.  Press 2 to end the game." << std::endl;
			int endGameSelection = 0;
			std::string s1;
			std::getline(std::cin, s1);
			std::stringstream stream1(s1);
			//checks to validate user input
			if (stream1 >> endGameSelection && !(stream1 >> s1) && (endGameSelection == 1 || endGameSelection == 2)) {
				//if the user wants to keep playing
				if (z.getCash() < 0) {
					std::cout << "You ran out of cash and have lost the game!" << std::endl;
					myLoop = false;
				}
				else if (endGameSelection == 1) {
					z.nextDay();
					secondaryLoop = true;
				}
				//if the user wants to quit
				else if (endGameSelection == 2) {
					myLoop = false;
				}
			}
		}
	}

	//closes the zoo, clears all memory for the zoo's dynamic arrays
	z.closeZoo();
	return 0;
}