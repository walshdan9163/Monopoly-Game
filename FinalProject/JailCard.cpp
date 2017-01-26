#pragma once
#include "JailCard.h"
#include "Tile.h"
#include <string>

JailCard::JailCard(std::string name, int val) : Tile(name, val)
{

}

void JailCard::tileAction()
{
}

void JailCard::setName(std::string name)
{
	this->name = name;
}
