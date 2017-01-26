#pragma once
#include "ComChest.h"
#include "Tax.h"
#include "Player.h"
#include "JailCard.h"
#include <iostream>
#include <ctime>

using namespace std;

ComChest::ComChest(std::string name) : Tile(name, 0)
{
	this->name = name;
}

void ComChest::tileAction()
{
}

void ComChest::performAction(Player* a, std::vector<Player *> players)
{
	cout << "\nYou have landed on a Community Chest tile.";
	cout << "\nYou draw a card.";
	int num;
	srand(time(NULL));
	num = (1 + (rand() % 3));
	if (num == 1) {
		cout << "\nYou have picked up a Get out of Jail Free card!\n";
		if (a->getJailCards() > 0) {
			cout << "Unfortunately, you already have one and so you must discard this one.\n";
		}
		else {
			JailCard x("Get out of Jail", 0);
			a->inv.push_back(&x);
			cout << "\nThe card has been added to your inventory. \n";
		}
	}
	else if (num == 2) {
		cout << "\nYou have picked up a card that charges you 200. Whoops!\n";
		a->subMoney(200);
		cout << "Your balance: " << a->getBalance();
	}
	else if (num == 3) {
		cout << "\nYou have picked up a card that gives you 300! Yay!\n";
		a->addMoney(300);
		cout << "Your balance: " << a->getBalance();
	}
	else {
		cout << "\n\nError in ComChest performAction\n";
	}

}


