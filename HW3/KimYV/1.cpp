#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int maxProduct(const std::vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int max1 = INT_MIN, max2 = INT_MIN; // два наибольших
    int min1 = INT_MAX, min2 = INT_MAX; // два наименьших

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

    long long prodMax = 1LL * max1 * max2;
    long long prodMin = 1LL * min1 * min2;

    return (int)std::max(prodMax, prodMin);
}

int main() {
    std::vector<int> nums = {-10, -10, 5, 2, 12, 9};

    std::cout << maxProduct(nums) << "\n"; // 100

    return 0;
}