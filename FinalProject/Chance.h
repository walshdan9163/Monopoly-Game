#pragma once
#include "Tile.h"
#include <string>

class Player;
class Chance : public Tile {
public:
	Chance(std::string name);
	virtual void tileAction();
	virtual void performAction(Player* a, std::vector<Player *> players);
	virtual ~Chance() = default;

private:
	std::string name;
};
