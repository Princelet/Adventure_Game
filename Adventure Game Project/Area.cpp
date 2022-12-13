#include "Area.h"
#include "Player.h"
#include "Feature.h"
#include "Monster.h"
#include "Item.h"
#include <iostream>

Area::Area()
    : Thing("", "")
    , contents()
    , exits()
    , enemy(nullptr)
{
}

Area::Area(std::string newName, std::string newDescription)
    : Thing(newName, newDescription)
    , contents()
    , exits()
    , enemy(nullptr)
{
}

Area::~Area()
{
}

void Area::Look()
{
	std::cout << "\nYou look around " << this->GetName() << "." << std::endl;
    std::cout << this->GetDescription() << std::endl;

    // Contents
    std::cout << "\nYou see:" << std::endl;

    for (int i = 0; i < contents.size(); ++i)
    {
        std::cout << this->contents[i]->GetName() << std::endl;
    }

    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << this->items[i]->GetName() << std::endl;
    }

    // Areas
    std::cout << "\nThe room has exits to areas: " << std::endl;

    for (int i = 0; i < exits.size(); ++i)
    {
        std::cout << this->exits[i]->GetName() << std::endl;
    }
}

Area* Area::AttemptGo()
{
    std::cout << "\nThe room has exits to areas: " << std::endl;

    for (int i = 0; i < exits.size(); ++i)
    {
        std::cout << this->exits[i]->GetName() << std::endl;
    }

    std::string response;
    std::cout << "\nGo where?" << std::endl;
    std::getline(std::cin, response);

    for (int i = 0; i < exits.size(); ++i)
    {
        if (exits[i]->GetName() == response)
        {
            return exits[i];
        }
    }
    return this;
}

void Area::Examine()
{
    std::cout << "\nThis room contains: " << std::endl;

    for (int i = 0; i < contents.size(); ++i)
    {
        std::cout << this->contents[i]->GetName() << std::endl;
    }

    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << this->items[i]->GetName() << std::endl;
    }

    std::string response;

    do
    {
        std::cout << "\nWhat would you like to look at? (Type 'stop' to finish examining)\n" << std::endl;
        std::getline(std::cin, response);

        for (int i = 0; i < contents.size(); ++i)
        {
            if (contents[i]->GetName() == response)
            {
                std::cout << "\n" << contents[i]->GetDescription() << "\n" << std::endl;
            }
        }

        for (int i = 0; i < items.size(); ++i)
        {
            if (items[i]->GetName() == response)
            {
                std::cout << "\n" << items[i]->GetDescription() << "\n" << std::endl;
            }
        }

    } while (response != "stop");
}

void Area::Fight(Player* player)
{
    std::cout << "There is a " << enemy->GetName() << " in the room!\n" << std::endl;
    enemy->Look();

    do {
        std::string response;
        std::cout << "What do you do?" << std::endl;
        std::getline(std::cin, response);

        if (response == "fight")
        {

            do {

                std::cout << "The " << enemy->GetName() << " attacks!"
                    << " You take " << enemy->GetAttack() << " damage!" << std::endl;
                std::cout << "You attack the " << enemy->GetName() << "!"
                    << " You take " << player->GetAttack() << " damage!" << std::endl;

                enemy->ChangeHealth(-player->GetAttack());
                player->ChangeHealth(-enemy->GetAttack());

            } while (enemy->GetCurrHealth() > 0 || player->GetCurrHealth() > 0);

            if (enemy->GetCurrHealth() < 1)
            {

                std::cout << "\nYou defeated the " << enemy->GetName() << "!\n" << std::endl;
                enemy = nullptr;
                return;

            }

            if (player->GetCurrHealth() < 1)
            {

                std::cout << "\nYou lost to the " << enemy->GetName() << "!" << std::endl;
                std::cout << "You scramble away and hide until it leaves." << std::endl;
                return;
            }

        }

        if (response == "run")
        {
            do {
                player->SetLocation(player->GetLocation()->AttemptGo());
            } while (player->GetLocationName() == "Room B");
            std::cout << "You escaped to " << player->GetLocationName() << "." << std::endl;
            return;
        }

        if (response == "throw rock")
        {
            bool hasRock = false;
            for (int i = 0; i < items.size(); ++i)
            {
                if (items[i]->GetName() == "Small Rock")
                {
                    hasRock = true;
                }
            }
            
            if (hasRock == true)
            {
                std::cout << "\nThe " << enemy->GetName() << " is distracted by the rock and chases it as it falls through a crack." << std::endl;
                std::cout << "Since the opponent is gone, you win the fight.\n" << std::endl;
                enemy = nullptr;
                return;
            }
            else
            {
                std::cout << "\nYou don't have a rock!\n" << std::endl;
            }

        }
    } while (enemy != nullptr);
}

void Area::AddContents(Feature* newContent)
{
    contents.push_back(newContent);
}


void Area::AddExits(Area* newExit)
{
    exits.push_back(newExit);
}

void Area::AddItem(Item* newItem)
{
    items.push_back(newItem);
}

std::vector<Area*> Area::GetExits()
{
    return this->exits;
}

std::vector<Item*> Area::GetItems()
{
    return this->items;
}


void Area::AddMonster(Monster* newMonster)
{
    enemy = newMonster;
}


Monster* Area::GetMonster()
{
    return enemy;
}

