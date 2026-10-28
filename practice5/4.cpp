/*
Задача 4. Перегрузка функций, скрытие и using (7 мин)
Тема: перегрузка методов в одном классе, скрытие имён в наследнике, using для восстановления видимости.
Условие. Реализуйте Printer с тремя перегруженными print.
Наследник FancyPrinter добавляет print(const vector<int>&).
Покажите, что без using базовые перегрузки скрываются, покажите как это исправить.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

class Printer {
public:
    virtual ~Printer() = default;

    virtual string print(int x) {
        return "int: " + to_string(x);
    }
    virtual string print(double x) {
        ostringstream os; os << "double: " << x;
        return os.str();
    }
    virtual string print(const string& s) {
        return "string: " + s;
    }
};

class FancyPrinter : public Printer {
public:
    using Printer::print;   // ← без этой строки базовые перегрузки скрыты!

    string print(const vector<int>& v) {
        string result = "vector:";
        for (int x : v) result += " " + to_string(x);
        return result;
    }
};

void runTests() {
    FancyPrinter fp;

    // Благодаря using, все базовые перегрузки видны
    assert(fp.print(42) == "int: 42");
    assert(fp.print(0.5) == "double: 0.5");
    assert(fp.print("hello") == "string: hello");
    assert(fp.print(vector<int>{1, 2, 3}) == "vector: 1 2 3");

    cout << "Задача 4: все тесты пройдены!\n";
}

int main() {
    runTests();

    // Демонстрация: уберите `using Printer::print;` — и код ниже не скомпилируется
    FancyPrinter fp;
    cout << fp.print(42) << "\n";
    cout << fp.print("hi") << "\n";
    cout << fp.print(vector<int>{1, 2, 3}) << "\n";
    return 0;
}