// Задача 2. «Ограбление домов» (House Robber)
// Тема: 1D ДП, оптимизация памяти.

// Условие: В каждом доме i лежит nums[i] денег.
// Нельзя грабить два соседних дома.
// Найдите максимальную сумму, которую можно украсть.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int dp_i2 = 0; // DP[i-2]
    int dp_i1 = 0; // DP[i-1]

    for (int x : nums) {
        int dp_i = max(dp_i1, dp_i2 + x); // DP[i]
        dp_i2 = dp_i1;
        dp_i1 = dp_i;
    }
    return dp_i1; // DP[n]
}

int main() {
    vector<vector<int>> tests = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
        {5},
        {2, 1},
        {}
    };

    for (auto& t : tests) {
        cout << rob(t) << endl;
    }
    return 0;
}