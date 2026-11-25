#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

class Vector2D {
public:

    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    double length() const { return sqrt(x_ * x_ + y_ * y_); }

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
        const double eps = 1e-9;
        return fabs(x_ - other.x_) < eps && fabs(y_ - other.y_) < eps;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

private:
    double x_;
    double y_;
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    return os << "(" << v.x() << ", " << v.y() << ")";
}

int main() {
    Vector2D zero;
    Vector2D onlyX(5);
    Vector2D a(3, 4);
    Vector2D b(1, 2);

    assert(zero.x() == 0 && zero.y() == 0);
    assert(onlyX.x() == 5 && onlyX.y() == 0);

    assert(fabs(a.length() - 5.0) < 1e-9);

    assert(a + b == Vector2D(4, 6));
    assert(a - b == Vector2D(2, 2));

    assert(-a == Vector2D(-3, -4));

    assert(a * 2 == Vector2D(6, 8));
    assert(fabs(a * b - 11.0) < 1e-9);

    assert(a == Vector2D(3, 4));
    assert(a != b);

    const Vector2D c(6, 8);
    assert(c.length() == 10.0);
    assert(c + a == Vector2D(9, 12));
    assert(c * 0.5 == a);

    ostringstream oss;
    oss << a;
    assert(oss.str() == "(3, 4)");

    cout << "a = " << a << ", b = " << b << "\n";
    cout << "|a| = " << a.length() << ", |b| = " << b.length() << "\n";
    cout << "a + b = " << (a + b) << "\n";
    cout << "a - b = " << (a - b) << "\n";
    cout << "a * 2 = " << (a * 2) << "\n";
    cout << "a * b = " << (a * b) << "\n";
    cout << "a == b: " << (a == b ? "true" : "false") << "\n";
    cout << "a != b: " << (a != b ? "true" : "false") << "\n";
    cout << "-a = " << (-a) << "\n";
    cout << "Все проверки пройдены\n";
    return 0;
}
