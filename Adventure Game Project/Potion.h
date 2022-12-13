#pragma once
#include "Item.h"

#include <string>

class Player;

class Potion : public Item
{
public:
	Potion();
	Potion(std::string newName, std::string newDescription, int newAmount);
	~Potion();

	void Use();

private:
	int healingAmount;
	Player* itemOwner;
};

