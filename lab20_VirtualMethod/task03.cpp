#include <iostream>
using namespace std;

class Homosapiens {
protected:
	int age = 0;

public:
	Homosapiens() {}
	Homosapiens(int age) : age(age) {}

	virtual ~Homosapiens() {}

	int getAge() {
		return age;
	}
	void setAge(int age) {
		if (age >= 0 && age < 110) {
			this->age = age;
		}
	}

	virtual void show() = 0;
};

class Human : public Homosapiens {
protected:
	char name[15] = "No Name";

public:
	Human() : Homosapiens() {}
	Human(const char* name, int age) : Homosapiens(age) {
		setName(name);
	}

	~Human() {}

	char* getName() {
		char t[15];
		strcpy_s(t, 15, name);
		return t;
	}
	void setName(const char* name) {
		strcpy_s(this->name, 15, name);
	}

	void show() override {
		cout << "Человек:\n";
		cout << "Имя: " << name << "\nВозраст: " << age << endl;
	}
};

class Employee : public Human {
protected:
	char post[30] = "Unknown";
	double wage = 0;

public:
	Employee() : Human() {}
	Employee(const char* name, int age, const char* post, double wage) : Human(name, age) {
		setPost(post);
		setWage(wage);
	}

	~Employee() {}


	char* getPost() {
		char t[30];
		strcpy_s(t, 30, post);
		return t;
	}
	void setPost(const char* post) {
		strcpy_s(this->post, 30, post);
	}

	double getWage() {
		return wage;
	}
	void setWage(double wage) {
		if (wage > 0) {
			this->wage = wage;
		}
	}


	void show() override {
		cout << "Сотрудник, ";
		Human::show();
		cout << "Должность: " << post << "\nОклад: " << wage << endl;
	}

	double calcSalary(double percent) {
		return wage + wage * percent / 100;
	}
};


int task03() {
	Human a;
	a.setAge(20);
	a.setName("Andrey");
	a.show();
	cout << endl;

	Employee b("Leha", 22, "rabotnik", 1200);
	b.show();

	cout << "\n===============\n\n";

	int n = 3;
	Homosapiens** arr = new Homosapiens*[n] {
		new Employee("Vlad", 25, "Traktorist", 30000), 
		new Human("Maksim", 16), 
		new Employee("Klim", 30, "3D disainer", 3000) 
	};

	for (int i = 0; i < n; i++) {
		arr[i]->show();
		cout << endl;
	}
	
	return 0;
}