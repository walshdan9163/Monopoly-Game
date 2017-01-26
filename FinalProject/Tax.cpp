#pragma once
#include "Tax.h"
#include "Player.h"
#include <iostream>

using namespace std;

Tax::Tax(std::string name) : Tile(name, 0)
{
	this->name = name;
	this->price = 200;
}

void Tax::tileAction()
{
}

void Tax::performAction(Player * player, std::vector<Player *> players)
{
	string x;
	system("CLS");
	cout << "You have landed on a Tax space, \nand the bank will collect $200 from you account. OK? (y/n)\n";
	cin >> x;
	player->subMoney(200);
}

