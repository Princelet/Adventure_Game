#include "Area.h"
#include "Player.h"
#include "Feature.h"
#include "Monster.h"
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

std::vector<Area*> Area::GetExits()
{
    return this->exits;
}


void Area::AddMonster(Monster* newMonster)
{
    enemy = newMonster;
}

Monster* Area::GetMonster()
{
    return enemy;
}

