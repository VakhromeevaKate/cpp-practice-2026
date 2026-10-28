#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Тимашёв Михаил, гр. 640-02

class Vector2D {

private:
    double x_, y_;

public:
    Vector2D() : x_(0), y_(0) {} // по умолчанию нулевой вектор
    Vector2D(double x, double y) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }
    double length() const { return sqrt(x_*x_ + y_*y_); }
    
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x(), y_ + other.y());
    }
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x(), y_ - other.y());
    }
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }
    double operator*(const Vector2D& other) const {
        return x_ * other.x() + y_ * other.y();
    }
    
    bool operator==(const Vector2D& other) const {
        return x_ == other.x() && y_ == other.y();
    }
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }
    
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x() << ", " << v.y() << ")";
    return os;
}

Vector2D vector_a = Vector2D(2, 6);
Vector2D vector_b = Vector2D(4, 2);
Vector2D vector_c = Vector2D(3, 4);

int main() {
    cout << "вектор a " << vector_a << endl;
    cout << "вектор b " << vector_b << endl;
    cout << "a + b = " << vector_a + vector_b << endl;
    cout << "a - b = " << vector_a - vector_b << endl << endl;

    cout << "вектор c " << vector_c << endl;
    cout << "длина c = " << vector_c.length() << endl;
    cout << "противоположный вектор: (" << -vector_c.x() << ", " << -vector_c.y() << ")" << endl << endl;
    
    cout << "c * 3 = " << vector_c * 3 << endl;
    cout << "a * b = " << (vector_a * vector_b) << endl << endl;
    
    cout << "a == b: " << (vector_a == vector_b) << endl;
    cout << "a != b: " << (vector_a != vector_b);
}
