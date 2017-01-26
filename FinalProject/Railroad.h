#pragma once
#include <string>
#include "Tile.h"

class Player;
class Railroad : public Tile {
public:
	Railroad(std::string name, int value);
	virtual void tileAction();
	virtual void performAction(Player* a, std::vector<Player *> players);
	virtual ~Railroad() = default;
	virtual void travel(Player* a);

private:
	std::string name;
	int value;
	int owned;
};