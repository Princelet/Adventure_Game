#pragma once

#include <string>

class Feature
{
public:
	Feature();
	~Feature();

	void SetName(std::string newName);
	void SetDescription(std::string newDesc);

	std::string GetName();
	std::string GetDescription();

private:
	std::string name;
	std::string description;
};

