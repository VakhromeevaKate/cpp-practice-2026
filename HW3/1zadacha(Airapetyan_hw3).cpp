#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept>
#include <cassert>
#include <algorithm>
using namespace std;

long long maxProduct(const vector<int>& nums) {
    if (nums.size() < 2)
        throw invalid_argument("Нужно минимум два числа");

    long long max1 = LLONG_MIN, max2 = LLONG_MIN; 
    long long min1 = LLONG_MAX, min2 = LLONG_MAX; 

    for (int v : nums) {
        long long x = v;

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

    return max(max1 * max2, min1 * min2);
}

int main() {
    assert(maxProduct({1, 2, 3}) == 6);
    assert(maxProduct({1, 2, 3, 4}) == 12);
    assert(maxProduct({-1, -2, -3, 1}) == 6);
    assert(maxProduct({-10, -10, 5, 2}) == 100);
    assert(maxProduct({-5, 3}) == -15);
    assert(maxProduct({0, -1}) == 0);
    cout << "Задача 1: все тесты пройдены" << endl;
    return 0;
}