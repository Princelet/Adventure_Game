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
	void SetHealth(int newHealth);
	void SetAttack(int newAttack);
	void SetLocation(Area* newLocation);
	Area* GetLocation();
	std::string GetLocationName();

private:
	int health;
	int attack;
	std::vector<int> equipment;
	std::vector<int> inventory;

	Area* currentArea;
};

