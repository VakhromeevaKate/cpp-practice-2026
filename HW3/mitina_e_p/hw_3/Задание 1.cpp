#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>

using namespace std;

int maxProduct(const vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int max1 = INT_MIN;
    int max2 = INT_MIN;

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (int x : nums) {
        // Находим два максимальных числа
        if (x > max1) {
            max2 = max1;
            max1 = x;
        }
        else if (x > max2) {
            max2 = x;
        }

        // Находим два минимальных числа
        if (x < min1) {
            min2 = min1;
            min1 = x;
        }
        else if (x < min2) {
            min2 = x;
        }
    }

    return max(max1 * max2, min1 * min2);
}

void runTests() {
    assert(maxProduct({1, 2, 3}) == 6);
    assert(maxProduct({1, 2, 3, 4}) == 12);
    assert(maxProduct({-1, -2, -3, 1}) == 6);
    assert(maxProduct({-10, -10, 5, 2}) == 100);

    assert(maxProduct({-5, -4, -3}) == 20);
    assert(maxProduct({-1, 0, 2}) == 0);
    assert(maxProduct({0, 1, 2}) == 2);
    assert(maxProduct({5, 5, 1}) == 25);
    assert(maxProduct({-10, -2, -1}) == 20);

    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();

    vector<int> demo = {-10, -10, 5, 2};

    cout << "Массив: [-10, -10, 5, 2]" << endl;
    cout << "Максимальное произведение: "
         << maxProduct(demo) << endl;

    return 0;
}

// Сложность: O(n) по времени, O(1) по памяти.
