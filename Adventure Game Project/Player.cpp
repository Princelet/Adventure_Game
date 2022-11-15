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
    for (int i = 0; i < currentArea->exits.size(); ++i)
    {
		if (newArea->name == currentArea->exits[i]->name)
		{
			currentArea = newArea;
			std::cout << "\n\nYou moved to " << currentArea->name << ".\n\n" << std::endl;
		}
		else
		{
			std::cout << "\n\nThis room does not have an exit to " << newArea->name << ".\n\n" << std::endl;
		}
    }

}
