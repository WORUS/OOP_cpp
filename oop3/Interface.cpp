#include <typeinfo>
#include <iostream>
//#include <string>
#include <Windows.h>
#include <conio.h>
#include "Interface.h"
#include "Animal.h"

void Interface::drawInterface() {
	while (true) {
		clearscr();
		SetConsoleCP(1251);
		int choice = 0;
		std::cout << "=========================================\n";
		std::cout << "1) �������� �������\n";
		std::cout << "2) �������� ������ ���� ��������� ������\n";
		std::cout << "3) ������� ������� ������\n";
		std::cout << "4) ������� ��� �������� � ������\n";
		std::cout << "5) ������� ������ ��������� �� ���� ������\n";
		std::cout << "6) �����\n";
		std::cout << "7) ������ � �����\n";
		std::cout << "�������� ��������: ";
		std::cin >> choice;
		if (choice == 6) {
			initializeWriteToFile();
			break;
		}
		this->doAction(choice);
	}
}

void Interface::initializeWriteToFile()
{
	std::ofstream file;
	file.open("data_base.txt");
	file.clear();
	file.close();
	list.writeToFile();
}

void Interface::doAction(int choice) {
	clearscr();
	switch (choice)
	{
	case 1: this->drawAddingElement();
		break;
	case 2: list.showAllItems();
		break;
	case 3: this->deleteElementById();
		break;
	case 4: list.deleteAllItems();
		break;
	case 5: this->drawShowingElementsByClassName();
		break;
	case 7: list.readFile();
		break;
	default:
		std::cout << "��� ������ ��������!\n";
		break;
	}
	_getch();
}

void Interface::processAnimalChoice(int choice) {
	clearscr();
	switch (choice)
	{
	case 1: list.addItem(new Amphibia());
		break;
	case 2: list.addItem(new Fish());
		break;
	case 3: list.addItem(new Reptile());
		break;
	case 4: list.addItem(new Bird());
		break;
	case 5: list.addItem(new Mammal());
		break;
	default:
		std::cout << "��� ������ �������!\n";
		break;
	}
}

void Interface::drawAddingElement() {
	int choice = 0;
	std::cout << "===== ��������� � ���������� �������� =====\n";
	std::cout << "1) Amphibia\n";
	std::cout << "2) Fish\n";
	std::cout << "3) Reptile\n";
	std::cout << "4) Bird\n";
	std::cout << "5) Mammal\n";
	std::cout << "6) ������ �� �����\n";
	std::cout << "������� ����� �������, ������� ������ �������: ";
	std::cin >> choice;
	this->processAnimalChoice(choice);
}

void Interface::deleteElementById() {
	int animalId = 0;
	std::cout << "������� ID �������, ����� ��� �������: ";
	std::cin >> animalId;
	list.deleteItem(animalId);
}

void Interface::drawShowingElementsByClassName() {
	clearscr();
	int choice = 0;
	std::cout << "1) Amphibia\n";
	std::cout << "2) Fish\n";
	std::cout << "3) Reptile\n";
	std::cout << "4) Bird\n";
	std::cout << "5) Mammal\n";
	std::cout << "�������� ��� �����, �������� �������� ����� ��������: \n";
	std::cin >> choice;
	switch (choice)
	{
	case 1: list.showItemsByClassName(typeid(Amphibia));
		break;
	case 2: list.showItemsByClassName(typeid(Fish));
		break;
	case 3: list.showItemsByClassName(typeid(Bird));
		break;
	case 4:	list.showItemsByClassName(typeid(Reptile));
		break;
	case 5:	list.showItemsByClassName(typeid(Mammal));
		break;
	default:
		std::cout << "��� ������ ������!\n";
		break;
	}
}

void Interface::clearscr() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
	SetConsoleCursorPosition(hStdOut, coord);
}

