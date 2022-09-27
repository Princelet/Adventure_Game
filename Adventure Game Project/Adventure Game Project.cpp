// Adventure Game Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Player.h"
#include "Item.h"
#include "Area.h"
#include "Feature.h"
#include "Monster.h"

void printPlayer(int HP, int ATK, std::vector<std::string> equip, std::vector<std::string> inv)
{
    std::cout << "You currently have " << HP << "HP.\n"
        << "Your attack is " << ATK << ".\n\n"
        << "Your equipment is currently:\n";

        for (int i = 0; i < equip.size(); ++i)
        {
            std::cout << equip[i] << "\n";
        }

        std::cout << "\nYour inventory currently contains:\n";

        for (int i = 0; i < inv.size(); ++i)
        {
            std::cout << inv[i] << "\n";
        }
}

void printItem(std::string name, std::string desc)
{
    std::cout << "The item is a(n) " << name << ".\n"
        << "Description: " << desc << "\n\n";
}

void printArea(std::string name, std::string desc,
    std::vector<std::string> contents, std::vector<std::string> exits)
{
    std::cout << "This area is " << name << ".\n"
        << "Description: " << desc << "\n\n"
        << "This room contains:\n";

    for (int i = 0; i < contents.size(); ++i)
    {
        std::cout << contents[i] << "\n";
    }

    std::cout << "\nThe room has exits in the directions:\n";

    for (int i = 0; i < exits.size(); ++i)
    {
        std::cout << exits[i] << "\n";
    }
}

void printFeature(std::string name, std::string desc)
{
    std::cout << "The deature is a(n) " << name << ".\n"
        << "Description: " << desc << "\n\n";
}

void printMonster(std::string name, std::string desc, int ATK, int HP)
{
    std::cout << "The item is a(n) " << name << ".\n"
        << "Description: " << desc
        << "It has " << HP << "HP.\n"
        << "It's attack is " << ATK << ".\n\n";
}

int main()
{
    Player player;
    player.health = 100;
    player.attack = 10;
    player.equipment;
    player.inventory;
    // unsure how to add to vector outside


    Item potion;
    Item key;
    Item rock;
    potion.name = "Potion";
    potion.description = "A healing potion. Restores 50 health.";
    key.name = "Small Key";
    key.description = "A small key to unlock a locked door.";
    rock.name = "Small Rock";
    rock.description = "A small rock found on the ground.";


    Area roomA;
    Area roomB;
    Area roomC;
    roomA.name = "Room A";
    roomA.description = "A square room filled with pebbles and rocks.";
    roomA.contents;
    roomA.exits;


    Feature vines;
    Feature chest;
    Feature bones;
    vines.name = "Vines";
    vines.description = "These vines cover the walls of the room.";
    chest.name = "Opened Chest";
    chest.description = "This chest looks to have been looted long ago.";
    bones.name = "Cracked Bones";
    bones.description = "The bones laying on the ground are cracked and covered in web.";


    Monster goblin;
    Monster bat;
    Monster skeleton;
    goblin.name = "Goblin Warrior";
    goblin.description = "A frail goblin warrior. Small and nimble.";
    bat.name = "Cave Bat";
    bat.description = "A little guy.";
    skeleton.name = "Skeleton Knight";
    skeleton.description = "A tough armoured knight of the undead.";
}