#include <iostream>
#include <cmath>
using namespace std;

class Vector2D {
private:
    double x_, y_;

public:
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    int x() const { return x_; }
    int y() const { return y_; }

    double length() const { return sqrt(x_ * x_ + y_ * y_); }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_*k);
    }
    double operator*(const Vector2D& other) const {
        return (x_ * other.x_, y_ * other.y_);
    }
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }
    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }
    friend ostream& operator<<(ostream& os, const Vector2D& c);
};

ostream& operator<<(ostream& os, const Vector2D& c) {
    os << "(" << c.x_ << ", " << c.y_ << ")";
    return os;
}


int main(){

    cout << Vector2D(1, 2) + Vector2D(2, 3) << '\n';
    cout << Vector2D(4, 3) - Vector2D(2, 1) << '\n';
    cout << Vector2D(1, 2) * 4 << '\n';
    cout << Vector2D(2, 4) * Vector2D(2, 5) << '\n';


    return 0;
}