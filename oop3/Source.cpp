#include <iostream>
#include <locale>
#include "windows.h"
#include "Interface.h"
#include "fstream"
int main(int arc, string* argv[]) {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "RUS");
	Interface interf;
	interf.drawInterface();
	return 0;
}
