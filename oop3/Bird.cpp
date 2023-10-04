#include "Bird.h"
#include "iostream"
#include "string"

using namespace std;

Bird::Bird(string name, int weight, int bodyLength) :Animal("Bird", name, weight) {


}

Bird::Bird(int InfTxt, std::string NameFromFile, int WeightFromFile, int IdFromFile) : Animal("Bird", NameFromFile, WeightFromFile, IdFromFile) {
	this->bodyLength = InfTxt;
}


Bird::Bird() : Animal("Bird") {
	cout << "ƒлина тела (в см.) : ";
	cin >> this->bodyLength;
}

Bird::~Bird() {

}

void Bird::setBodyLength(int body)
{
	bodyLength = body;
}

int getBodyLength(int body) {
	return body;
}

void Bird::showAnimalData() {
	Animal::showAnimalData();
	cout << "ƒлина тела (в см.): " << this->bodyLength;
}

void Bird::writeToFile() {
	Animal::writeToFile();
	std::ofstream out;          // поток дл€ записи
	out.open("data_base.txt", ios::app);

	if (out.is_open())
	{
		out << "ƒлина тела (в см.): " << this->bodyLength << std::endl;
		out << "-----------------------------------------\n";
	}
	out.close();
}
