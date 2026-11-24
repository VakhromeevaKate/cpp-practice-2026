#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    if (n == 0) { std::cout << 0 << std::endl; return 0; }
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) std::cin >> nums[i];
    if (n == 1) { std::cout << nums[0] << std::endl; return 0; }

    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; ++i) {
        int current = std::max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = current;
    }
    std::cout << prev1 << std::endl;
    return 0;
}
