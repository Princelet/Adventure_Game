#pragma once

#include <string>

class Monster
{
public:

	Monster();
	~Monster();

	std::string name;
	std::string description;
	int health;
	int attack;
};

