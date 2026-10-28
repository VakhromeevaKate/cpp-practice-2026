/*
Блок 2. Строки и символы
Заголовки: <string>, <string_view>, <cctype>
Для чего: Поиск подстрок, замена, конвертация чисел, 
классификация символов (буква/цифра), 
string_view для передачи без копирования.
*/

#include <iostream>
#include <string>
#include <string_view>
#include <cctype>

int main() {
    std::string s = "Hello, World!";
    
    // Поиск и подстроки
    std::cout << "Find 'World': " << s.find("World") << "\n"; // 7
    std::cout << "Substr: " << s.substr(7, 5) << "\n";        // World
    
    // Конвертация
    int num = std::stoi("123");
    std::string str = std::to_string(456);
    std::cout << "num+1: " << num + 1 << ", str+'!': " << str + "!" << "\n";
    
    // Классификация символов
    for (char c : s) {
        if (std::isalpha(c)) std::cout << (char)std::toupper(c);
    }
    std::cout << "\n";
    
    // string_view — «вид» на строку без копирования
    std::string_view sv(s);
    std::cout << "View: " << sv.substr(0, 5) << "\n";
    return 0;
}