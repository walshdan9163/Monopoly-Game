#pragma once
#include "Tile.h"

class Player;
class ComChest : public Tile 
{
public:
	ComChest(std::string name);
	virtual void tileAction();
	virtual void performAction(Player* a, std::vector<Player *> players);
	virtual ~ComChest() = default;

private:
	std::string name;

};