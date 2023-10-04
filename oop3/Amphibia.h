#include "Animal.h"
#include "string"

#pragma once
class Amphibia : public	Animal
{
public:
	Amphibia(string name, int avgWeight, string habitat);
	Amphibia();
	Amphibia(std::string InfTxt, std::string NameFromFile, int WeightFromFile, int IdFromFile);
	~Amphibia();
	void showAnimalData();
	void setHabitat(string hab);
	string getHabitat(string hab);
	void writeToFile();
private:
	string habitat;
};
