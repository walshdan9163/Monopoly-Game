#pragma once
#include "Tile.h"
#include <string>
#include <vector>

class Player;
class Property : public Tile {

public:
	Property(std::string color, std::string name, int val);
	virtual void tileAction();
	virtual void performAction(Player* a, std::vector<Player *> players);
	virtual ~Property() = default;
	std::string getName();
	int getValue();

private:
	std::string name;
	int value;
	std::string color;
	int owned;

};