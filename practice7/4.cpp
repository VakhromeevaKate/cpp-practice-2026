/*
Блок 4. Алгоритмы
Заголовки: <algorithm>, <numeric>
Для чего: Сортировка, поиск, суммирование, трансформация.
«Cердце» STL.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    
    // Сортировка
    std::sort(v.begin(), v.end());
    std::cout << "Sorted: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
    
    // Поиск
    auto it = std::find(v.begin(), v.end(), 5);
    std::cout << "Find 5 at: " << (it - v.begin()) << "\n";
    
    // Сумма (accumulate)
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Sum: " << sum << "\n";
    
    // Мин/макс
    std::cout << "Min/Max: " << *std::min_element(v.begin(), v.end()) 
              << " / " << *std::max_element(v.begin(), v.end()) << "\n";
    
    // Трансформация (умножение на 2)
    std::vector<int> doubled(v.size());
    std::transform(v.begin(), v.end(), doubled.begin(), [](int x){ return x * 2; });
    std::cout << "Doubled: ";
    for (int x : doubled) std::cout << x << " ";
    std::cout << "\n";
    
    // Идиома remove-erase (удаление дубликатов)
    v.erase(std::unique(v.begin(), v.end()), v.end());
    std::cout << "Unique: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}