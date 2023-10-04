#include "Animal.h"
#include "string"

#pragma once
class Bird : public	Animal
{
public:
	Bird(string name, int avgWeight, int bodyLength);
	Bird(int InfTxt, std::string NameFromFile, int WeightFromFile, int IdFromFile);
	Bird();
	~Bird();
	void showAnimalData();
	void setBodyLength(int body);
	int getBodyLength(int body);
	void writeToFile();
private:
	int bodyLength;
};
