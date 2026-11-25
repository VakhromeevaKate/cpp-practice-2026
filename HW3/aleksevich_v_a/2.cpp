#include <bits/stdc++.h>
using namespace std;

// Задача 2. House Robber.
// dp[i] = max(dp[i-1], nums[i-1] + dp[i-2])
// Храним только два последних значения: prev1 (= dp[i-1]), prev2 (= dp[i-2]).
// Сложность O(n) по времени, O(1) по памяти.

int rob(const vector<int>& nums) {
    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]

    for (int x : nums) {
        int cur = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1; // это dp[n]
}

int main() {
    cout << rob({1, 2, 3, 1})    << "\n"; // 4
    cout << rob({2, 7, 9, 3, 1}) << "\n"; // 12
    cout << rob({5})             << "\n"; // 5
    cout << rob({2, 1})          << "\n"; // 2
    cout << rob({})              << "\n"; // 0
    return 0;
}
