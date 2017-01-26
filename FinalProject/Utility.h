#pragma once
#include <string>
#include "Tile.h"
#include "Player.h"

class Player;
class Utility : public Tile {
public:
	Utility(std::string name, int price);
	virtual void tileAction();
	virtual void performAction(Player* a, std::vector<Player *> players);
private:
	std::string name;
	int value;
	int owned;
};
