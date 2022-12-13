#include "Player.h"
#include "Area.h"
#include "Item.h"
#include <iostream>
#include <algorithm>

Player::Player()
	: Creature("Player", "You!", 1, 1)
	, currentArea(nullptr)
{
}

Player::Player(int newHealth, int newAttack)
	: Creature("the Legendary Adventurer", "You!", newHealth, newAttack)
	, currentArea(nullptr)
{
}

Player::~Player()
{
}

void Player::Look()
{
	std::cout << "You are " << name << "." << std::endl;
	std::cout << "You have " << attack << "ATK and " << currentHealth << "/" << maxHealth << "HP." << std::endl;
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

void Player::SetLocation(Area* newLocation)
{
	currentArea = newLocation;
}

void Player::AddToInventory()
{
	std::cout << "The items in the room are: " << std::endl;
	for (int i = 0; i < GetLocation()->GetItems().size(); ++i)
	{
		std::cout << this->GetLocation()->GetItems()[i]->GetName() << std::endl;
	}

	std::string response;
	std::cout << "\n\nWhat do you want to pick up?" << std::endl;
	std::getline(std::cin, response);

	for (int i = 0; i < GetLocation()->GetItems().size(); ++i)
	{
		if (GetLocation()->GetItems()[i]->GetName() == response)
		{
			inventory.push_back(GetLocation()->GetItems()[i]);

			/*
			std::swap(GetLocation()->GetItems()[i], GetLocation()->GetItems().back());
			GetLocation()->GetItems().pop_back();
			*/
		}
	}

}

Area* Player::GetLocation()
{
	return currentArea;
}

std::string Player::GetLocationName()
{
	return currentArea->GetName();
}
