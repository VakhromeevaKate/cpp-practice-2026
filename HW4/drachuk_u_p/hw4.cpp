#include <cmath>
#include <iostream>

class Vector2D {
private:
    double x_;
    double y_;

public:
    // Конструктор с параметрами по умолчанию
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    // Геттеры
    double x() const { return x_; }
    double y() const { return y_; }

    // Длина вектора
    double length() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    // Сложение
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    // Вычитание
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

    // Равенство
    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    // Неравенство
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // Унарный минус
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    // Вывод в формате (x, y)
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        return os << "(" << v.x_ << ", " << v.y_ << ")";
    }
};

int main() {
    Vector2D a(3, 4);
    Vector2D b(1, 2);
    Vector2D zero;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "zero = " << zero << "\n";
    std::cout << "a.x() = " << a.x() << ", a.y() = " << a.y() << "\n";
    std::cout << "|a| = " << a.length() << "\n";

    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * 2 = " << (a * 2) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";

    std::cout << "a == b: " << (a == b ? "true" : "false") << "\n";
    std::cout << "a != b: " << (a != b ? "true" : "false") << "\n";
    std::cout << "a == a: " << (a == Vector2D(3, 4) ? "true" : "false") << "\n";

    std::cout << "-a = " << (-a) << "\n";

    return 0;
}