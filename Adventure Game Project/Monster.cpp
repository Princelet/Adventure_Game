#include "Monster.h"

Monster::Monster()
	: Creature("Dummy", "A beat up training dummy.", 1, 1)
{
}

Monster::Monster(std::string newName, std::string newDescription, int newHealth, int newAttack)
	: Creature(newName, newDescription, newHealth, newAttack)
{
}

Monster::~Monster()
{
}

