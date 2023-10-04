#include "Amphibia.h"
#include "iostream"
#include "string"

using namespace std;

Amphibia::Amphibia(string name, int weight, string habitat) :Animal("Amphibia", name, weight) {


}

Amphibia::Amphibia() : Animal("Amphibia") {
	cout << "Место обитания: ";
	cin >> this->habitat;
}

Amphibia::Amphibia(std::string InfTxt, std::string NameFromFile, int WeightFromFile, int IdFromFile) : Animal("Amphibia", NameFromFile, WeightFromFile, IdFromFile) {
	this->habitat = InfTxt;
}


Amphibia::~Amphibia() {

}

void Amphibia::setHabitat(string hab)
{
	habitat = hab;
}


string getHabitat(string hab) {
	return hab;
}

void Amphibia::showAnimalData() {
	Animal::showAnimalData();
	cout << "Место обитания :" << this->habitat;
}


void Amphibia::writeToFile() {
	Animal::writeToFile();
	std::ofstream out;          // поток для записи
	out.open("data_base.txt", ios::app);

	if (out.is_open())
	{
		out << "Место обитания: " << this->habitat << std::endl;
		out << "-----------------------------------------\n";
	}
	out.close();
}
