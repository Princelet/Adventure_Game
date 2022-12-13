#pragma once
#include "Thing.h"

class Creature : public Thing
{
public:
	Creature();
	Creature(std::string newName, std::string newDescription, int newHealth, int newAttack);
	~Creature();

	void Look();

	// Setter
	void SetCurrHealth(int newHealth);
	void ChangeHealth(int healthDiff);
	void SetMaxHealth(int newMaxHealth);
	void SetAttack(int newAttack);

	// Getter
	int GetCurrHealth();
	int GetMaxHealth();
	int GetAttack();

protected:
	int currentHealth;
	int maxHealth;
	int attack;
};

