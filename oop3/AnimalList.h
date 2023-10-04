#pragma once
#include <vector>
#include "Animal.h"
#include "fstream"

using namespace std;

class AnimalList
{
public:
	void addItem(Animal* animal);
	void showAllItems();
	void showItem(int animalId);
	void deleteAllItems();
	void deleteItem(int animalId);
	void showItemsByClassName(const type_info& type);
	~AnimalList();
	void writeToFile();
	void readFile();
private:
	std::vector<Animal*> animalList;
};
