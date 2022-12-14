#pragma once
#include "Thing.h"

#include <string>
#include <vector>

class Feature;
class Monster;
class Player;
class Item;

class Area : public Thing
{
public:
	Area();
	Area(std::string newName, std::string newDescription);
	~Area();

	void Look();
	Area* AttemptGo();
	void AttemptUnlock (Player* player);
	void Examine();
	void Fight(Player* player);

	void ListItems();
	void ListContents();
	void ListExits();
	void ListLockedExits();
	Item* CheckItems(std::string checker);
	Feature* CheckContents(std::string checker);
	Area* CheckExits(std::string checker);
	Area* CheckLockedExits(std::string checker);

	// Getters
	std::vector<Area*> GetExits();
	std::vector<Item*> GetItems();
	std::vector<Item*> SetItems();
	Monster* GetMonster();

	// Setters
	void AddContents(Feature* newContent);
	void AddExits(Area* newExit);
	void AddLockedExits(Area* newLExit);
	void AddMonster(Monster* newMonster);
	void AddItem(Item* newItem);
	void RemoveItem(int itemPos);
	void RemoveItem(Item* itemToRemove);
	void UnlockExit(Area* newExit);

private:
	std::vector<Feature*> contents;
	std::vector<Item*> items;
	std::vector<Area*> exits;
	std::vector<Area*> lockedExits;
	Monster* enemy;
};

