#pragma once
#include "Thing.h"

#include <string>

class Player;

class Item : public Thing
{
public:
	Item();
	Item(std::string newName, std::string newDescription);
	~Item();
	
	virtual void Use();
	void SetOwner(Player* newOwner);

protected:
	Player* itemOwner;
};

