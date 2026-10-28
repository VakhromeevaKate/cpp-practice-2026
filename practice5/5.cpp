/*
Задача 5. Класс Fraction: перегрузка и const-корректность (8 мин)
Тема: нормализация состояния, friend-функции, работа с const.
Условие. Реализуйте класс Fraction (обыкновенная дробь) с приватными num_, den_.
Дробь всегда хранится в сокращённом виде, знак — в числителе.
Перегрузите +, *, <, ==, <<.
*/

#include <iostream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <stdexcept>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

class Fraction {
private:
    int num_, den_;

    void reduce() {
        if (den_ == 0) throw invalid_argument("denominator is zero");
        int g = gcd(num_, den_);
        num_ /= g;
        den_ /= g;
        if (den_ < 0) { num_ = -num_; den_ = -den_; }  // знак в числителе
    }

public:
    Fraction(int num = 0, int den = 1) : num_(num), den_(den) {
        reduce();
    }

    int numerator() const { return num_; }
    int denominator() const { return den_; }

    Fraction operator+(const Fraction& o) const {
        return Fraction(num_ * o.den_ + o.num_ * den_, den_ * o.den_);
    }

    Fraction operator*(const Fraction& o) const {
        return Fraction(num_ * o.num_, den_ * o.den_);
    }

    bool operator<(const Fraction& o) const {
        return num_ * o.den_ < o.num_ * den_;
    }

    bool operator==(const Fraction& o) const {
        return num_ == o.num_ && den_ == o.den_;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
    if (f.den_ == 1) os << f.num_;
    else             os << f.num_ << "/" << f.den_;
    return os;
}

void runTests() {
    Fraction a(2, 4);   // должна сократиться до 1/2
    assert(a.numerator() == 1);
    assert(a.denominator() == 2);

    Fraction b(-3, -6); // знак в числителе → 1/2
    assert(b == a);

    Fraction c(1, 3);
    assert((a + c) == Fraction(5, 6));
    assert((a * c) == Fraction(1, 6));
    assert(c < a);

    ostringstream os;
    os << a << " " << c << " " << Fraction(3, 1);
    assert(os.str() == "1/2 1/3 3");

    // Проверка деления на ноль
    bool thrown = false;
    try { Fraction bad(1, 0); }
    catch (const invalid_argument&) { thrown = true; }
    assert(thrown);

    cout << "Задача 5: все тесты пройдены!\n";
}

int main() {
    runTests();
    cout << "1/2 + 1/3 = " << Fraction(1, 2) + Fraction(1, 3) << "\n";
    cout << "1/2 * 1/3 = " << Fraction(1, 2) * Fraction(1, 3) << "\n";
    return 0;
}