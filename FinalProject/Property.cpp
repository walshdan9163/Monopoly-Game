#pragma once
#include "Property.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Property::Property(std::string color, std::string name, int val) : Tile(name, val)
{
	this->name = name;
	this->color = color;
	this->value = val;
	this->owned = 0;
}
void Property::tileAction() {

}

void Property::performAction(Player* player, std::vector<Player *> players) {
	cout << "You landed at " << this->name << ".";
	if (this->owned == 0) {
		cout << "\nColor: " << this->color << "\nValue: " << this->value;
		string ans = "";
		while(ans != "y" && ans != "n"){
			cout << "\n\nWould you like to purchase this property? (y/n): ";
			cin >> ans;
		}
		if (ans == "y" || ans == "Y") {
			this->owned = 1;
			player->subMoney(this->value);
			cout << "\nYou now own " << this->name << "!\n";
			cout << "Your new balance is " << player->getBalance() << "\n";
			player->inv.push_back(this);
			cout << "Your Inventory: ";
			for (int i = 0; i < player->inv.size(); i++) {
				Tile * x = player->inv[i];
				cout << "\n" << x->getName();
			
			}
			cout << "\n";
		}
		else{
			cout << "\nYou selected not to purchase this property.\n" ;
		}
	}
	else if(this->owned == 1) {
		cout << "\nYou have landed on a space that is owned. ";
		for (int i = 0; i < players.size(); i++) {
			for (int j = 0; j < players[i]->inv.size(); j++) {
				if (this->name == players[i]->inv[j]->getName()) {
					cout << "\nThis property is owned by " << players[i]->getName();
					cout << "\nYou have been charged " << this->value << "by the owner.\n\n";
					player->subMoney(this->getValue());
					players[i]->addMoney(this->getValue());
				}
			}
		}
	}
	else {
		cout << "\nThis property is mortaged.\nThere is nothing to do here.";
	}
}

std::string Property::getName()
{
	return this->name;
}

int Property::getValue()
{
	return this->value;
}
