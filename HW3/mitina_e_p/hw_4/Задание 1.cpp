#include <iostream>
#include <cassert>
#include <sstream>
#include <cmath>
using namespace std;

class Vector2D {
private:
    double x_;
    double y_;

public:
    // Конструктор с параметрами по умолчанию
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    // Геттеры (const)
    double x() const { return x_; }
    double y() const { return y_; }

    // Длина вектора
    double length() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    // Покомпонентное сложение
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    // Покомпонентное вычитание
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }

    // Умножение на скаляр: v * k
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    // Скалярное произведение: v1 * v2
    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    // Сравнение
    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // Унарный минус — противоположный вектор
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    // Вывод в формате (x, y)
    friend ostream& operator<<(ostream& os, const Vector2D& v);
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x_ << ", " << v.y_ << ")";
    return os;
}

void runTests() {
    Vector2D a(3, 4), b(1, -2);

    // Сложение / вычитание
    assert((a + b) == Vector2D(4, 2));
    assert((a - b) == Vector2D(2, 6));

    // Умножение на скаляр
    assert((a * 2.0) == Vector2D(6, 8));

    // Скалярное произведение: 3*1 + 4*(-2) = -5
    assert((a * b) == -5.0);

    // Унарный минус
    assert((-a) == Vector2D(-3, -4));

    // Длина: sqrt(9 + 16) = 5
    assert(a.length() == 5.0);

    // Сравнения
    assert(a != b);
    assert(a == Vector2D(3, 4));

    // Проверка вывода
    ostringstream out;
    out << a << " " << b;
    assert(out.str() == "(3, 4) (1, -2)");

    cout << "Задача 1 (Vector2D): все тесты пройдены\n";
}

int main() {
    runTests();

    Vector2D a(3, 4), b(1, -2);
    cout << "a + b   = " << a + b << "\n";
    cout << "a - b   = " << a - b << "\n";
    cout << "a * 2   = " << a * 2.0 << "\n";
    cout << "a * b   = " << a * b << "\n";
    cout << "-a      = " << -a << "\n";
    cout << "|a|     = " << a.length() << "\n";
    return 0;
}
