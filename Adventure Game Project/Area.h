#pragma once

#include <string>
#include <vector>
#include "Feature.h"

class Area
{
public:

	Area();
	~Area();

	void LookAround();
	Area* AttemptGo();
	void Examine();

	std::string name;
	std::string description;
	std::vector<Feature*> contents;
	std::vector<Area*> exits;
};

