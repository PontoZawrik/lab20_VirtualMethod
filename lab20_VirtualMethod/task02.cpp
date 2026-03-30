#include <iostream>
using namespace std;

class Alive {
protected:
	int age;
	int satiety = 1;
	bool alive;
public:
	Alive() {
		age = 0;
		satiety = 0;
	}
	Alive(int age, int satiety) {
		this->age = age;
		this->satiety = satiety;
	}

	~Alive() {}

	virtual void eating(Alive&) {};
	virtual void show() {
		cout << "Статус: " << (isAlive() ? "Живой" : "Мёртвый") << endl;
		cout << "Возраст: " << age << endl;
		cout << "Сытость: " << satiety << endl << endl;
	}

	bool isAlive() {
		return alive;
	}
	void death() {
		alive = false;
	}

	void newYear(int maxAge) {
		if (satiety > 0 && age < maxAge && isAlive()) {
			age++;
			satiety--;
		}
		else {
			death();
		}
	}
};

class Plant : public Alive {
private:
	static inline int maxAge = 2;

public:
	Plant() : Alive() {}
	Plant(int age, int satiety) : Alive(age, satiety) {}

	~Plant() {}

	void eating(Alive& a) override {
		satiety++;
	}

	void show() override {
		cout << "Существо: Растение\n";
		Alive::show();
	}

	void newYear() {
		Alive::newYear(maxAge);
	}
};

class Rabbit : public Alive {
private:
	static inline int maxAge = 4;

public:
	Rabbit() : Alive() {}
	Rabbit(int age, int satiety) : Alive(age, satiety) {}

	~Rabbit() {}

	void eating(Alive& a) override {
		if (a.isAlive() && this->satiety < 3) {
			satiety++;
			a.death();
		}
	}

	void show() override {
		cout << "Существо: Кролик\n";
		Alive::show();
	}

	void newYear() {
		Alive::newYear(maxAge);
	}
};

class Fox : public Alive {
private:
	static inline int maxAge = 9;

public:
	Fox() : Alive() {}
	Fox(int age, int satiety) : Alive(age, satiety) {}

	~Fox() {}

	void eating(Alive& a) override {
		if (a.isAlive() && this->satiety < 3) {
			satiety++;
			a.death();
		}
	}

	void show() override {
		cout << "Существо: Лиса\n";
		Alive::show();
	}

	void newYear() {
		Alive::newYear(maxAge);
	}
};


int task02() {
	Alive empty = Alive();

	Plant a(0, 2);
	Rabbit b(2, 1);
	Fox c(4, 3);

	a.eating(empty);
	a.newYear();
	a.show();

	b.eating(a);
	b.newYear();
	b.show();

	c.eating(b);
	c.newYear();
	c.death();
	c.show();

	
	cout << endl;
	Alive** arr = new Alive*[]{ new Plant(0, 2), new Rabbit(1, 3), new Fox(5, 1) };
	for (int i = 0; i < 3; i++) {
		arr[i]->show();
	}

	return 0;
}