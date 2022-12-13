#include "Item.h"

Item::Item()
    : Thing("", "")
{
}

Item::Item(std::string newName, std::string newDescription)
    : Thing(newName, newDescription)
{
}

Item::~Item()
{
}

void Item::Use()
{
}
