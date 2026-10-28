/*
Заголовки: <utility>, <tuple>, <optional>, <chrono>
Для чего: Пары значений, кортежи (наборы разных типов),
optional (может быть значение, а может нет),
замер времени.
*/

#include <iostream>
#include <utility>
#include <tuple>
#include <optional>
#include <chrono>
#include <thread>

int main() {
    // Pair — пара значений
    std::pair<int, std::string> p = {1, "one"};
    std::cout << "Pair: " << p.first << ", " << p.second << "\n";
    
    // Tuple — несколько значений разных типов
    auto t = std::make_tuple(42, "hello", 3.14);
    std::cout << "Tuple: " << std::get<0>(t) << ", " 
              << std::get<1>(t) << ", " << std::get<2>(t) << "\n";
    
    // Optional — значение или "ничего"
    std::optional<int> maybe_value = 42;
    if (maybe_value) std::cout << "Optional: " << *maybe_value << "\n";
    std::optional<int> empty = std::nullopt;
    std::cout << "Empty has value? " << empty.has_value() << "\n";
    
    // Chrono — замер времени
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Slept: " << ms.count() << " ms\n";
    return 0;
}