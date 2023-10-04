#include <typeinfo>
#include <iostream>
#include <vector>
#include <string>
#include "AnimalList.h"
#include <windows.h>
#include "fstream"
#include "Animal.h"
#include "Interface.h"


void AnimalList::addItem(Animal* animal) {
	animalList.push_back(animal);
}

void AnimalList::showAllItems() {
	if (!animalList.empty()) {
		for (auto element : animalList) {
			element->showAnimalData();
		}
	}
	else {
		std::cout << "\nCписок пуст!\n";
	}
}

void AnimalList::showItem(int AnimalId) {
	if (!animalList.empty()) {
		for (auto element : animalList) {
			if (element->getAnimalId() == AnimalId) {
				element->showAnimalData();
			}
		}
	}
	else {
		std::cout << "Список пуст!\n";
	}
}

void AnimalList::deleteAllItems() {
	if (!animalList.empty()) {
		std::vector<Animal*>::iterator itt;
		for (itt = animalList.begin(); itt != animalList.end();) {
			delete* itt;
			itt = animalList.erase(itt);
		}
		std::cout << "\nВсе элементы были удалены из списка!\n";
	}
	else {
		std::cout << "\nВы не можете очистить список, так как он уже пуст!\n";
	}
}

void AnimalList::deleteItem(int AnimalId) {
	if (!animalList.empty()) {
		std::vector<Animal*>::iterator itt;
		for (itt = animalList.begin(); itt != animalList.end();) {
			if ((*itt)->getAnimalId() == AnimalId) {
				delete* itt;
				itt = animalList.erase(itt);
			}
			else {
				itt++;
			}
		}
	}
	else {
		std::cout << "\nВы не можете удалить элемент списка, так как он уже пуст!\n";
	}
}

void AnimalList::showItemsByClassName(const type_info& type) {
	for (auto element : animalList) {
		if (typeid(*element) == type) {
			element->showAnimalData();
		}
	}
}

AnimalList::~AnimalList() {
	if (!animalList.empty()) {
		std::vector<Animal*>::iterator itt;
		for (itt = animalList.begin(); itt != animalList.end();) {
			delete* itt;
			itt = animalList.erase(itt);
		}
	}
}

void AnimalList::writeToFile()
{
	std::ofstream out;
	out.open("data_base.txt");
	if (!out.is_open())
	{
		cout << "File don't oppen!";
		exit(1);
	}
	else
	{
		cout << "File oppened!";
		for (Animal* element : animalList) {
			element->writeToFile();
		}
	}
	cout << "Объекты сохранены в " << "data_base.txt" << endl;
	out.close();
}

void AnimalList::readFile() {
	std::string line;
	std::string tmpTxt;
	std::ifstream in("data_base.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::string typeOfAnimal = line.substr(line.find(':') + 2, line.length() - line.find(':'));
			getline(in, line);
			std::string nameOfAnimal = line.substr(line.find(':') + 2, line.length() - line.find(':'));
			getline(in, line);
			std::string chkId = line.substr(line.find(':') + 2, line.length() - line.find(':'));
			int idOfAnimal = stoi(chkId);
			getline(in, line);
			int WeightOfAnimal = stoi(line.substr(line.find(':') + 2, line.length() - line.find(':')));
			getline(in, line);
			if (typeOfAnimal == "Amphibia") {
				std::string infTxt = line.substr(line.find(':') + 2, line.length() - line.find(':'));
				addItem(new Amphibia(infTxt, nameOfAnimal, WeightOfAnimal, idOfAnimal));
			}
			else if (typeOfAnimal == "Bird") {
				std::string infTxt = line.substr(line.find(':') + 2, line.length() - line.find(':'));
				addItem(new Bird(stoi(infTxt), nameOfAnimal, WeightOfAnimal, idOfAnimal));
			}
			else if (typeOfAnimal == "Fish") {
				std::string infTxt = line.substr(line.find(':') + 2, line.length() - line.find(':'));
				addItem(new Fish(stoi(infTxt), nameOfAnimal, WeightOfAnimal, idOfAnimal));
			}
			else if (typeOfAnimal == "Reptile") {
				std::string infTxt = line.substr(line.find(':') + 2, line.length() - line.find(':'));
				addItem(new Reptile(stoi(infTxt), nameOfAnimal, WeightOfAnimal, idOfAnimal));
			}
			else if (typeOfAnimal == "Mammal") {
				addItem(new Animal("Mammal", nameOfAnimal, WeightOfAnimal, idOfAnimal));
			}
			if (line[1] != '-')getline(in, line);
			cout << "Добавлен элемент с классом " << typeOfAnimal << endl;
		}
	}
	in.close();     // закрываем файл
	cout << "\nДанные записаны из data_base.txt";
}


