// Задача 4. Висячие ссылки и их опасность
// Условие. Дан фрагмент кода.
// Найдите проблему и объясните, почему это неопределённое поведение.
// Предложите безопасный вариант.

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"one", "two", "three"};
    std::string& ref = words[0];
    std::cout << ref << "\n";   // ???
    words.clear();
    words.assign({"asldklaksd", "kaslkads"});
    std::cout << ref << "\n";   // ???
    words.clear();
    std::cout << words[100] << "\n";   // ???

    return 0;
}