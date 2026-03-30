#include <iostream>
using namespace std;

class Line {
protected:
	double l;

public:
	Line() : l(0) {}
	Line(double l) {
		this->l = l;
	}

	virtual void show() {
		cout << "Длина: " << l << endl;
	}

	virtual double perimetr() { return l; };
	virtual double square() { return 0; };
	virtual double volume() { return 0; };
};

class Romb : public Line {
protected:
	double w;

public:
	Romb() : Line(), w(0) {};
	Romb(double l, double w) :Line(l) {
		this->w = w;
	}

	void show() override {
		Line::show();
		cout << "Ширина: " << w << endl;
	}

	double perimetr() override {
		return 4 * l;
	}

	double square() override {
		return w * l;
	}
};

class Rhombohedron : public Romb {
protected:
	double h;

public:
	Rhombohedron() : Romb(), h(0) {};
	Rhombohedron(double l, double b, double h) : Romb(l, b) {
		this->h = h;
	};

	void show() override {
		Romb::show();
		cout << "Высота: " << h << endl;
	}

	double perimetr() override {
		return Romb::perimetr() * 3;
	}

	double square() override {
		return Romb::square() * 6;
	}

	double volume() override {
		return Romb::square() * h;
	}
};


int task01() {
	typedef double (Line::* func)();
	func f1 = &Line::perimetr;
	func f2 = &Line::square;
	func f3 = &Line::volume;

	Line l(5);
	Line* dl = new Line(6);
	Romb r(7, 8);
	Romb* dr = new Romb(9, 10);
	Rhombohedron rh(5, 6, 7);
	Rhombohedron* drh = new Rhombohedron(8, 9, 10);

	cout << (l.*f1)() << '\t' << (dl->*f1)() << endl;
	cout << (l.*f2)() << '\t' << (dl->*f2)() << endl;
	cout << (l.*f3)() << '\t' << (dl->*f3)() << endl << endl;

	cout << (r.*f1)() << '\t' << (dr->*f1)() << endl;
	cout << (r.*f2)() << '\t' << (dr->*f2)() << endl;
	cout << (r.*f3)() << '\t' << (dr->*f3)() << endl << endl;

	cout << (rh.*f1)() << '\t' << (drh->*f1)() << endl;
	cout << (rh.*f2)() << '\t' << (drh->*f2)() << endl;
	cout << (rh.*f3)() << '\t' << (drh->*f3)() << endl << endl;


	Line arr1[]{ Line(3), Line(4), Line(5) };
	Romb arr2[]{ Romb(6, 7), Romb(8, 9), Romb(10, 11) };
	Rhombohedron arr3[]{ Rhombohedron(3, 4, 5), Rhombohedron(6, 7, 8), Rhombohedron(9, 10 ,11) };

	for (int i = 0; i < 3; i++) {
		cout << (arr1[i].*f1)() << ", " << (arr1[i].*f2)() << ", " << (arr1[i].*f3)();
		cout << "\t\t";
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << (arr2[i].*f1)() << ", " << (arr2[i].*f2)() << ", " << (arr2[i].*f3)();
		cout << '\t';
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << (arr3[i].*f1)() << ", " << (arr3[i].*f2)() << ", " << (arr3[i].*f3)();
		cout << '\t';
	}
	cout << endl << endl;


	int n = 3;
	Line** dArr = new Line * [n];

	int p, a, b, c;

	for (int i = 0; i < n; i++) {
		do {
			cout << "\n1-Линия, 2-Ромб, 3-Ромбоэдр: ";
			cin >> p;

			switch (p) {
			case 1: {
				cout << "Введите длину: ";
				cin >> a;
				dArr[i] = new Line(a);
			} break;

			case 2: {
				cout << "Введите длину и ширину: ";
				cin >> a >> b;
				dArr[i] = new Romb(a, b);
			} break;

			case 3: {
				cout << "Введите длину, ширину и высоту: ";
				cin >> a >> b >> c;
				dArr[i] = new Rhombohedron(a, b, c);
			} break;

			default:
				cout << "Неверный ввод." << endl;
			}
		} while (p <= 0 || p > 3);
		dArr[i]->show();
	}

	return 0;
}