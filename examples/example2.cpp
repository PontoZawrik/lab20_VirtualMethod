#include <iostream>
#include <Windows.h>
using namespace std;

class Parent {
protected:
	int a = 0;

public:
	Parent() {}
	Parent(int a0) {
		a = a0;
	}

	virtual ~Parent() {}

	virtual void Show() = 0;
};

class Child : public Parent {
protected:
	double b = 0;

public:
	Child() : Parent() {}
	Child(int a1, double b2) : Parent(a1) {
		b = b2;
	}

	virtual ~Child() {}

	void Show() override {
		cout << Parent::a << ' ' << Child::b << endl;
	}
};

class Grandchild : public Child {
protected:
	char c = 'X';

public:
	Grandchild() : Child() {}
	Grandchild(int a3, double b3, char c3) : Child(a3, b3) {
		c = c3;
	}

	virtual ~Grandchild() {}

	void Show() override {
		cout << Grandchild::c << ' ';
		Child::Show();
	}
};


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Child a;
	Grandchild b;
	int n = 3, p, a4;
	double b4;
	char c4;
	Parent** m = new Parent*[n];

	if (m == nullptr) {
		cout << "No memory.\n";
		system("pause");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cout << "0-Child, 1-Grandchild. Enter: ";
		cin >> p;

		switch (p) {
		case 0: {
			cout << "a: ";
			cin >> a4;
			cout << "b: ";
			cin >> b4;

			m[i] = new Child(a4, b4);
			if (m[i] == nullptr) {
				cout << "No memory.\n";
				system("pause");
				return 0;
			}
		} break;

		case 1: {
			cout << "a: ";
			cin >> a4;
			cout << "b: ";
			cin >> b4;
			cout << "c: ";
			cin >> c4;

			m[i] = new Child(a4, b4);
			if (m[i] == nullptr) {
				cout << "No memory.\n";
				system("pause");
				return 0;
			}
		} break;
		}
		m[i]->Show();
	}

	for (int i = 0; i < n; i++) {
		delete[] m[i];
	}
	delete[] m;
	system("pause");
	return 0;
}