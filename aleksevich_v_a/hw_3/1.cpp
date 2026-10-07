#include <bits/stdc++.h>
using namespace std;

int max_product(const vector<int>& nums) {
    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int x : nums) {
        if (x > max1) { max2 = max1; max1 = x; }
        else if (x > max2) { max2 = x; }

        if (x < min1) { min2 = min1; min1 = x; }
        else if (x < min2) { min2 = x; }
    }

    return max(max1 * max2, min1 * min2);
}

int main() {
    cout << max_product({1, 2, 3})        << "\n"; // 6
    cout << max_product({1, 2, 3, 4})     << "\n"; // 12
    cout << max_product({-1, -2, -3, 1})  << "\n"; // 6
    cout << max_product({-10, -10, 5, 2}) << "\n"; // 100
    return 0;
}
