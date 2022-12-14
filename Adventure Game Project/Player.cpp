#include "Player.h"
#include "Area.h"
#include "Item.h"
#include <iostream>

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
	GetLocation()->ListItems();

	if (GetLocation()->GetItems().size() != 0)
	{
		std::string response;
		std::cout << "\n\nWhat do you want to pick up?" << std::endl;
		std::getline(std::cin, response);

		Item* toGet = nullptr;
		toGet = GetLocation()->CheckItems(response);

		inventory.push_back(toGet);
		GetLocation()->RemoveItem(toGet);
		toGet->SetOwner(this);
	}
	else
	{
		std::cout << "There's nothing to pick up!" << std::endl;
	}

}

Item* Player::CheckInv(std::string checker)
{
		for (int i = 0; i < inventory.size(); ++i)
		{
			if (inventory[i]->GetName() == checker)
			{
				return inventory[i];
			}
		}
	return nullptr;
}

void Player::ItemList()
{
	if (inventory.size() > 0)
	{
		std::cout << "The items you have are: " << std::endl;
		for (int i = 0; i < inventory.size(); ++i)
		{
			std::cout << "> " << this->inventory[i]->GetName() << std::endl;
		}
}
	else
	{
		std::cout << "You have no items." << std::endl;
	}
}

void Player::CheckEncounter()
{
	if (GetLocation()->GetMonster() != nullptr)
	{
		GetLocation()->Fight(this);
	}
}

void Player::UseItem()
{
	std::string response;
	Item* toUse = nullptr;

	do
	{
		ItemList();

		std::cout << "\nWhat do you want to use? (Type 'stop' to return)" << std::endl;
		std::getline(std::cin, response);

		if (response != "stop")
		{
			toUse = CheckInv(response);
			if (toUse != nullptr)
			{
				toUse->Use();
				RemoveInv(toUse);
			}
			else
			{
				std::cout << "\nYou don't have that!" << std::endl;
			}
		}

	} while (response != "stop");
}

void Player::RemoveInv(Item* toRemove)
{
	std::string itemName = toRemove->GetName();
	for (int i = 0; i < inventory.size(); ++i)
	{
		if (inventory[i]->GetName() == itemName)
		{
			std::swap(inventory[i], inventory.back());
			inventory.pop_back();
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
