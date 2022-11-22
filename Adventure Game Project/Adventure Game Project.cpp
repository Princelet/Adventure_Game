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
    player.SetHealth(100);
    player.SetAttack(10);

    Item potion;
    Item key;
    Item rock;
    potion.SetName("Potion");
    potion.SetDescription("A healing potion. Restores 50 health.");
    key.SetName("Small Key");
    key.SetDescription("A small key to unlock a locked door.");
    rock.SetName("Small Rock");
    rock.SetDescription("A small rock found on the ground.");


    Feature vines;
    Feature chest;
    Feature bones;
    vines.SetName("Vines");
    vines.SetDescription("These vines cover the walls of the room.");
    chest.SetName("Opened Chest");
    chest.SetDescription("This chest looks to have been looted long ago.");
    bones.SetName("Cracked Bones");
    bones.SetDescription("The bones laying on the ground are cracked and covered in web.");


    Monster goblin;
    Monster bat;
    Monster skeleton;
    goblin.SetName("Goblin Warrior");
    goblin.SetDescription("A frail goblin warrior. Small and nimble.");
    bat.SetName("Cave Bat");
    bat.SetDescription("A little guy.");
    skeleton.SetName("Skeleton Knight");
    skeleton.SetDescription("A tough armoured knight of the undead.");


    Area roomA;
    Area roomB;
    Area roomC;
    roomA.SetName("Room A");
    roomA.SetDescription("A square room filled with pebbles and rocks.");
    roomA.AddContents(&bones);
    roomA.AddContents(&vines);
    roomA.AddExits(&roomB);
    roomA.AddExits(&roomC);

    roomB.SetName("Room B");
    roomB.SetDescription("A long room that is empty besides a few old pieces of furniture.");
    roomB.AddContents(&chest);
    roomB.AddExits(&roomA);

    roomC.SetName("Room C");
    roomC.SetDescription("A compact room filled with foliage and broken equipment.");
    roomC.AddContents(&vines);
    roomC.AddContents(&chest);
    roomC.AddExits(&roomA);



    player.SetLocation(&roomA);
    player.GetLocation()->LookAround();

    do
    {
        std::cout << "\n\nWhat do you want to do?" << std::endl;
        std::getline(std::cin, playerResponse);

        if (playerResponse == "look")
        {
            player.GetLocation()->LookAround();
        }
        else if (playerResponse == "go")
        {
            player.SetLocation(player.GetLocation()->AttemptGo());

            std::cout << "\nYou are now in " << player.GetLocationName() << ".\n\n" << std::endl;
        }
        else if (playerResponse == "examine")
        {
            player.GetLocation()->Examine();
        }
        else if (playerResponse == "escape")
        {
            std::cout << "\n\nThe floor beneath you crumbles.\n\n" << std::endl;
            std::cout << "\n\nYou fall.\n\n" << std::endl;
        }
        else
        {
            std::cout << "\n\nThat don't work so good!\n\n" << std::endl;
        }

    } while (playerResponse != "escape");

}