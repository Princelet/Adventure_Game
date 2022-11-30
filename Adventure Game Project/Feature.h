#pragma once
#include "Thing.h"

#include <string>

class Feature : public Thing
{
public:
	Feature();
	Feature(std::string newName, std::string newDescription);
	~Feature();

	std::string GetName();
	std::string GetDescription();
};

