#pragma once
#include "Amphibia.h"
#include "Bird.h"
#include "Reptile.h"
#include "Fish.h"
#include "Mammal.h"
#include "AnimalList.h"
#include "string"

class Interface {
public:
	void drawInterface();
private:
	AnimalList list;
	void doAction(int choice);
	void processAnimalChoice(int choice);
	void drawAddingElement();
	void deleteElementById();
	void drawShowingElementsByClassName();
	void clearscr();
	void initializeWriteToFile();
};
