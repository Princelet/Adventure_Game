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

void CommandList()
{
    std::cout << std::endl;
    std::cout << "All commands are case sensitive." << std::endl;
    std::cout << std::endl;
    std::cout << "The standard commands are:" << std::endl;
    std::cout << "'inventory' - Look at the items the player has." << std::endl;
    std::cout << "'look' - Look around the current room." << std::endl;
    std::cout << "'examine' - Look at a specific item or feature." << std::endl;
    std::cout << "'pick up' - Look at the items the player has." << std::endl;
    std::cout << "'go' - Go to an available connected room." << std::endl;
    std::cout << "'unlock' - Unlock a locked door, requires key." << std::endl;
    std::cout << "'commands' - Displays this list." << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::string playerResponse = "";

    Player player(30, 5);

    Potion misty("Misty Potion", "A healing potion. Restores 10 health.", 10);
    Item key("Small Key", "A small key to unlock a locked door.");
    Item rock("Small Rock", "A small rock found on the ground. Could be used as a distraction.");
    Item treasure("Magical Ultimate Treasure of Destiny", "Useless shiny thing. Enjoy.");

    Feature vines("Vines", "These vines cover the walls of the room.");
    Feature chest("Opened Chest", "This chest looks to have been looted long ago.");
    Feature chest2("Soldered Chest", "This chest has been soldered shut. Too bad.");
    Feature bones("Cracked Bones", "The bones laying on the ground are cracked and covered in web.");

    Monster goblin("Goblin Warrior", "A frail goblin warrior. Small and nimble.", 5, 3);
    Monster bat("Cave Bat", "A little guy.", 3, 2);
    Monster skeleton("Skeleton Knight", "A tough armoured knight of the undead.", 10, 6);

    Area roomA("Room A", "A square room filled with pebbles and rocks.");
    Area roomB("Room B", "A long room that is empty besides a few old pieces of furniture.");
    Area roomC("Room C", "A compact room filled with foliage and broken equipment.");
    Area roomD("Room D", "A huge room. The treasure lies here.");

    roomA.AddContents(&bones);
    roomA.AddContents(&vines);
    roomA.AddItem(&rock);
    roomA.AddExits(&roomB);
    roomA.AddExits(&roomC);

    roomB.AddContents(&chest);
    roomB.AddItem(&key);
    roomB.AddExits(&roomA);
    roomB.AddLockedExits(&roomD);
    roomB.AddMonster(&skeleton);

    roomC.AddContents(&vines);
    roomC.AddContents(&chest);
    roomC.AddItem(&misty);
    roomC.AddExits(&roomA);

    roomC.AddContents(&chest2);
    roomC.AddContents(&chest);
    roomD.AddItem(&treasure);
    roomD.AddExits(&roomB);


    player.SetLocation(&roomA);
    player.Look();
    player.GetLocation()->Look();

    do
    {
        std::cout << "\nWhat do you want to do? (Type 'commands' for a list)" << std::endl;
        std::getline(std::cin, playerResponse);

        if (playerResponse == "look")
        {
            player.GetLocation()->Look();
        }
        else if (playerResponse == "go")
        {
            Area* checkedExit = player.GetLocation()->AttemptGo();

            player.SetLocation(checkedExit);

            std::cout << "\nYou are now in " << player.GetLocationName() << "." << std::endl;

            player.CheckEncounter();
        }
        else if (playerResponse == "unlock")
        {
            player.GetLocation()->AttemptUnlock(&player);
        }
        else if (playerResponse == "examine")
        {
            player.GetLocation()->Examine();
        }
        else if (playerResponse == "pick up")
        {
            player.AddToInventory();
        }
        else if (playerResponse == "inventory")
        {
            player.ItemList();
        }
        else if (playerResponse == "use")
        {
            player.UseItem();
        }
        else if (playerResponse == "commands")
        {
            CommandList();
        }
        else if (playerResponse == "escape")
        {
            std::cout << "\n\nThe floor beneath you crumbles.\n\n" << std::endl;
            std::cout << "\n\nYou fall.\n\n" << std::endl;
        }
        else
        {
            std::cout << "\nBad input! Try something else." << std::endl;
        }

    } while (playerResponse != "escape");

}