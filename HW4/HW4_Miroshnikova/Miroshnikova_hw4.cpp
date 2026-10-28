// Задача 1 - Vector2D

#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x_;
    double y_;

public:
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    double length() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }

    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }
};

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x() << ", " << v.y() << ")";
    return os;
}

int main() {
    Vector2D a(1, 2);
    Vector2D b(3, 4);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a - b = " << a - b << "\n";

    std::cout << "a * 2 = " << a * 2 << "\n";
    std::cout << "a * b = " << a * b << "\n";

    std::cout << "length(a) = " << a.length() << "\n";

    std::cout << "-a = " << -a << "\n";

    Vector2D c(1, 2);
    std::cout << "a == c: " << (a == c) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";

    return 0;
}
