/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/04/2018
**Description: Project 2 - Header file for the menu class.  See individual function descriptions for more info.
*******************************************************************************************************************/
#include <string>

#ifndef MENU_HPP
#define MENU_HPP

class menu {

private:
	int numberOfMenuItems;
	std::string menuItems[4];	//update based on biggest number of menu items
public:
	menu();
	//prints the menu to the console
	void printMenu();
	//sets a new menu item
	void setMenuItem(std::string menuItem);
	//prints the menu with no 
	void printIntroMenu();

};

#endif