// Задача 2. «Ограбление домов»

// Условие: Вы — грабитель, планирующий ограбление домов на улице.
// В каждом доме i лежит nums[i] денег.
// Единственное ограничение: нельзя грабить два соседних дома (сработает сигнализация).
// Найдите максимальную сумму, которую можно украсть.

// Примеры:
// [1, 2, 3, 1]      → 4   (грабим дома 0 и 2: 1 + 3 = 4)
// [2, 7, 9, 3, 1]   → 12  (грабим дома 0, 2, 4: 2 + 9 + 1 = 12)
// [5]               → 5
// [2, 1]            → 2   (грабим более дорогой дом)
// []                → 0

// Разбор по четырём шагам ДП:
// Состояние: DP[i] — максимальная сумма, которую можно украсть из первых i домов.
// Рекуррентность: рассматриваем последний (i-й) дом:
// - Не грабим дом i-1: ответ = DP[i-1].
// - Грабим дом i-1: тогда дом i-2 грабить нельзя, ответ = nums[i-1] + DP[i-2].
// Итого: DP[i] = max(DP[i-1], nums[i-1] + DP[i-2]).
// Порядок: по возрастанию
// Ответ: DP[n].

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// Классическая версия: O(n) памяти
int rob(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
    }

    return dp[n];
}

// Оптимизация памяти: O(1)
int robOptimized(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = 0;      // DP[i-2]
    int prev1 = nums[0]; // DP[i-1]

    for (int i = 2; i <= n; i++) {
        int current = max(prev1, nums[i-1] + prev2);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

void runTests() {
    assert(robOptimized({1, 2, 3, 1}) == 4);
    assert(robOptimized({2, 7, 9, 3, 1}) == 12);
    assert(robOptimized({5}) == 5);
    assert(robOptimized({2, 1}) == 2);
    assert(robOptimized({}) == 0);
    assert(robOptimized({2, 3, 2}) == 4);
    assert(robOptimized({1, 2}) == 2);
    assert(robOptimized({1, 3, 1}) == 3);
    assert(robOptimized({4, 1, 2, 7, 5, 3, 1}) == 15);

    // Проверка, что оптимизированная версия даёт тот же ответ
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
        {5},
        {2, 1},
        {},
        {2, 3, 2},
        {1, 2},
        {1, 3, 1},
        {4, 1, 2, 7, 5, 3, 1}
    };

    for (const auto& nums : testCases) {
        assert(rob(nums) == robOptimized(nums));
    }

    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();

    vector<int> demo1 = {1, 2, 3, 1};
    vector<int> demo2 = {2, 7, 9, 3, 1};
    cout << "rob({1, 2, 3, 1}) = " << robOptimized(demo1) << endl;
    cout << "rob({2, 7, 9, 3, 1}) = " << robOptimized(demo2) << endl;

    return 0;
}