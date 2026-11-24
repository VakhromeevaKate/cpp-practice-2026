/**
 Задача 1. Класс Complex: перегрузка операторов (20 мин)
 Тема: инкапсуляция, конструкторы, перегрузка арифметических операторов и <<.
 Условие. Реализуйте класс комплексных чисел Complex с приватными полями re и im.
 Перегрузите:
 - operator+, operator-, operator* — арифметика;
 - operator- (унарный) — знак; 
 - operator+= — накопление;
 - operator== и operator!= — сравнение;
 - operator<< — вывод в формате a+bi или a-bi.
 */

#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

class Complex {
private:
    double re_, im_;

public:
    Complex(double re = 0, double im = 0) : re_(re), im_(im) {}

    double real() const { return re_; }
    double imag() const { return im_; }

    Complex operator+(const Complex& other) const {
        return Complex(re_ + other.re_, im_ + other.im_);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re_ - other.re_, im_ - other.im_);
    }

    Complex operator*(const Complex& other) const {
        return Complex(re_ * other.re_ - im_ * other.im_,
                       re_ * other.im_ + im_ * other.re_);
    }

    Complex operator-() const {
        return Complex(-re_, -im_);
    }

    Complex& operator+=(const Complex& other) {
        re_ += other.re_;
        im_ += other.im_;
        return *this;
    }

    bool operator==(const Complex& other) const {
        return re_ == other.re_ && im_ == other.im_;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.re_;
    if (c.im_ >= 0) os << "+";
    os << c.im_ << "i";
    return os;
}

void runTests() {
    Complex a(3, 4), b(1, -2);

    assert((a + b) == Complex(4, 2));
    assert((a - b) == Complex(2, 6));
    assert((a * b) == Complex(11, -2));
    assert((-a) == Complex(-3, -4));
    assert((-b) == Complex(-1, 2));

    Complex c(1, 1);
    c += a;
    assert(c == Complex(4, 5));

    assert(a != b);
    assert(a == Complex(3, 4));

    // Проверка вывода
    ostringstream out;
    out << a << " " << b;
    assert(out.str() == "3+4i 1-2i");

    cout << "Задача 1: все тесты пройдены!\n";
}

int main() {
    runTests();
    Complex a(3, 4), b(1, -2);
    cout << "a + b = " << a + b << "\n";
    cout << "a * b = " << a * b << "\n";
    cout << "-a    = " << -a << "\n";
    return 0;
}