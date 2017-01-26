#pragma once
#include "Utility.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <time.h>

using namespace std;

class Player;
Utility::Utility(std::string name, int price) : Tile(name, price)
{
	this->name = name;
	this->value = price;
	this->owned = 0;
}

void Utility::tileAction()
{
}

void Utility::performAction(Player* a, std::vector<Player *> players)
{
	if (this->owned == 0) {
		string ans;
		if (this->name == "Water Works") {
			cout << "You have landed on Water Works.\nWould you like to purchase it for " << this->value << "?";
			cin >> ans;
			if (ans == "y" || ans == "Y") {
				a->inv.push_back(this);
				a->subMoney(this->value);
				cout << "You have chosen to purchase Water Works.";
				a->getInventory();
			}
			else {
				cout << "You have chosen not to purchase Water Works.";
			}
			if (this->name == "Electric Company") {
				cout << "You have landed on Electric Company. \nWould you like to purchase it for " << this->value << "?";
				cin >> ans;
				if (ans == "y" || ans == "Y") {
					a->inv.push_back(this);
					a->subMoney(this->value);
					cout << "You have chosen to purchase Electric Company.";
					a->getInventory();
				}
				else {
					cout << "You have chosen not to purchase Electric Company.";
				}
			}
		}
	}
	else {
		string other = "";
		if (this->name == "Water Works") {
			other = "Electric Company";

		}
		else {
			other = "Water Works";
		}
			for (int i = 0; i < players.size(); i++) {
				for (int j = 0; i < players[i]->inv.size(); j++) {
					if (players[i]->inv[j]->getName() == this->name) {
						cout << "You have landed on "<< this->name << " which is owned by " << players[i]->getName();
						for (int k = 0; i < players[i]->inv.size(); k++) {
							if (players[i]->inv[k]->getName() == other) {
								cout << "This player also owns " << other;
								cout << "You will have to roll a dice and pay the amount rolled times 10.";
								srand(time(NULL));
								int num = (1 + (rand() % 6));
								int sum = num * 10;
								players[i]->addMoney(sum);
								a->subMoney(sum);
							}
							else {
								cout << "This player does not own " << other;
								cout << "You will have to roll a dice and pay the amount rolled times 4.";
								srand(time(NULL));
								int num = (1 + (rand() % 6));
								int sum = num * 4;
								players[i]->addMoney(sum);
								a->subMoney(sum);
							}
						}
					}
				}
			
		}
	}
}