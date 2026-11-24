//# 📝 Домашнее задание 4

//# Задача 1. Класс Vector2D
//Тема : инкапсуляция, конструкторы, перегрузка операторов, const - корректность.

//Условие.Реализуйте класс Vector2D — вектор на плоскости с приватными полями x_, y_ типа double.
//ребуется :
	//-Конструктор Vector2D(double x = 0, double y = 0).
	//- Геттеры x(), y() (const).
	//- length() — длина вектора, const - метод.
	//- operator+ и operator- — покомпонентные сложение и вычитание, возвращают новый вектор.
	//- operator* — две перегрузки :
//-Vector2D operator*(double k) const — умножение на скаляр.
//- double operator*(const Vector2D & other) const — скалярное произведение.
//- operator== и operator!=.
//- operator- (унарный) — противоположный вектор.
//- operator<< — вывод в формате(x, y).

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cassert>
#include <cmath>
#include <sstream> 

using namespace std;

class Vector2D {
private:
	double x_, y_;

public:
	Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}
	double x() const { return x_; }
	double y() const { return y_; }

	double length() const {
		return sqrt(x_ * x_ + y_ * y_);
	}

	Vector2D operator+(const Vector2D& other) const {
		return Vector2D(x_ + other.x_, y_ + other.y_);
	}

	Vector2D operator-(const Vector2D& other) const {
		return Vector2D(x_ - other.x_, y_ - other.y_);
	}

	double operator*(const Vector2D& other) const {
		return x_ * other.x_ + y_ * other.y_;
	}

	Vector2D operator*(double k) const {
		return Vector2D(x_ * k, y_ * k);
	}

	bool operator==(const Vector2D& other) const {
		return x_ == other.x_ && y_ == other.y_;
	}

	bool operator!=(const Vector2D& other) const {
		return x_ != other.x_ || y_ != other.y_;
	}

	Vector2D operator-() const {
		return Vector2D(-x_, -y_); 
	}

	friend ostream& operator<<(ostream& os, const Vector2D& c);
};

ostream& operator<<(ostream& os, const Vector2D& c) {
	os << "(" << c.x_ << ", " << c.y_ << ")";
	return os;
}

void runTests() {
	Vector2D a(3, 4), b(1, -2);

	assert((a + b) == Vector2D(4, 2));
	assert((a - b) == Vector2D(2, 6));
	assert((a * b) == -5.0);
	assert((a * 2.0) == Vector2D(6, 8));
	assert((-a) == Vector2D(-3, -4));
	assert((-b) == Vector2D(-1, 2));
	assert(a.length() == 5.0);
	assert(a != b);
	assert(a == Vector2D(3, 4));
	ostringstream out;
	out << a << " " << b;
	assert(out.str() == "(3, 4) (1, -2)");

	cout << "Задача 1: все тесты пройдены!\n";
}

int main() {
	runTests();
	Vector2D a(3, 4), b(1, -2);

	cout << "Вектор a = " << a << "\n";
	cout << "Вектор b = " << b << "\n\n";

	cout << "Сложение (a + b): " << a + b << "\n";
	cout << "Вычитание (a - b): " << a - b << "\n";
	cout << "Умножение на скаляр (a*2): " << a * 2.0 << "\n";
	cout << "Скалярное произв. (a * b): " << a * b << "\n";
	cout << "Унарный минус (-a): " << -a << "\n";
	cout << "Длина вектора a: " << a.length() << "\n";

	cout << "a == b? " << (a == b ? "True" : "False") << "\n";
	cout << "a != b? " << (a != b ? "True" : "False") << "\n";

	return 0;
}
