#include <cmath>
#include <iostream>

class Vector2D {
private:
    double x_;
    double y_;

public:
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    double x() const {
        return x_;
    }

    double y() const {
        return y_;
    }

    double length() const {
        return std::hypot(x_, y_);
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

    friend std::ostream& operator<<(std::ostream& out, const Vector2D& v) {
        return out << '(' << v.x_ << ", " << v.y_ << ')';
    }
};

int main() {
    const Vector2D a(3, 4);
    const Vector2D b(1, 2);
    const Vector2D zero;

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "zero = " << zero << '\n';
    std::cout << "a.x() = " << a.x() << '\n';
    std::cout << "a.y() = " << a.y() << '\n';
    std::cout << "a.length() = " << a.length() << '\n';
    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a - b = " << a - b << '\n';
    std::cout << "a * 2 = " << a * 2 << '\n';
    std::cout << "a * b = " << a * b << '\n';
    std::cout << "-a = " << -a << '\n';
    std::cout << std::boolalpha;
    std::cout << "a == b: " << (a == b) << '\n';
    std::cout << "a != b: " << (a != b) << '\n';
    std::cout << "a == Vector2D(3, 4): " << (a == Vector2D(3, 4)) << '\n';

    return 0;
}
