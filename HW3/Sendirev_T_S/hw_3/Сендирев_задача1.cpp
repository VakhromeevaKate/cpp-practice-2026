// Задача 1. Максимальное произведение двух чисел

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

long long maxProduct(const std::vector<int>& nums) {
    
    if (nums.size() < 2) {
        throw std::invalid_argument("Нужно минимум два числа");
    }

    const long long INF = std::numeric_limits<long long>::max();
    long long max1 = -INF, max2 = -INF;  
    long long min1 = INF, min2 = INF;    

    for (int x : nums) {
        if (x > max1) {
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max2 = x;
        }

        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    return std::max(max1 * max2, min1 * min2);
}

int main() {
    // Примеры из условия
    assert(maxProduct({1, 2, 3}) == 6);
    assert(maxProduct({1, 2, 3, 4}) == 12);
    assert(maxProduct({-1, -2, -3, 1}) == 6);
    assert(maxProduct({-10, -10, 5, 2}) == 100);

    // Примеры из условия
    assert(maxProduct({2, 3}) == 6);
    assert(maxProduct({-2, -3}) == 6);
    assert(maxProduct({-2, 3}) == -6);
    assert(maxProduct({0, 0, 0}) == 0);
    assert(maxProduct({-5, 0, 3}) == 0);
    assert(maxProduct({-1, -2, -3}) == 6);
    assert(maxProduct({5, 5}) == 25);
    assert(maxProduct({100000, 100000}) == 10000000000LL);

    bool thrown = false;
    try {
        maxProduct({1});
    } catch (const std::invalid_argument&) {
        thrown = true;
    }
    assert(thrown);

    std::cout << "Задача 1: все тесты пройдены\n";
    return 0;
}