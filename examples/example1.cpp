#include <iostream>
using namespace std;

class Dot {
protected:
	int x, y;

public:
	virtual void show() {
		cout << "Dot with koordinates X: " << x << ", Y: " << y << endl;
	}

	Dot() {}
	Dot(int x0, int y0) : x(x0), y(y0) {}
};

