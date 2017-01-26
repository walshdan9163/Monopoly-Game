#pragma once
#include "Tile.h"
#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Tile::Tile(std::string name, int val)
{
	this->name = name;
	this->owned = 0;
	this->value = val;

}

void Tile::tileAction()
{
}

void Tile::performAction(Player * a, std::vector <Player *> players)
{
	cout << "\nIn tile's perform action\n";
}


void Tile::setName(std::string name)
{
	this->name = name;
}

std::string Tile::getName()
{
	return this->name;
}


