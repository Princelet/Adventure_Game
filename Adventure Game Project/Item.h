#pragma once

#include <string>

class Item
{
public:
	Item();
	~Item();

	void SetName(std::string newName);
	void SetDescription(std::string newDesc);

private:
	std::string name;
	std::string description;
};

