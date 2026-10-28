#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cstddef>

int MaxPair(const std::vector<int>& nums) {
    if (nums.size() < 2) {
        throw std::invalid_argument("Нужно хотябы два числа для выполнения функции");
    }

    int max1 = std::max(nums[0], nums[1]);
    int max2 = std::min(nums[0], nums[1]);

    int min1 = max2;
    int min2 = max1;

    for (std::size_t i = 2; i < nums.size(); ++i) {
        int x = nums[i];

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

    int proiz1 = max1 * max2;
    int proiz2 = min1 * min2;

    return std::max(proiz1, proiz2);
}

int main() {
    std::cout << MaxPair({1, 2, 3}) << '\n';
    std::cout << MaxPair({1, 2, 3}) << '\n';
    std::cout << MaxPair({1, 2, 3}) << '\n';
    std::cout << MaxPair({1, 2, 3}) << '\n';

    return 0;
    
}