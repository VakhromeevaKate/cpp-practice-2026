#include <iostream>
#include <cmath>
class Vector2D {
private:
double x_;
double y_;
public:
// конструктор с параметрами
Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}
// геттеры
double x() const { return x_; }
double y() const { return y_; }
// длина вектора
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
// умножение скаляр
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
// минус
Vector2D operator-() const {
return Vector2D(-x_, -y_);
}
// вывод
friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
os << "(" << v.x_ << ", " << v.y_ << ")";
return os;
}
int main() {
Vector2D v1(3, 4);
Vector2D v2(1, 2);
std::cout << "v1 = " << v1 << "\n";
std::cout << "v2 = " << v2 << "\n";
std::cout << "v1 + v2 = " << v1 + v2 << "\n";
std::cout << "v1 - v2 = " << v1 - v2 << "\n";
std::cout << "v1 * 2 = " << v1 * 2 << "\n";
std::cout << "v1 * v2 (скалярное) = " << v1 * v2 << "\n";
std::cout << "длина v1 = " << v1.length() << "\n";
std::cout << "-v1 = " << -v1 << "\n";
if (v1 == v2) std::cout << "v1 == v2\n";
else std::cout << "v1 != v2\n";
return 0;
}
