#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x_;
    double y_;

public:
    Vector2D(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

    // геттер
    double x() const { return x_; }
    double y() const { return y_; }

    // длина
    double length() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    // сложение
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    // вычитание
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }
    // умножение
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    // скалярное произведение
    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    // равенство
    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    // неравенство
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // противоположный вектор
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }
};

// Вывод
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x() << ", " << v.y() << ")";
    return os;
}

int main() {
    Vector2D a(1, 1);
    Vector2D b(2, 1);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * 2 = " << (a * 2) << "\n";
    std::cout << "a * b (скалярное) = " << (a * b) << "\n";
    std::cout << "|a| = " << a.length() << "\n";
    std::cout << "-a = " << (-a) << "\n";
    std::cout << "a == b? " << (a == b) << "\n";
    std::cout << "a != b? " << (a != b) << "\n";

    return 0;
}