#pragma once
#include "Creature.h"

#include <string>

class Monster : public Creature
{
public:
	Monster();
	Monster(std::string newName, std::string newDescription, int newHealth, int newAttack);
	~Monster();
};

