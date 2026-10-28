#include <iostream>
#include <algorithm>
#include <vector>

int HouseRobber(const std::vector<int>& nums) {
    int prev2 = 0;
    int prev1 = 0;

    for (int money : nums) {
        int take = prev2 + money;
        int skip = prev1;

        int current = std::max(take, skip);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    std::cout << HouseRobber({1, 2, 3, 1}) << '\n';
    std::cout << HouseRobber({2, 7, 9, 3, 1}) << '\n';
    std::cout << HouseRobber({5}) << '\n';
    std::cout << HouseRobber({2, 1}) << '\n';
    std::cout << HouseRobber({}) << '\n';

    return 0;
}