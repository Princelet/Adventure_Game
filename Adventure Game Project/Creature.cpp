#include "Creature.h"
#include <iostream>

Creature::Creature()
	: Thing("", "")
	, currentHealth(1)
	, maxHealth(1)
	, attack(1)
{
}

Creature::Creature(std::string newName, std::string newDescription, int newHealth, int newAttack)
	: Thing(newName, newDescription)
	, currentHealth(newHealth)
	, maxHealth(newHealth)
	, attack(newAttack)
{
}

Creature::~Creature()
{
}

void Creature::Look()
{
	std::cout << "You observe the " << name << "." << std::endl;
	std::cout << description << std::endl;
	std::cout << "It has " << attack << "ATK and " << currentHealth << "HP." << std::endl;
}

void Creature::SetCurrentHealth(int newHealth)
{
	currentHealth = newHealth;
	if (currentHealth > maxHealth) 
	{
		currentHealth = maxHealth;
	}
}

void Creature::ChangeHealth(int healthDiff)
{
	currentHealth += healthDiff;
	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
}

void Creature::SetMaxHealth(int newMaxHealth)
{
	maxHealth = newMaxHealth;
}

void Creature::SetAttack(int newAttack)
{
	attack = newAttack;
}

int Creature::GetCurrHealth()
{
	return currentHealth;
}

int Creature::GetMaxHealth()
{
	return maxHealth;
}

int Creature::GetAttack()
{
	return attack;
}
