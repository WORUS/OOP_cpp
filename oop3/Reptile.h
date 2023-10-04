#include "Animal.h"
#include "string"

#pragma once
class Reptile : public Animal
{
public:
	Reptile(string name, int avgWeight, bool shell);
	Reptile(int InfTxt, std::string NameFromFile, int WeightFromFile, int IdFromFile);
	Reptile();
	~Reptile();
	void setShell(bool shell);
	void showAnimalData();
	int getShell();
	void writeToFile();
private:
	bool beShell;
};
