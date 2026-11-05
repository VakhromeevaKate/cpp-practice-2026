#include <iostream>
#include <cmath>
using namespace std;


// класс вектора на плоскости
class Vector2D {
private:
    double x_, y_; // приватные поля,координаты вектора

public:
    // конструктор
    Vector2D(double x = 0, double y = 0) {
        x_ = x;
        y_ = y;
    }

    // геттеры 
    double x() const { return x_;}

    double y() const { return y_;}

    // вычисление длины вектора
    double length() const {
        return sqrt(x_ * x_ + y_ * y_);
    }

    // сложение двух векторов
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    // вычитание двух векторов
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }

    // умножение вектора на число 
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    // скалярное произведение двух векторов (перегрузка)
    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    // проверка на равенство векторов
    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    // проверка на неравенство векторов
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // унарный минус, изменение направления вектора
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    // вывод вектора в формате (x, y)
    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x_ << ", " << v.y_ << ")";
        return out;
    }
};

int main() {
    Vector2D a(3, 4);
    Vector2D b(1, 2);

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;

    cout << "a * 2 = " << a * 2 << endl;

    cout << "a * b = " << a * b << endl;

    cout << "длина вектора a = " << a.length() << endl;

    cout << "-a = " << -a << endl;

    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;

    return 0;
}