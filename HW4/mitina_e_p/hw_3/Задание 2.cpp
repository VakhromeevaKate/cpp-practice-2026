#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int rob(const vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 2; i <= n; i++) {
        int current = max(prev1, nums[i - 1] + prev2);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

void runTests() {
    assert(rob({1, 2, 3, 1}) == 4);
    assert(rob({2, 7, 9, 3, 1}) == 12);
    assert(rob({5}) == 5);
    assert(rob({2, 1}) == 2);
    assert(rob({}) == 0);

    assert(rob({2, 1, 1, 2}) == 4);
    assert(rob({1, 2, 3, 1, 5}) == 9);
    assert(rob({10, 1, 10, 1, 10}) == 30);
    assert(rob({1, 1, 1, 1}) == 2);
    assert(rob({5, 3, 4, 11, 2}) == 16);

    cout << "Все тесты пройдены" << endl;
}

int main() {
    runTests();

    vector<int> demo = {2, 7, 9, 3, 1};

    cout << "Массив: [2, 7, 9, 3, 1]" << endl;
    cout << "Максимальная сумма: "
         << rob(demo) << endl;

    return 0;
}

// Сложность: O(n) по времени, O(1) по памяти.
