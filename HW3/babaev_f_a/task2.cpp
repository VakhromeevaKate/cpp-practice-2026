#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

//2
int rob(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        int curr = std::max(prev1, nums[i] + prev2);
        
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    std::vector<std::vector<int>> tests2 = {
        {1, 2, 3, 1}, 
        {5, 2, 7, 5, 1}, 
        {3}, 
        {}
    };
    for (const auto& t : tests2) {
        std::cout << "[";
        for(int x : t) std::cout << x << " ";
        std::cout << "] -> " << rob(t) << "\n";
    }

    return 0;
}