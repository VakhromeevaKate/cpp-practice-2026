// Домашнее задание 3. Задача 2. «Ограбление домов» (House Robber)
// Тема: 1D ДП, оптимизация памяти.

// Условие: В каждом доме i лежит nums[i] денег. Нельзя грабить два соседних дома.
// Найдите максимальную сумму, которую можно украсть.

// Примеры:
// [1, 2, 3, 1]    -> 4   (грабим дома 0 и 2: 1 + 3 = 4)
// [2, 7, 9, 3, 1] -> 12  (2 + 9 + 1)
// [5]             -> 5
// [2, 1]          -> 2   (грабим более дорогой дом)
// []              -> 0

// Разбор по четырём шагам ДП:
// Состояние: DP[i] — максимальная сумма, которую можно украсть из первых i домов.
//
// Рекуррентность: рассматриваем последний (i-й) дом, то есть nums[i-1]:
//   - не грабим дом i-1: ответ = DP[i-1];
//   - грабим дом i-1: тогда дом i-2 грабить нельзя, ответ = nums[i-1] + DP[i-2].
//   Итого: DP[i] = max(DP[i-1], nums[i-1] + DP[i-2]).
//
// База: DP[0] = 0 (нет домов), DP[1] = nums[0] (один дом — грабим его).
//
// Порядок: по возрастанию i.
//
// Ответ: DP[n].

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

// Классическая версия: O(n) памяти
int robClassic(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

// Оптимизация памяти: O(1)
// Для DP[i] нужны только DP[i-1] и DP[i-2], поэтому храним две переменные.
int robOptimized(const vector<int>& nums) {
    int prev2 = 0; // DP[i-2]
    int prev1 = 0; // DP[i-1]

    for (int i = 0; i < (int)nums.size(); i++) {
        int cur = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

void runTests() {
    // Примеры из условия
    assert(robOptimized({1, 2, 3, 1}) == 4);
    assert(robOptimized({2, 7, 9, 3, 1}) == 12);
    assert(robOptimized({5}) == 5);
    assert(robOptimized({2, 1}) == 2);
    assert(robOptimized({}) == 0);

    // Ещё несколько проверок
    assert(robOptimized({2, 1, 1, 2}) == 4);
    assert(robOptimized({10, 1, 1, 10}) == 20);

    // Проверка, что обе версии дают одинаковый ответ
    assert(robClassic({1, 2, 3, 1}) == robOptimized({1, 2, 3, 1}));
    assert(robClassic({2, 7, 9, 3, 1}) == robOptimized({2, 7, 9, 3, 1}));
    assert(robClassic({5}) == robOptimized({5}));
    assert(robClassic({2, 1}) == robOptimized({2, 1}));
    assert(robClassic({}) == robOptimized({}));
    assert(robClassic({2, 1, 1, 2}) == robOptimized({2, 1, 1, 2}));

    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();
    cout << "[2, 7, 9, 3, 1] = " << robClassic({2, 7, 9, 3, 1}) << endl;
    cout << "[1, 2, 3, 1] = " << robClassic({1, 2, 3, 1}) << endl;
    return 0;
}

// Сложность: O(n) по времени; O(n) памяти в классической версии, O(1) в оптимизированной.