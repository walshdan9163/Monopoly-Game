#pragma once
#include "Railroad.h"
#include "Player.h"
#include <iostream>

using namespace std;

Railroad::Railroad(std::string name, int value) : Tile(name, 0)
{
	this->name = name;
	this->value = value;
	this->owned = 0;
}

void Railroad::tileAction()
{
	/*
	cout << "You have landed on " << this->name << ".\n";
	if (this->bought = 1) {
		cout << "This railroad is owned by _____";
	}
	else {
		std::string ans;
		cout << "Would you like to buy this railroad? (y/n): ";
		cin >> ans;
		if (ans == "y" || ans == "Y") {

		}
	}*/
}

void Railroad::performAction(Player* player, std::vector<Player *> players)
{
	if (owned == 0) {
		string ans = "";
		cout << "\nYou have landed on an un-owned " << this->getName() << "!";
		while (ans != "y" && ans != "n") {
			cout << "\nWould you like to purchase this railroad for " << this->value << "? (y/n): ";
			cin >> ans;
			if (ans == "y") {
				cout << "\nCongratulations! This railroad is now yours. ";
				player->subMoney(this->value);
				cout << "\nYour balance is now " << player->getBalance() << "\n";
				player->inv.push_back(this);
				this->owned = 1;
			}
			else if (ans == "n") {
				cout << "\nYou have chosen not to purchase this railroad.\n";
			}
		}
	}
}

void Railroad::travel(Player * player)
{
	string ans;
	string option = "*****************************\na) Reading Railroad (Tile 5)\nb) Pennsylvania Railroad (Tile 15)\nc) B. & O. Railroad (Tile 25)\nd) Short Line (Tile 35)\n*****************************";
	cout << "\nYou have opted to travel by railroad.";
	cout << "\nWhich station would you like to travel to? " << "\n" << option;
	cin >> ans;
	if (ans == "a") {
		player->setCurPos(5);
	}
	else if (ans == "b") {
		player->setCurPos(15);
	}
	else if (ans == "c") {
		player->setCurPos(25);
	}
	else if (ans == "d") {
		player->setCurPos(35);
	}

}



