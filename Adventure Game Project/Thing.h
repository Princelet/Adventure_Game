#pragma once
#include <string>

class Item;

class Thing
{
public:
	Thing();
	Thing(std::string newName, std::string newDescription);
	~Thing();

	void Look();
	void UseItem();

	// Getters
	std::string GetName();
	std::string GetDescription();

protected:
	std::string name;
	std::string description;
};

