// Задача 2. Ограбление домов (House Robber)
// 1D ДП с оптимизацией памяти до O(1).
// DP[i] = max(DP[i-1], nums[i-1] + DP[i-2])

#include <iostream>
#include <vector>
#include <algorithm>

long long rob(const std::vector<long long>& nums) {
    long long prev2 = 0; // DP[i-2]
    long long prev1 = 0; // DP[i-1]

    for (long long v : nums) {
        long long cur = std::max(prev1, v + prev2);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1; // DP[n]
}

int main() {
    std::cout << rob({1, 2, 3, 1})     << "\n"; // 4
    std::cout << rob({2, 7, 9, 3, 1})  << "\n"; // 12
    std::cout << rob({5})              << "\n"; // 5
    std::cout << rob({2, 1})           << "\n"; // 2
    std::cout << rob({})               << "\n"; // 0
    return 0;
}