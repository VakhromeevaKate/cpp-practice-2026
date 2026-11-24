#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stdexcept>

long long maxProduct(const std::vector<int>& a) {
    if (a.size() < 2)
        throw std::invalid_argument("Нужно минимум два числа");

    long long max1 = LLONG_MIN, max2 = LLONG_MIN; // max1 >= max2
    long long min1 = LLONG_MAX, min2 = LLONG_MAX; // min1 <= min2

    for (int x : a) {
        if (x > max1)      { max2 = max1; max1 = x; }
        else if (x > max2) { max2 = x; }

        if (x < min1)      { min2 = min1; min1 = x; }
        else if (x < min2) { min2 = x; }
    }
    return std::max(max1 * max2, min1 * min2);
}

int main() {
    std::vector<std::vector<int>> tests = {
        {1, 2, 3},          // 6
        {1, 2, 3, 4},       // 12
        {-1, -2, -3, 1},    // 6
        {-10, -10, 5, 2}    // 100
    };
    for (const auto& t : tests)
        std::cout << maxProduct(t) << "\n";
}
