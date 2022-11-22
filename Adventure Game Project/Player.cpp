#include "Player.h"
#include "Area.h"
#include <iostream>

Player::Player()
	: health(100)
	, attack(1)
	, equipment()
	, inventory()
	, currentArea(nullptr)
{
}

Player::~Player()
{
}

void Player::Go(Area* newArea)
{
    for (int i = 0; i < currentArea->GetExits().size(); ++i)
    {
		if (newArea->GetName() == currentArea->GetExits()[i]->GetName())
		{
			currentArea = newArea;
			std::cout << "\n\nYou moved to " << currentArea->GetName() << ".\n\n" << std::endl;
		}
		else
		{
			std::cout << "\n\nThis room does not have an exit to " << newArea->GetName() << ".\n\n" << std::endl;
		}
    }

}

void Player::SetHealth(int newHealth)
{
	health = newHealth;
}

void Player::SetAttack(int newAttack)
{
	attack = newAttack;
}

void Player::SetLocation(Area* newLocation)
{
	currentArea = newLocation;
}

Area* Player::GetLocation()
{
	return currentArea;
}

std::string Player::GetLocationName()
{
	return currentArea->GetName();
}
