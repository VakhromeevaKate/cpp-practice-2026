#include "Vector2D.hpp"

#include <cmath>

namespace {

constexpr double kEps = 1e-9;


Vector2D::Vector2D(double x, double y) : x_(x), y_(y) {}

double Vector2D::x() const { return x_; }
double Vector2D::y() const { return y_; }

double Vector2D::length() const { return std::sqrt(x_ * x_ + y_ * y_); }

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x_ + other.x_, y_ + other.y_);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x_ - other.x_, y_ - other.y_);
}

Vector2D Vector2D::operator-() const { return Vector2D(-x_, -y_); }

Vector2D Vector2D::operator*(double k) const { return Vector2D(x_ * k, y_ * k); }

double Vector2D::operator*(const Vector2D& other) const {
    return x_ * other.x_ + y_ * other.y_;
}

bool Vector2D::operator==(const Vector2D& other) const {
    return std::fabs(x_ - other.x_) < kEps && std::fabs(y_ - other.y_) < kEps;
}

bool Vector2D::operator!=(const Vector2D& other) const { return !(*this == other); }

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    return os << "(" << v.x() << ", " << v.y() << ")";
}
