#pragma once

#include <string>
#include <vector>
#include "Area.h"

class Player
{
public:

	Player();
	~Player();

	void Go(Area* newArea);

	int health;
	int attack;
	std::vector<int> equipment;
	std::vector<int> inventory;

	Area* currentArea;
};

