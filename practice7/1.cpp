/*
Блок 1. Ввод-вывод и форматирование
Заголовки: <iostream>, <fstream>, <sstream>, <iomanip>
Для чего: Вывод в консоль, чтение/запись файлов, парсинг строк, выравнивание таблиц.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

int main() {
    // 1. Форматированный вывод (как printf, но безопаснее)
    std::cout << "Hello, std::cout!" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Pi = " << 3.14159 << "\n";

    // 2. Выравнивание (таблицы)
    std::cout << std::setw(10) << std::left << "Name" << "Age\n";
    std::cout << std::setw(10) << std::left << "Alice" << 25 << "\n";

    // 3. Строковые потоки (парсинг строк)
    std::istringstream iss("123 45.6 Hello");
    int a; double b; std::string s;
    iss >> a >> b >> s;
    std::cout << "Parsed: " << a << ", " << b << ", " << s << "\n";

    std::ostringstream oss;
    oss << "Result: " << a + b;
    std::cout << oss.str() << "\n"; // удобно для сборки строк

    // 4. Файловый ввод-вывод
    {
        std::ofstream out("test.txt");
        out << "Line 1\nLine 2\n";
    } // файл закрывается автоматически (RAII)
    std::ifstream in("test.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::cout << "Read: " << line << "\n";
    }
    return 0;
}