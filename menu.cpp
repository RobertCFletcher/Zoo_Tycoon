/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2- Menu class implementation file.  Sets different menu items and printMenu() prints the items
**	that were set in the menu.
*******************************************************************************************************************/

#include "menu.hpp"
#include <iostream>

menu::menu() {
	numberOfMenuItems = 0;
}

//prints the menu to the console
void menu::printMenu() {
	for (int i = 0; i < numberOfMenuItems; i++) {
		std::cout << i + 1 << " " << menuItems[i] << std::endl;
	}
}

//sets the menu item and allows for menu item manipulation
void menu::setMenuItem(std::string menuItem) {
	menuItems[numberOfMenuItems] = menuItem;
	numberOfMenuItems++;
}

//prints a menu without the numerics
void menu::printIntroMenu() {
	for (int i = 0; i < numberOfMenuItems; i++) {
		std::cout << menuItems[i] << std::endl;
	}
}