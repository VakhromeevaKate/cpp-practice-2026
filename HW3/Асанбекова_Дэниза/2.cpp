#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<long long> nums;
    long long x;
    while (std::cin >> x) {
        nums.push_back(x);
    }

    int n = nums.size();
    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (n == 1) {
        std::cout << nums[0] << std::endl;
        return 0;
    }

    long long prev2 = 0;      
    long long prev1 = nums[0]; 

    for (int i = 1; i < n; ++i) {
        long long current = std::max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = current;
    }

    std::cout << prev1 << std::endl;
    return 0;
}
