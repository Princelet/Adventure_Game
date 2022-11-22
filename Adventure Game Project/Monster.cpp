#include "Monster.h"

Monster::Monster()
	: name("")
	, description("")
	, health(1)
	, attack(1)
{
}

Monster::~Monster()
{
}

void Monster::SetName(std::string newName)
{
	name = newName;
}

void Monster::SetDescription(std::string newDesc)
{
	description = newDesc;
}
