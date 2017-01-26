#pragma once
#include "Tile.h"
#include <string>

class Player;
class Special : public Tile {

public:
	Special(std::string name);
	virtual void tileAction();
	virtual void performAction(Player* a, std::vector<Player *> players);
	virtual ~Special() = default;
	std::string getName();
	
private:
	std::string name;

};
