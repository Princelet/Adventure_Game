#pragma once
#include "Creature.h"

#include <string>
#include <vector>
#include "Area.h"

class Item;

class Player : public Creature
{
public:
	Player();
	Player(int newHealth, int newAttack);
	~Player();

	void Look();
	void Go(Area* newArea);
	void CheckEncounter();

	void AddToInventory();
	Item* CheckInv(std::string checker);
	void ItemList();
	void UseItem();
	void RemoveInv(Item* toRemove);

	// Setters
	void SetLocation(Area* newLocation);

	// Getters
	Area* GetLocation();
	std::string GetLocationName();

private:
	std::vector<Item*> equipment;
	std::vector<Item*> inventory;

	Area* currentArea;
};

