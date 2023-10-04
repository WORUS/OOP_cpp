#include <iostream>
#include <string>
#include "Animal.h"
#include "fstream"
#include <windows.h>
#include "AnimalList.h"
#include "Amphibia.h"
#include "Bird.h"
#include "Fish.h"
#include "Reptile.h"
#include "Interface.h"

using namespace std;

int Animal::animalCount = 0;
int Animal::currentId = 0;

void Animal::showAnimalData() {
	std::cout << "\n==================================\n";
	std::cout << "ID объекта:  " << animalId << "\n";
	std::cout << "Название животного: " << animalName << "\n";
	std::cout << "Класс животного: " << animalType << "\n";
	std::cout << "Средний вес животного: " << avgWeight << "\n";
}

int Animal::getAnimalCount() {
	return animalCount;
}

Animal::Animal(string animalType, string animalName, int avgWeight) {
	animalCount++;
	currentId++;
	this->animalType = animalType;
	this->animalName = animalName;
	this->avgWeight = avgWeight;
	animalId = currentId;
	std::cout << this << " Вы создали животное под названием " << animalName << " с ID: " << animalId << "\n";

}

Animal::Animal(string animalType) {
	this->animalType = animalType;
	animalCount++;
	currentId++;
	animalId = currentId;
	std::cout << "Создание животного с классом: " << animalType << "\n";
	std::cout << "Введите вес животного: ";
	//std::cin.ignore();
	std::cin >> avgWeight;
	std::cout << "Введите название животного: ";
	std::cin >> animalName;
}

void Animal::writeToFile()
{
	std::ofstream out;
	out.open("data_base.txt", ios::app);

	if (out.is_open())
	{
		out << "Класс животного: " << *&animalType << std::endl;
		out << "Название животного: " << *&animalName << std::endl;
		out << "Id объекта: " << *&animalId << std::endl;
		out << "Средний вес животного: " << *&avgWeight << std::endl;
	}
	out.close();
}

Animal::Animal() : avgWeight(0), animalName(""), animalType("") {
	animalCount++;
	currentId++;
	animalId = currentId;
	std::cout << this << " Вы создали животное без параметров с ID: " << animalId << "\n";
}

Animal::Animal(const Animal& animal) {
	animalCount++;
	currentId++;
	this->animalType = animal.animalType;
	this->animalName = animal.animalName;
	this->avgWeight = animal.avgWeight;
	animalId = currentId;
	std::cout << this << " Вы создали животное под названием " << animalName << " с ID: " << animalId << " через конструктор копирования\n";
}

Animal::~Animal() {
	std::cout << this << " Вы удалили животное: " << animalName << " с ID: " << animalId << "\n";
	animalCount--;
}

void Animal::setAnimalType(string type) {
	animalType = type;
}

void Animal::setAnimalName(string name) {
	animalName = name;
}

void Animal::setAvgWeight(int weight) {
	avgWeight = weight;
}

string Animal::getAnimalType() {
	return animalType;
}

string Animal::getAnimalName() {
	return animalName;
}

int Animal::getAvgWeight() {
	return avgWeight;
}

int Animal::getAnimalId() {
	return animalId;
}

Animal::Animal(std::string TypeFromFile, std::string NameFromFile, int WeightFromFile, int IdFromFile) {
	this->animalType = TypeFromFile;
	animalCount++;
	currentId = IdFromFile;
	this->animalId = IdFromFile;
	this->avgWeight = WeightFromFile;
	this->animalName = NameFromFile;
}
