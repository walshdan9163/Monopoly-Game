#pragma once
#include "Chance.h"
#include "Player.h"
#include <iostream>
#include <ctime>

using namespace std;

Chance::Chance(std::string name) : Tile(name, 0)
{
	this->name = name;
}

void Chance::tileAction()
{
}

void Chance::performAction(Player* a, std::vector<Player *> players)
{
	cout << "\nYou have landed on a Chance tile.";
	cout << "\nYou will draw a card.\n";
	int num;
	srand(time(NULL));
	num = (1 + (rand() % 3));
	
	if (num == 1) {
		cout << "\nYou drew a card that moves you 5 spaces.";
		a->setCurPos(a->getCurPos() + 5);
		cout << "\nYour position is now " << a->getCurPos() << "\n";
	}
	else if (num == 2) {
		int b;
		cout << "\nYou drew a card that lets you choose your position! (1 - 40)";
		cout << "Where would you like to move?; ";
		cin >> b;
		a->setCurPos(b);
		cout << "Your position is now " << a->getCurPos() << "\n";
	}
	else if (num == 3) {
		cout << "\nYou drew a card that moves you to go and gives you 200!\n";
		a->addMoney(200);
		a->setCurPos(0);
		cout << "\nYour balance: " << a->getBalance() << "\n";
	}
	else {
		cout << "\n\nError in Chance performAction\n";
	}
}

