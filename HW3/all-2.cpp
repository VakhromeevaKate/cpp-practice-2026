#include <iostream>
#include <vector>
#include <algorithm>

// Этап 1: обычное 1D ДП, память O(n)
int robTable(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    std::vector<int> dp(n + 1, 0);
    dp[1] = nums[0];
    for (int i = 2; i <= n; ++i)
        dp[i] = std::max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    return dp[n];
}

// Этап 2: оптимизация памяти, O(1)
int rob(const std::vector<int>& nums) {
    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]
    for (int x : nums) {
        int cur = std::max(prev1, x + prev2);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    std::vector<std::vector<int>> tests = {
        {1, 2, 3, 1},     // 4
        {2, 7, 9, 3, 1},  // 12
        {5},              // 5
        {2, 1},           // 2
        {}                // 0
    };
    for (const auto& t : tests)
        std::cout << rob(t) << "\n";
}