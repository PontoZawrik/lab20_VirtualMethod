#include <iostream>
#include <Windows.h>
using namespace std;

int task01();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int p;
	cout << "Введите номер задания: ";
	cin >> p;

	switch (p) {
		case 1: task01(); break;
	}

	system("pause");
	return 0;
}