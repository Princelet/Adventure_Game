#include "Area.h"
#include <iostream>

Area::Area()
    : name("")
    , description("")
    , contents()
    , exits()
{
}

Area::~Area()
{
}

void Area::LookAround()
{
	std::cout << "\nYou look around " << this->name << "." << std::endl;
    std::cout << this->description << std::endl;

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
        std::cout << this->exits[i]->name << std::endl;
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

void Area::SetName(std::string newName)
{
    name = newName;
}

void Area::SetDescription(std::string newDesc)
{
    description = newDesc;
}

void Area::AddContents(Feature* newContent)
{
    contents.push_back(newContent);
}

void Area::AddExits(Area* newExit)
{
    exits.push_back(newExit);
}

std::string Area::GetName()
{
    return this->name;
}

std::vector<Area*> Area::GetExits()
{
    return this->exits;
}
