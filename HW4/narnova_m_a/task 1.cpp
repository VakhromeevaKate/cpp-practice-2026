/**
 Задача 1. Класс Vector2D: перегрузка операторов
 Тема: инкапсуляция, конструкторы, перегрузка операторов, const-корректность.
 Условие. Реализуйте класс Vector2D — вектор на плоскости с приватными полями x_, y_ типа double.
 Перегрузите:
 - operator+, operator- — покомпонентные;
 - operator* — две перегрузки: на скаляр (Vector2D) и скалярное произведение (double);
 - operator- (унарный) — противоположный вектор;
 - operator== и operator!= — сравнение;
 - operator<< — вывод в формате (x, y).
 */

#include <iostream>
#include <cassert>
#include <sstream>
#include <cmath>
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

    // Умножение на скаляр
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    // Скалярное произведение
    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Vector2D& v);
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x_ << ", " << v.y_ << ")";
    return os;
}

void runTests() {
    Vector2D a(3, 4), b(1, 2);

    assert((a + b) == Vector2D(4, 6));
    assert((a - b) == Vector2D(2, 2));
    assert((a * 2.0) == Vector2D(6, 8));
    assert((a * b) == 3 * 1 + 4 * 2);   
    assert((-a) == Vector2D(-3, -4));

    assert(a != b);
    assert(a == Vector2D(3, 4));

    
    assert(std::abs(a.length() - 5.0) < 1e-9);

    
    ostringstream out;
    out << a << " " << b;
    assert(out.str() == "(3, 4) (1, 2)");

    cout << "Задача 1: все тесты пройдены!\n";
}

int main() {
    runTests();

    Vector2D a(3, 4), b(1, 2);
    cout << "a       = " << a << "\n";
    cout << "b       = " << b << "\n";
    cout << "a + b   = " << a + b << "\n";
    cout << "a - b   = " << a - b << "\n";
    cout << "a * 2   = " << a * 2 << "\n";
    cout << "a * b   = " << a * b << "\n";
    cout << "|a|     = " << a.length() << "\n";
    cout << "-a      = " << -a << "\n";
    cout << "a == b  : " << (a == b) << "\n";
    cout << "a != b  : " << (a != b) << "\n";
    return 0;
}