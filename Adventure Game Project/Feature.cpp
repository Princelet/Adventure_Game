#include "Feature.h"

Feature::Feature()
	: Thing("", "")
{
}

Feature::Feature(std::string newName, std::string newDescription)
	: Thing(newName, newDescription)
{
}

Feature::~Feature()
{
}

std::string Feature::GetName()
{
	return name;
}

std::string Feature::GetDescription()
{
	return description;
}
