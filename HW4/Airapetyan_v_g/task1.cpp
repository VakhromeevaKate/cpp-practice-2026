#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

class Vector2D {
private:
    double x_;
    double y_;

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

    // умножение на число
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    // скалярное произведение
    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // противоположный вектор
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x_ << ", " << v.y_ << ")";
        return out;
    }
};

int main() {
    Vector2D a(3, 4);
    Vector2D b(1, 2);
    Vector2D zero;

    assert(a.x() == 3 && a.y() == 4);
    assert(zero.x() == 0 && zero.y() == 0);
    assert(a.length() == 5);
    assert(a + b == Vector2D(4, 6));
    assert(a - b == Vector2D(2, 2));
    assert(a * 2 == Vector2D(6, 8));
    assert(a * b == 11);
    assert(-a == Vector2D(-3, -4));
    assert(a != b);
    assert(!(a != Vector2D(3, 4)));

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "a * b = " << a * b << endl;
    cout << "-a = " << -a << endl;
    cout << "|a| = " << a.length() << endl;
    cout << "Все тесты пройдены" << endl;
    return 0;
}
