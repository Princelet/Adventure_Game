#include "Thing.h"
#include "Item.h"
#include <iostream>

Thing::Thing()
	: name("Empty Room")
	, description("You shouldn't be here.")
{
}

Thing::Thing(std::string newName, std::string newDescription)
	: name(newName)
	, description(newDescription)
{
}

Thing::~Thing()
{
}

void Thing::Look()
{
	std::cout << "This is " << this->GetName() << std::endl;
	std::cout << this->GetDescription() << std::endl;
}

void Thing::UseItem()
{
}

std::string Thing::GetName()
{
	return name;
}

std::string Thing::GetDescription()
{
	return description;
}
