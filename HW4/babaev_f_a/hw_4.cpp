#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x_;
    double y_;

public:
    // Конструктор
    Vector2D(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}
    // Геттеры
    double x() const { return x_; }
    double y() const { return y_; }
    // Длина вектора
    double length() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }
    // Покомпонентное сложение
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }
    // Покомпонентное вычитание
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }
    // Умножение на скаляр
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }
    // Скалярное произведение
    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }
    // Оператор равенства
    bool operator==(const Vector2D& other) const {
        return (x_ == other.x_) && (y_ == other.y_);
    }
    // Оператор неравенства
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }
    // Унарный минус
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }
    // Oператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x_ << ", " << v.y_ << ")";
        return os;
    }
};

// Тест
int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(0.0, 0.0);
    Vector2D v3(1.0, 2.0);

    std::cout << "Длина v1: " << v1.length() << "\n";

    std::cout << "v1 + v3 = " << v1 + v3 << "\n";
    std::cout << "v1 - v3 = " << v1 - v3 << "\n";

    std::cout << "v1 * 2.0 = " << v1 * 2.0 << "\n";
    std::cout << "v1 * v3 = " << v1 * v3 << "\n";

    std::cout << "-v1 = " << -v1 << "\n";

    Vector2D v4(3.0, 4.0);
    std::cout << "v1 == v4: " << (v1 == v4 ? "true" : "false") << "\n";
    std::cout << "v1 != v3: " << (v1 != v3 ? "true" : "false") << "\n";

    return 0;
}
