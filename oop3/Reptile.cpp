#include "Reptile.h"
#include "iostream"
using namespace std;

Reptile::Reptile(string name, int avgWeight, bool shell) {

};

Reptile::Reptile() : Animal("Reptile") {
	cout << "Наличие панциря(1/0) : ";
	cin >> this->beShell;
};
Reptile ::~Reptile() {

};

Reptile::Reptile(int InfTxt, std::string NameFromFile, int WeightFromFile, int IdFromFile) : Animal("Reptile", NameFromFile, WeightFromFile, IdFromFile) {
	this->beShell = InfTxt;
}

void Reptile::setShell(bool shell) {
};

void Reptile::showAnimalData() {
	Animal::showAnimalData();
	cout << "Наличие панциря(1/0): " << this->beShell;
};

int Reptile::getShell() {
	return beShell;
};

void Reptile::writeToFile() {
	Animal::writeToFile();
	std::ofstream out;          // поток для записи
	out.open("data_base.txt", ios::app);

	if (out.is_open())
	{
		out << "Наличие панциря(1/0): " << this->beShell << std::endl;
		out << "-----------------------------------------\n";
	}
	out.close();
}
