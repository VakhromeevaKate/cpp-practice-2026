/*
Задача 3. Иерархия фигур: абстрактный класс и полиморфизм (10 мин)
Тема: чисто виртуальные функции, override, работа через базовый интерфейс.
Условие. Создайте абстрактный класс Shape с чисто виртуальными area(), perimeter(), name().
Реализуйте Circle, Rectangle, Triangle.
Напишите функцию printAll, принимающую vector<unique_ptr<Shape>>.
*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

constexpr double PI = 3.14159265358979323846;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() = default;

    void describe() const {
        cout << name() << ": area=" << area()
             << ", perimeter=" << perimeter() << "\n";
    }
};

class Circle : public Shape {
    double r_;
public:
    Circle(double r) : r_(r) {}
    double area() const override { return PI * r_ * r_; }
    double perimeter() const override { return 2 * PI * r_; }
    string name() const override { return "Circle"; }
};

class Rectangle : public Shape {
    double w_, h_;
public:
    Rectangle(double w, double h) : w_(w), h_(h) {}
    double area() const override { return w_ * h_; }
    double perimeter() const override { return 2 * (w_ + h_); }
    string name() const override { return "Rectangle"; }
};

class Triangle : public Shape {
    double a_, b_, c_;
public:
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}
    double perimeter() const override { return a_ + b_ + c_; }
    double area() const override {
        double p = perimeter() / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }
    string name() const override { return "Triangle"; }
};

void printAll(const vector<unique_ptr<Shape>>& shapes) {
    for (const auto& s : shapes) {
        s->describe();   // полиморфный вызов
    }
}

void runTests() {
    Circle c(1);
    assert(fabs(c.area() - PI) < 1e-9);
    assert(fabs(c.perimeter() - 2 * PI) < 1e-9);

    Rectangle r(3, 4);
    assert(r.area() == 12);
    assert(r.perimeter() == 14);

    Triangle t(3, 4, 5);
    assert(fabs(t.area() - 6) < 1e-9);
    assert(t.perimeter() == 12);

    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(1));
    shapes.push_back(make_unique<Rectangle>(3, 4));
    shapes.push_back(make_unique<Triangle>(3, 4, 5));

    // Проверяем, что полиморфизм работает
    assert(shapes[0]->name() == "Circle");
    assert(shapes[1]->name() == "Rectangle");
    assert(shapes[2]->name() == "Triangle");

    cout << "Задача 3: все тесты пройдены!\n";
}

int main() {
    runTests();
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(1));
    shapes.push_back(make_unique<Rectangle>(3, 4));
    shapes.push_back(make_unique<Triangle>(3, 4, 5));
    printAll(shapes);
    return 0;
}