#include "Animal.h"

#pragma once
class Fish : public Animal
{
public:
	Fish(string name, int avgWeight, int fins);
	Fish(int InfTxt, std::string NameFromFile, int WeightFromFile, int IdFromFile);
	Fish();
	~Fish();
	void setFins(int fins);
	void showAnimalData();
	int getFins();
	void writeToFile();
private:
	int fishFins;
};
