// Задача 2. Ограбление домов (House Robber)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int rob(const std::vector<int>& nums) {
    int prev2 = 0;  
    int prev1 = 0;  

    for (int money : nums) {
        int cur = std::max(prev1, money + prev2);  
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;  
}

int main() {
    // Примеры из условия
    assert(rob({1, 2, 3, 1}) == 4);
    assert(rob({2, 7, 9, 3, 1}) == 12);
    assert(rob({5}) == 5);
    assert(rob({2, 1}) == 2);
    assert(rob({}) == 0);

    // Дополнительные краевые случаи
    assert(rob({0, 0, 0}) == 0);
    assert(rob({1, 1, 1, 1}) == 2);
    assert(rob({10, 1, 1, 10}) == 20);
    assert(rob({1, 3, 1}) == 3);
    assert(rob({6, 1, 1, 6, 1}) == 12);

    std::cout << "Задача 2: все тесты пройдены\n";
    return 0;
}