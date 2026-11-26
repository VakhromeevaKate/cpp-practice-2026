#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long maxProduct(vector<int>& nums) {
    long long max1 = LLONG_MIN, max2 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    for (int x : nums) {
        if (x >= max1) {
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max2 = x;
        }

        if (x <= min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    return max(max1 * max2, min1 * min2);
}

int main() {
    vector<int> nums = {-10, -10, 5, 2};

    if (nums.size() < 2) {
        cout << "Недостаточно чисел";
        return 0;
    }

    cout << maxProduct(nums) << endl;

    return 0;
}
