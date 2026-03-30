#include <iostream>
#include <Windows.h>
using namespace std;

int task01();
int task02();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int p;
	cout << "Введите номер задания: ";
	cin >> p;

	switch (p) {
		case 1: task01(); break;
		case 2: task02(); break;

		default: cout << "Неверный ввод.";
	}

	system("pause");
	return 0;
}