#include "Item.h"

Item::Item()
	: name("")
	, description("")
{
}

Item::~Item()
{
}

void Item::SetName(std::string newName)
{
	name = newName;
}

void Item::SetDescription(std::string newDesc)
{
	description = newDesc;
}
