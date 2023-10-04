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
	std::cout << "ID �������:  " << animalId << "\n";
	std::cout << "�������� ���������: " << animalName << "\n";
	std::cout << "����� ���������: " << animalType << "\n";
	std::cout << "������� ��� ���������: " << avgWeight << "\n";
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
	std::cout << this << " �� ������� �������� ��� ��������� " << animalName << " � ID: " << animalId << "\n";

}

Animal::Animal(string animalType) {
	this->animalType = animalType;
	animalCount++;
	currentId++;
	animalId = currentId;
	std::cout << "�������� ��������� � �������: " << animalType << "\n";
	std::cout << "������� ��� ���������: ";
	//std::cin.ignore();
	std::cin >> avgWeight;
	std::cout << "������� �������� ���������: ";
	std::cin >> animalName;
}

void Animal::writeToFile()
{
	std::ofstream out;
	out.open("data_base.txt", ios::app);

	if (out.is_open())
	{
		out << "����� ���������: " << *&animalType << std::endl;
		out << "�������� ���������: " << *&animalName << std::endl;
		out << "Id �������: " << *&animalId << std::endl;
		out << "������� ��� ���������: " << *&avgWeight << std::endl;
	}
	out.close();
}

Animal::Animal() : avgWeight(0), animalName(""), animalType("") {
	animalCount++;
	currentId++;
	animalId = currentId;
	std::cout << this << " �� ������� �������� ��� ���������� � ID: " << animalId << "\n";
}

Animal::Animal(const Animal& animal) {
	animalCount++;
	currentId++;
	this->animalType = animal.animalType;
	this->animalName = animal.animalName;
	this->avgWeight = animal.avgWeight;
	animalId = currentId;
	std::cout << this << " �� ������� �������� ��� ��������� " << animalName << " � ID: " << animalId << " ����� ����������� �����������\n";
}

Animal::~Animal() {
	std::cout << this << " �� ������� ��������: " << animalName << " � ID: " << animalId << "\n";
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
