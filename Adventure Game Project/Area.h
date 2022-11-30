#pragma once
#include "Thing.h"

#include <string>
#include <vector>

class Feature;
class Monster;
class Player;

class Area : public Thing
{
public:
	Area();
	Area(std::string newName, std::string newDescription);
	~Area();

	void Look();
	Area* AttemptGo();
	void Examine();
	void Fight(Player* player);

	// Getters
	std::vector<Area*> GetExits();
	Monster* GetMonster();

	// Setters
	void AddContents(Feature* newContent);
	void AddExits(Area* newExit);
	void AddMonster(Monster* newMonster);

private:
	std::vector<Feature*> contents;
	std::vector<Area*> exits;
	Monster* enemy;
};

