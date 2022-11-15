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

void printMonster(std::string name, std::string desc, int ATK, int HP)
{
    std::cout << "The item is a(n) " << name << ".\n"
        << "Description: " << desc
        << "It has " << HP << "HP.\n"
        << "It's attack is " << ATK << ".\n\n";
}

int main()
{
    std::string playerResponse = "";

    Player player;
    player.health = 100;
    player.attack = 10;
    player.equipment;
    player.inventory;


    Item potion;
    Item key;
    Item rock;
    potion.name = "Potion";
    potion.description = "A healing potion. Restores 50 health.";
    key.name = "Small Key";
    key.description = "A small key to unlock a locked door.";
    rock.name = "Small Rock";
    rock.description = "A small rock found on the ground.";


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


    Area roomA;
    Area roomB;
    Area roomC;
    roomA.name = "Room A";
    roomA.description = "A square room filled with pebbles and rocks.";
    roomA.contents.push_back(&bones);
    roomA.contents.push_back(&vines);
    roomA.exits.push_back(&roomB);
    roomA.exits.push_back(&roomC);

    roomB.name = "Room B";
    roomB.description = "A long room that is empty besides a few old pieces of furniture.";
    roomB.contents.push_back(&chest);
    roomB.exits.push_back(&roomA);

    roomC.name = "Room C";
    roomC.description = "A compact room filled with foliage and broken equipment.";
    roomC.contents.push_back(&vines);
    roomC.contents.push_back(&chest);
    roomC.exits.push_back(&roomA);



    player.currentArea = &roomA;
    player.currentArea->LookAround();

    do
    {
        std::cout << "\n\nWhat do you want to do?" << std::endl;
        std::getline(std::cin, playerResponse);

        if (playerResponse == "look")
        {
            player.currentArea->LookAround();
        }
        else if (playerResponse == "go")
        {
            player.currentArea = player.currentArea->AttemptGo();

            std::cout << "\nYou are now in " << player.currentArea->name << ".\n\n" << std::endl;
        }
        else if (playerResponse == "examine")
        {
            player.currentArea->Examine();
        }
        else
        {
            std::cout << "\n\nThat don't work so good!\n\n" << std::endl;
        }

    } while (playerResponse != "escape");

}