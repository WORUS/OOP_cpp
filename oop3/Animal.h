#pragma once

#include "string"
#include "fstream"
#include "iostream"

using namespace std;

enum animalTypes { amph, bird, rept, fish };
class Animal
{
public:
	virtual void showAnimalData();
	static int getAnimalCount();
	Animal(string animalType, string animalName, int avgWeight);
	Animal(string animalType);
	Animal();
	Animal(std::string TypeFromFile, std::string NameFromFile, int WeightFromFile, int IdFromFile);
	Animal(const Animal& animal);
	virtual ~Animal();
	void setAnimalType(string type);
	void setAnimalName(string name);
	void setAvgWeight(int weight);
	string getAnimalType();
	string getAnimalName();
	virtual void writeToFile();
	int getAvgWeight();
	int getAnimalId();
private:
	string animalName;
	int avgWeight;
	string  animalType;
	int animalId = 0;
	static int animalCount;
	static int currentId;
};
