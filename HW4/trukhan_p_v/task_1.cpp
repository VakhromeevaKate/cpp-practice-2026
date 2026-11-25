#include <iostream>
#include <cmath>

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

    Vector2D operator+(const Vector2D& o) const {
        return Vector2D(x_ + o.x_, y_ + o.y_);
    }

    Vector2D operator-(const Vector2D& o) const {
        return Vector2D(x_ - o.x_, y_ - o.y_);
    }

    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    double operator*(const Vector2D& o) const {
        return x_ * o.x_ + y_ * o.y_;
    }

    bool operator==(const Vector2D& o) const {
        return x_ == o.x_ && y_ == o.y_;
    }

    bool operator!=(const Vector2D& o) const {
        return !(*this == o);
    }

    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    friend ostream& operator<<(ostream& os, const Vector2D& v);
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x_ << ", " << v.y_ << ")";
    return os;
}

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    
    cout << "v1.length() = " << v1.length() << endl;
    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;
    cout << "v1 * 2.0 = " << v1 * 2.0 << endl;
    cout << "v1 * v2 = " << v1 * v2 << endl;
    cout << "v1 == v2? " << (v1 == v2) << endl;
    cout << "v1 != v2? " << (v1 != v2) << endl;
    cout << "-v1 = " << -v1 << endl;

    return 0;
}