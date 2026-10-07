// Задача 3. «Наибольшая возрастающая подпоследовательность» (25 мин)
// Тема: 1D ДП с вложенным циклом, сложность O(n²).

// Условие: Дана последовательность целых чисел.
// Найдите длину наибольшей строго возрастающей подпоследовательности
// (элементы идут в исходном порядке, но не обязательно подряд).

// Примеры:
// [10, 9, 2, 5, 3, 7, 101, 18]  → 4   (подпоследовательность [2, 3, 7, 101])
// [0, 1, 0, 3, 2, 3]            → 4   ([0, 1, 2, 3])
// [7, 7, 7, 7]                  → 1   (строго возрастает — значит, все равные не считаются)
// [1, 2, 3, 4, 5]               → 5
// [5, 4, 3, 2, 1]               → 1

// Разбор по четырём шагам ДП:
// Состояние: DP[i] — длина наибольшей возрастающей подпоследовательности, которая заканчивается на элементе arr[i].

// Рекуррентность: DP[i] = 1 + max{ DP[j] : j < i и arr[j] < arr[i] }. Если таких j нет — DP[i] = 1.

// База: DP[i] = 1 для всех i (каждый элемент сам по себе — подпоследовательность длины 1).

// Порядок: по возрастанию i.

// Ответ: max(DP[i]).

// Идея: мы не требуем, чтобы подпоследовательность заканчивалась в последнем элементе.
// Поэтому ответ — максимум по всей таблице.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int lengthOfLIS(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1); // каждый элемент — минимум 1
    int best = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        best = max(best, dp[i]);
    }
    return best;
}

// Восстановление самой подпоследовательности
vector<int> reconstructLIS(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    int bestIdx = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > dp[bestIdx]) bestIdx = i;
    }

    // Восстанавливаем путь
    vector<int> result;
    for (int i = bestIdx; i != -1; i = parent[i]) {
        result.push_back(arr[i]);
    }
    reverse(result.begin(), result.end());
    return result;
}

void runTests() {
    assert(lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(lengthOfLIS({0, 1, 0, 3, 2, 3}) == 4);
    assert(lengthOfLIS({7, 7, 7, 7}) == 1);
    assert(lengthOfLIS({1, 2, 3, 4, 5}) == 5);
    assert(lengthOfLIS({5, 4, 3, 2, 1}) == 1);
    assert(lengthOfLIS({}) == 0);
    assert(lengthOfLIS({1}) == 1);
    assert(lengthOfLIS({1, 3, 6, 7, 9, 4, 10, 5, 6}) == 6);

    // Проверка восстановления
    auto lis = reconstructLIS({10, 9, 2, 5, 3, 7, 101, 18});
    assert(lis.size() == 4);
    // Проверяем, что результат строго возрастает
    for (size_t i = 1; i < lis.size(); i++) {
        assert(lis[i-1] < lis[i]);
    }
    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();

    vector<int> demo = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Длина LIS: " << lengthOfLIS(demo) << endl;

    auto lis = reconstructLIS(demo);
    cout << "Одна из LIS: ";
    for (int x : lis) cout << x << " ";
    cout << endl;

    return 0;
}

// Сложность: O(n²) по времени, O(n) по памяти.