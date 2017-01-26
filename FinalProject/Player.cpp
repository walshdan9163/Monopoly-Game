#pragma once
#include "Player.h"
#include "Property.h"
#include "Tile.h"
#include "Special.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player(std::string name, std::string symbol)
{
	this->name = name;
	this->bankrupt = 0;
	this->oldPos = 0;
	this->curPos = 0;
	this->newPos = 0;
	this->bal = 1500;
	this->jailed = 0;
	this->doubleTry = 0;
	this->symbol = symbol;

}

void Player::move(int roll)
{
	this->curPos = this->curPos + roll;
}

void Player::addMoney(int amount)
{
	this->bal += amount;
}

void Player::setName(std::string newName)
{
	this->name = newName;
}

void Player::setJail(int n)
{
	this->jailed = n;
}

std::string Player::getName() 
{
	return this->name;
}

int Player::getCurPos()
{
	return this->curPos;
}

int Player::isJailed()
{
	return this->jailed;
}

void Player::jail()
{
	this->jailed = 1;
	this->curPos = 10;
	cout << "You are thrown in jail!";
}

void Player::setCurPos(int newPos)
{
	this->curPos = newPos;
}

void Player::newDoubleTry()
{
	this->doubleTry += 1;
}

void Player::doubleTryClear()
{
	this->doubleTry = 0;
}

int Player::getDoubleTry()
{
	return this->doubleTry;
}

int Player::getJailCards()
{
	int counter = 0;
	for (int i = 0; i < inv.size(); i++) {
		if (inv[i]->getName() == "Get out of Jail") {
			counter += 1;
		}
	}
	return counter;
}

void Player::removeJailCard()
{
	std::vector <Tile *> x;
	for (int i = 0; i < inv.size(); i++) {
		if (inv[i]->getName() == "Get out of Jail") {
			inv[i]->setName("");
		}
	}
}

std::string Player::getSymbol()
{
	return this->symbol;
}

int Player::getOldPos()
{
	return oldPos;
}

void Player::setOldPos(int curPos)
{
	this->oldPos = curPos;
}

void Player::setNewPos(int newPos)
{
	this->setOldPos(this->curPos);
	this->curPos = newPos;
}

int Player::getBalance()
{
	return this->bal;
}

void Player::subMoney(int x)
{
	this->bal -= x;
}

void Player::getInventory()
{
	for (int i = 0; i < inv.size(); i++) {
		cout << i+1 << inv[i]->getName() << "\n";
	}
}


