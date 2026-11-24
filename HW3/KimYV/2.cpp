#include <iostream>
#include <vector>
#include <algorithm>

int rob(const std::vector<int>& nums) {
    int prev2 = 0; // DP[i-2]
    int prev1 = 0; // DP[i-1]

    for (int x : nums) {
        int cur = std::max(prev1, x + prev2);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

int main() {
    std::vector<int> nums = {2, 7, 9, 3, 1, 9};

    std::cout << rob(nums) << "\n"; // 12

    return 0;
}