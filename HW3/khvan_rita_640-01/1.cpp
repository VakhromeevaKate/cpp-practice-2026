#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    if (n < 2) { std::cout << 0 << std::endl; return 0; }
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) std::cin >> nums[i];

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int x : nums) {
        if (x > max1) { max2 = max1; max1 = x; }
        else if (x > max2) { max2 = x; }
        if (x < min1) { min2 = min1; min1 = x; }
        else if (x < min2) { min2 = x; }
    }
    std::cout << std::max(1LL * max1 * max2, 1LL * min1 * min2) << std::endl;
    return 0;
}
