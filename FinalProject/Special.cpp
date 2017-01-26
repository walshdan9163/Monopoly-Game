#pragma once
#include "Special.h"
#include "Tile.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Special::Special(std::string name) : Tile(name, 0)
{
	this->name = name;
}

void Special::tileAction()
{
		
}

void Special::performAction(Player* a, std::vector<Player *> players)
{
	if (this->name == "Go") {
		cout << "\nYou have landed on Go.\n";
	}
	else if (this->name == "Just Visiting / jail") {
		cout << "\nYou have landed on the jail tile, but you are just visiting!\n";
	}
	else if (this->name == "Free Parking") {
		cout << "\nYou have landed on Free Parking.\n";
	}
	else if (this->name == "Go directly to Jail") {
		cout << "\nUnfortunately, you must go to jail. Enjoy!\n";
		a->jail();
	}

}

std::string Special::getName()
{
	return this->name;
}
