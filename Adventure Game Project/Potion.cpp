#include "Potion.h"
#include "Player.h"

Potion::Potion()
    : Item("Awkward Potion", "This potion is incomplete. Restores 1 health.")
    , healingAmount(1)
    , itemOwner(nullptr)
{
}

Potion::Potion(std::string newName, std::string newDescription, int newAmount)
    : Item(newName, newDescription)
    , healingAmount(newAmount)
    , itemOwner(nullptr)
{
}

Potion::~Potion()
{
}

void Potion::Use()
{
    float currHP = itemOwner->GetCurrHealth();
    
    currHP += healingAmount;
    if (currHP > itemOwner->GetMaxHealth())
    {
        currHP = itemOwner->GetMaxHealth();
    }
    itemOwner->SetCurrHealth(currHP);
}
