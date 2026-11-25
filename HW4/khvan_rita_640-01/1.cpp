#include <iostream>
#include <cmath> // для std::sqrt

class Vector2D {
private:
    double x_;
    double y_;

public:
    // Конструктор с параметрами по умолчанию
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    // Геттеры (const)
    double x() const { return x_; }
    double y() const { return y_; }

    // Длина вектора (const)
    double length() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    // Оператор сложения (возвращает новый вектор)
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    // Оператор вычитания (возвращает новый вектор)
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }

    // Умножение на скаляр (возвращает новый вектор)
    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    // Скалярное произведение (возвращает число)
    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    // Оператор равенства
    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    // Оператор неравенства
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // Унарный минус (противоположный вектор)
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    // Вывод в поток в формате (x, y)
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x_ << ", " << v.y_ << ")";
        return os;
    }
};

// Пример использования (можно добавить для проверки, но в решении обычно не требуется)
int main() {
    Vector2D a(3.0, 4.0);
    Vector2D b(1.0, 2.0);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * 2 = " << a * 2 << std::endl;
    std::cout << "a * b = " << a * b << std::endl; // скалярное произведение
    std::cout << "-a = " << -a << std::endl;
    std::cout << "Длина a = " << a.length() << std::endl;

    return 0;
}