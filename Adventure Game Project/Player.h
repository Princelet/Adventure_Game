#pragma once

#include <string>
#include <vector>

class Player
{
public:
	int health;
	int attack;
	std::vector<int> equipment;
	std::vector<int> inventory;
};

