#pragma once
#include "Creature.h"

#include <string>
#include <vector>
#include "Area.h"

class Player : public Creature
{
public:
	Player();
	Player(int newHealth, int newAttack);
	~Player();

	void Look();

	void Go(Area* newArea);
	void SetLocation(Area* newLocation);
	Area* GetLocation();
	std::string GetLocationName();

private:
	std::vector<int> equipment;
	std::vector<int> inventory;

	Area* currentArea;
};

