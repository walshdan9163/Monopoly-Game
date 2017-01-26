#pragma once
#include <string>
#include "Tile.h"

class Player;
class Tax : public Tile {
public:
	Tax(std::string name);
	virtual void tileAction() override;
	virtual void performAction(Player* a, std::vector<Player *> players);
	virtual ~Tax() = default;

private:
	std::string name;
	int price;
};
