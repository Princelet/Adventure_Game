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

	void SetName(std::string newName);
	void SetDescription(std::string newDesc);
	void AddContents(Feature* newContent);
	void AddExits(Area* newExit);

	std::string GetName();
	std::vector<Area*> GetExits();

private:
	std::string name;
	std::string description;
	std::vector<Feature*> contents;
	std::vector<Area*> exits;
};

