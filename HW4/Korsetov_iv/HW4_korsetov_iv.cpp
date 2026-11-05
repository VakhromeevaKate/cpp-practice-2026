
#include <iostream>
#include <cmath>
using namespace std;

class Vector2D {
private:
    double x_;
    double y_;

public:
    Vector2D(double x = 0, double y = 0)
        : x_(x), y_(y) {}

    double x() const {
        return x_;
    }

    double y() const {
        return y_;
    }

    // Длина вектора
    double length() const {
        return sqrt(x_ * x_ + y_ * y_);
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

    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        os << "(" << v.x_ << ", " << v.y_ << ")";
        return os;
    }
};

int main() {
    Vector2D a(3, 4);
    Vector2D b(1, 2);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Length a = " << a.length() << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;

    cout << "a * 2 = " << a * 2 << endl;
    cout << "a * b = " << a * b << endl;

    cout << "-a = " << -a << endl;

    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;

    return 0;
}
