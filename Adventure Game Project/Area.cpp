#include "Area.h"
#include "Player.h"
#include "Feature.h"
#include "Monster.h"
#include "Item.h"
#include <iostream>
#include <algorithm>

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

    ListContents();
    ListItems();
    ListExits();
    ListLockedExits();
}

Area* Area::AttemptGo()
{
    ListExits();

    std::string response;
    std::cout << "\nGo where?" << std::endl;
    std::getline(std::cin, response);

    Area* checkedExit = nullptr;
    checkedExit = CheckExits(response);
    if (checkedExit == nullptr)
    {
        checkedExit = CheckLockedExits(response);
    }
    return checkedExit;
}

void Area::AttemptUnlock(Player* player)
{
    Item* hasKey = nullptr;
    Area* checkExit = nullptr;
    hasKey = player->CheckInv("Small Key");

    if (hasKey != nullptr)
    {
        ListLockedExits();
        std::string response;
        do {
            std::cout << "\nWhat do you want to unlock? (Type 'stop' to return)" << std::endl;
            std::getline(std::cin, response);

            checkExit = CheckLockedExits(response);
            if (checkExit != nullptr)
            {
                UnlockExit(checkExit);
            }

        } while (response != "stop");
    }
    else
    {
        std::cout << "\nYou have no keys!" << std::endl;
    }
}

void Area::Examine()
{
    ListContents();
    ListItems();

    std::string response;
    Thing* exObj = nullptr;

    do
    {
        std::cout << "\nWhat would you like to look at? (Type 'stop' to finish examining)\n" << std::endl;
        std::getline(std::cin, response);

        if (response != "stop")
        {
            exObj = CheckContents(response);
            if (exObj == nullptr)
            {
                exObj = CheckItems(response);
            }

            std::cout << exObj->GetDescription() << std::endl;
        }

    } while (response != "stop");

    exObj = nullptr;
}

void Area::Fight(Player* player)
{
    bool hasRock = false;
    std::cout << "There is a " << enemy->GetName() << " in the room!\n" << std::endl;
    enemy->Look();

    do {
        std::string response;
        std::cout << "What do you do? (Type 'commands' for a list)" << std::endl;
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
        if (response == "commands")
        {
            std::cout << std::endl;
            std::cout << "All commands are case sensitive." << std::endl;
            std::cout << std::endl;
            std::cout << "The battle commands are:" << std::endl;
            std::cout << "'fight' - Enter an auto-battle sequence until either participant dies." << std::endl;
            std::cout << "'throw rock' - Use a distraction item. The battle will automatically end." << std::endl;
            std::cout << "'run' - Escape to a connected room. The enemy will be there when you return." << std::endl;
            std::cout << "'commands' - Displays this list." << std::endl;
            std::cout << std::endl;
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
            Item* rockCheck = nullptr;

            rockCheck = player->CheckInv("Small Rock");
            if (rockCheck != nullptr)
            {
                hasRock = true;
            }
            
            if (hasRock == true)
            {
                std::cout << "\nThe " << enemy->GetName() << " is distracted by the rock and chases it away." << std::endl;
                std::cout << "Since the opponent is gone, you win the fight.\n" << std::endl;
                player->RemoveInv(rockCheck);
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


void Area::ListItems()
{
    std::cout << "\nThe items in the room are: " << std::endl;
    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << "> " << this->items[i]->GetName() << std::endl;
    }
}

void Area::ListContents()
{
    std::cout << "\nThis features in the room are: " << std::endl;

    for (int i = 0; i < contents.size(); ++i)
    {
        std::cout << "> " << this->contents[i]->GetName() << std::endl;
    }
}

void Area::ListExits()
{
    std::cout << "\nThe room has exits to area(s): " << std::endl;

    for (int i = 0; i < exits.size(); ++i)
    {
        std::cout << "> " << this->exits[i]->GetName() << std::endl;
    }
}

void Area::ListLockedExits()
{
    std::cout << "\nThe room has locked doors to area(s): " << std::endl;

    for (int i = 0; i < lockedExits.size(); ++i)
    {
        std::cout << "> " << this->lockedExits[i]->GetName() << " (Requires Key)" << std::endl;
    }
}

Item* Area::CheckItems(std::string checker)
{
    for (int i = 0; i < items.size(); ++i)
    {
        if (items[i]->GetName() == checker)
        {
            return items[i];
        }
    }
    return nullptr;
}

Feature* Area::CheckContents(std::string checker)
{
    for (int i = 0; i < contents.size(); ++i)
    {
        if (contents[i]->GetName() == checker)
        {
            return contents[i];
        }
    }
    return nullptr;
}

Area* Area::CheckExits(std::string checker)
{
    for (int i = 0; i < exits.size(); ++i)
    {
        if (exits[i]->GetName() == checker)
        {
            return exits[i];
        }
    }
    return this;
}

Area* Area::CheckLockedExits(std::string checker)
{
    {
        for (int i = 0; i < lockedExits.size(); ++i)
        {
            if (lockedExits[i]->GetName() == checker)
            {
                return lockedExits[i];
            }
        }
    }

    return this;
}

void Area::RemoveItem(int itemPos)
{
    std::swap(items[itemPos], items.back());
    items.pop_back();
}

void Area::RemoveItem(Item* itemToRemove)
{
    std::string itemName = itemToRemove->GetName();
    for (int i = 0; i < items.size(); ++i)
    {
        if (items[i]->GetName() == itemName)
        {
            std::swap(items[i], items.back());
            items.pop_back();
        }
    }
}

void Area::UnlockExit(Area* newExit)
{
    std::string exit = newExit->GetName();
    for (int i = 0; i < exits.size(); ++i)
    {
        if (exits[i]->GetName() == newExit->GetName())
        {
            std::swap(exits[i], exits.back());
            exits.pop_back();
        }
    }
    exits.push_back(newExit);

}


void Area::AddContents(Feature* newContent)
{
    contents.push_back(newContent);
}

void Area::AddExits(Area* newExit)
{
    exits.push_back(newExit);
}

void Area::AddLockedExits(Area* newLExit)
{
    lockedExits.push_back(newLExit);
}

void Area::AddItem(Item* newItem)
{
    items.push_back(newItem);
}

void Area::AddMonster(Monster* newMonster)
{
    enemy = newMonster;
}


std::vector<Area*> Area::GetExits()
{
    return this->exits;
}

std::vector<Item*> Area::GetItems()
{
    return this->items;
}

std::vector<Item*> Area::SetItems()
{
    return items;
}

Monster* Area::GetMonster()
{
    return enemy;
}
