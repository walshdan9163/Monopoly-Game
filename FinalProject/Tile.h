#pragma once
#include <string>
#include <vector>

class Player;
class Tile {

public:
	Tile(std::string name, int val);
	virtual void tileAction();
	virtual void performAction(Player * a, std::vector<Player *> players);
	virtual ~Tile() = default;
	virtual void setName(std::string name);
	std::string getName();
	int owned;
	int value;

protected:
	std::string name;
};