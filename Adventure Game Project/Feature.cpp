#include "Feature.h"

Feature::Feature()
	: name("")
	, description("")
{
}

Feature::~Feature()
{
}

void Feature::SetName(std::string newName)
{
	name = newName;
}

void Feature::SetDescription(std::string newDesc)
{
	description = newDesc;
}

std::string Feature::GetName()
{
	return name;
}

std::string Feature::GetDescription()
{
	return description;
}
