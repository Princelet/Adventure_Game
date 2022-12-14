#include "Item.h"

Item::Item()
    : Thing("", "")
    , itemOwner(nullptr)
{
}

Item::Item(std::string newName, std::string newDescription)
    : Thing(newName, newDescription)
    , itemOwner(nullptr)
{
}

Item::~Item()
{
}

void Item::Use()
{
    itemOwner = nullptr;
}

void Item::SetOwner(Player* newOwner)
{
    newOwner = itemOwner;
}
