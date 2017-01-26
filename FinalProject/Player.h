#pragma once
#include <string>
#include <vector>
#include "Tile.h"
#include "Property.h"
#include "Special.h"

class Player {
public:
	Player(std::string name, std::string symbol);
	~Player() = default;
	void move(int roll);
	void addMoney(int amount);
	void setName(std::string newName);
	void setJail(int n);
	std::string getName();
	int getCurPos();
	int isJailed();
	void jail();
	void setCurPos(int newPos);
	void newDoubleTry();
	void doubleTryClear();
	int getDoubleTry();
	int getJailCards();
	void removeJailCard();
	std::string getSymbol();
	int getOldPos();
	void setOldPos(int curPos);
	void setNewPos(int newPos);
	int getBalance();
	std::vector<Tile *> inv;
	void subMoney(int x);
	void getInventory();

private:
	int bankrupt;
	std::string name;
	std::string symbol;
	int curPos;
	int newPos;
	int bal;
	
	int jailed;
	int doubleTry;
	int oldPos;


};
