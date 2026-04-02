#include <iostream>
using namespace std;

class Point {
protected:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    virtual double length() = 0;
    virtual double inRadius() = 0;
    virtual ~Point() {}
};

class Polygon : public Point {
protected:
    const double pi = 3.1415;
    double a;     
    int n;        

public:
    Polygon(double x, double y, int n, double a) : Point(x, y) {
        if (n < 3 || a <= 0) {
            throw "Неверные значения.";
        }

        this->n = n;
        this->a = a;
    }

    ~Polygon() {}

    double length() override {
        return n * a;
    }
    double inRadius() override {
        return a / (2 * tan(pi / n));
    }

};


int task04() {
    int n = 3;
    Point** arr = new Point * [n] {
        new Polygon(1, 5, 4, 10),
        new Polygon(2, 4, 5, 4),
        new Polygon(-3, 2, 3, 7)
    };

    double avgR = 0;
    for (int i = 0; i < n; i++) {
        cout << "Радиус " << "1: " << arr[i]->inRadius() << endl;
        avgR += arr[i]->inRadius();
    }
    cout << "Средний радиус: " << avgR / n << endl;

    return 0;
}