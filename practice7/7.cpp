/*
Блок 7. Файловая система и обработка ошибок
Заголовки: <filesystem>, <stdexcept>, <cassert>
Для чего: Работа с путями, создание папок, итерация по файлам.
Исключения для ошибок (деление на ноль, неверный ввод).
*/

#include <iostream>
#include <filesystem>
#include <stdexcept>
#include <cassert>

namespace fs = std::filesystem;

int divide(int a, int b) {
    if (b == 0) throw std::invalid_argument("Division by zero!");
    return a / b;
}

int main() {
    // Filesystem (C++17)
    fs::path p = "my_folder";
    if (!fs::exists(p)) {
        fs::create_directory(p);
        std::cout << "Created directory: " << p << "\n";
    }
    
    // Обработка ошибок через исключения
    try {
        std::cout << "10 / 2 = " << divide(10, 2) << "\n";
        std::cout << "10 / 0 = " << divide(10, 0) << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
    // Assert — для отладки (выключается в релизе через NDEBUG)
    assert(2 + 2 == 4);
    std::cout << "Assert passed\n";
    return 0;
}