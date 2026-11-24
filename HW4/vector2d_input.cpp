#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

class Vector2D {
public:
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    double length() const { return sqrt(x_ * x_ + y_ * y_); }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }

    Vector2D operator*(double k) const {
        return Vector2D(x_ * k, y_ * k);
    }

    double operator*(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    bool operator==(const Vector2D& other) const {
        const double eps = 1e-9;
        return fabs(x_ - other.x_) < eps && fabs(y_ - other.y_) < eps;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

private:
    double x_;
    double y_;
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    return os << "(" << v.x() << ", " << v.y() << ")";
}

bool readDouble(const string& prompt, double& value) {
    while (true) {
        cout << prompt;
        if (cin >> value) return true;
        if (cin.eof()) return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: введите число.\n";
    }
}

bool readVector(const string& name, Vector2D& v) {
    double x, y;
    if (!readDouble("Введите x для " + name + ": ", x)) return false;
    if (!readDouble("Введите y для " + name + ": ", y)) return false;
    v = Vector2D(x, y);
    return true;
}

void printMenu() {
    cout << "\n===== Меню =====\n"
         << "1. Длина a и b\n"
         << "2. a + b\n"
         << "3. a - b\n"
         << "4. a * k (на скаляр)\n"
         << "5. a * b (скалярное произведение)\n"
         << "6. a == b\n"
         << "7. a != b\n"
         << "8. -a и -b\n"
         << "9. Ввести новые векторы\n"
         << "0. Выход\n"
         << "Ваш выбор: ";
}

int main() {
    Vector2D a, b;

    cout << "Введите два вектора.\n";
    if (!readVector("a", a)) return 0;
    if (!readVector("b", b)) return 0;

    while (true) {
        cout << "\nТекущие векторы: a = " << a << ", b = " << b << "\n";
        printMenu();

        int choice;
        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите номер пункта меню.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Выход.\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "|a| = " << a.length() << "\n"
                     << "|b| = " << b.length() << "\n";
                break;
            case 2:
                cout << "a + b = " << (a + b) << "\n";
                break;
            case 3:
                cout << "a - b = " << (a - b) << "\n";
                break;
            case 4: {
                double k;
                if (!readDouble("Введите скаляр k: ", k)) return 0;
                cout << "a * " << k << " = " << (a * k) << "\n";
                break;
            }
            case 5:
                cout << "a * b = " << (a * b) << "\n";
                break;
            case 6:
                cout << "a == b: " << (a == b ? "true" : "false") << "\n";
                break;
            case 7:
                cout << "a != b: " << (a != b ? "true" : "false") << "\n";
                break;
            case 8:
                cout << "-a = " << (-a) << "\n"
                     << "-b = " << (-b) << "\n";
                break;
            case 9:
                if (!readVector("a", a)) return 0;
                if (!readVector("b", b)) return 0;
                break;
            default:
                cout << "Нет такого пункта меню.\n";
        }
    }

    return 0;
}
