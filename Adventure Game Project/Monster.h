#pragma once

#include <string>

class Monster
{
public:
	Monster();
	~Monster();

	void SetName(std::string newName);
	void SetDescription(std::string newDesc);

private:
	std::string name;
	std::string description;
	int health;
	int attack;
};

