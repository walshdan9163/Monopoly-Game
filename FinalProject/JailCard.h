#pragma once
#include <string>
#include "Tile.h"

class JailCard :public Tile {
public:
	JailCard(std::string name, int value);
	virtual void tileAction() override;
	void setName(std::string name);


private:
	std::string name;

};