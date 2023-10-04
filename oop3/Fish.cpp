#include "Fish.h"

#include "iostream"
#include "string"

using namespace std;

Fish::Fish(string name, int weight, int fins) :Animal("Fish", name, weight) {


}

Fish::Fish() : Animal("Fish") {
	cout << "���������� ��������� : ";
	cin >> this->fishFins;
}

Fish::~Fish() {

}

Fish::Fish(int InfTxt, std::string NameFromFile, int WeightFromFile, int IdFromFile) : Animal("Fish", NameFromFile, WeightFromFile, IdFromFile) {
	this->fishFins = InfTxt;
}

void Fish::setFins(int fins)
{
	fishFins = fins;
}

int getfishFins(int body) {
	return body;
}

void Fish::showAnimalData() {
	Animal::showAnimalData();
	cout << "���������� ���������: " << this->fishFins;
}

void Fish::writeToFile() {
	Animal::writeToFile();
	std::ofstream out;          // ����� ��� ������
	out.open("data_base.txt", ios::app);

	if (out.is_open())
	{
		out << "���������� ���������: " << this->fishFins << std::endl;
		out << "-----------------------------------------\n";
	}
	out.close();
}
