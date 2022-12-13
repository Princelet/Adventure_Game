// Adventure Game Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Player.h"
#include "Item.h"
#include "Area.h"
#include "Feature.h"
#include "Monster.h"
#include "Potion.h"


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

    Player player(30, 5);

    Potion misty("Misty Potion", "A healing potion. Restores 10 health.", 10);
    Item key("Small Key", "A small key to unlock a locked door.");
    Item rock("Small Rock", "A small rock found on the ground. Could be used as a distraction.");

    Feature vines("Vines", "These vines cover the walls of the room.");
    Feature chest("Opened Chest", "This chest looks to have been looted long ago.");
    Feature bones("Cracked Bones", "The bones laying on the ground are cracked and covered in web.");

    Monster goblin("Goblin Warrior", "A frail goblin warrior. Small and nimble.", 5, 3);
    Monster bat("Cave Bat", "A little guy.", 3, 2);
    Monster skeleton("Skeleton Knight", "A tough armoured knight of the undead.", 10, 6);


    Area roomA("Room A", "A square room filled with pebbles and rocks.");
    Area roomB("Room B", "A long room that is empty besides a few old pieces of furniture.");
    Area roomC("Room C", "A compact room filled with foliage and broken equipment.");

    roomA.AddContents(&bones);
    roomA.AddContents(&vines);
    roomA.AddItem(&rock);
    roomA.AddExits(&roomB);
    roomA.AddExits(&roomC);

    roomB.AddContents(&chest);
    roomB.AddItem(&key);
    roomB.AddExits(&roomA);
    roomB.AddMonster(&skeleton);

    roomC.AddContents(&vines);
    roomC.AddContents(&chest);
    roomC.AddItem(&misty);
    roomC.AddExits(&roomA);



    player.SetLocation(&roomA);
    player.Look();
    player.GetLocation()->Look();

    do
    {
        std::cout << "\n\nWhat do you want to do?" << std::endl;
        std::getline(std::cin, playerResponse);

        if (playerResponse == "look")
        {
            player.GetLocation()->Look();
        }
        else if (playerResponse == "go")
        {
            player.SetLocation(player.GetLocation()->AttemptGo());

            std::cout << "\nYou are now in " << player.GetLocationName() << ".\n\n" << std::endl;

            if (player.GetLocation()->GetMonster() != nullptr)
            {
                player.GetLocation()->Fight(&player);
            }
        }
        else if (playerResponse == "examine")
        {
            player.GetLocation()->Examine();
        }
        else if (playerResponse == "pick up")
        {
            player.AddToInventory();
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