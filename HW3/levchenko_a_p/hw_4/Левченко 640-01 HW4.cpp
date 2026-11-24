#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x_;
    double y_;

public:
    // Конструктор
    Vector2D(double x = 0, double y = 0)
        : x_(x), y_(y) {}

    // Геттеры
    double x() const {
        return x_;
    }

    double y() const {
        return y_;
    }

    // Длина вектора
    double length() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    // Сложение векторов
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    // Вычитание векторов
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

    // Сравнение векторов
    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // Противоположный вектор
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    // Вывод
    friend std::ostream& operator<<(std::ostream& os,
                                    const Vector2D& v) {
        os << "(" << v.x_ << ", " << v.y_ << ")";
        return os;
    }
};

//Проверка  
int main() {
    Vector2D a(5, 7);
    Vector2D b(2, 4);

    std::cout << "Length of a = " << a.length() << '\n';
    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a - b = " << a - b << '\n';
    std::cout << "a * 2 = " << a * 2 << '\n';
    std::cout << "a * b = " << a * b << '\n';
    std::cout << "a == b: " << (a == b) << '\n';
    std::cout << "a != b: " << (a != b) << '\n';
    std::cout << "-a = " << -a << '\n';
    return 0;
}
