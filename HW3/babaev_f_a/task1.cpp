#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

//1
long long maxProductOfTwo(const std::vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int num : nums) {
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }

        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    return std::max(static_cast<long long>(max1) * max2, 
                    static_cast<long long>(min1) * min2);
}

int main() {
    std::vector<std::vector<int>> tests1 = {
        {1, 2, 3}, 
        {1, 2, 3, 6}, 
        {-7, -19, 6, 4}
    };
    for (const auto& t : tests1) {
        std::cout << "[";
        for(int x : t) std::cout << x << " ";
        std::cout << "] -> " << maxProductOfTwo(t) << "\n";
    }
    return 0;
}