#pragma once
#include "Thing.h"

#include <string>

class Item : public Thing
{
public:
	Item();
	Item(std::string newName, std::string newDescription);
	~Item();
};

