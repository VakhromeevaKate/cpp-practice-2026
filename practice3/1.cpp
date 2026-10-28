// Задача 1. «Максимальная сумма подмассива»
// Тема: 1D ДП, алгоритм Кадане.

// Условие: Дан массив целых чисел (могут быть отрицательные).
// Найдите максимальную сумму непрерывного подмассива
// (подмассив — это отрезок массива, содержащий хотя бы один элемент).

// Примеры:
// [-2, 1, -3, 4, -1, 2, 1, -5, 4]  → 6   (подмассив [4, -1, 2, 1])
// [1]                               → 1
// [5, 4, -1, 7, 8]                  → 23  (весь массив)
// [-3, -1, -5]                      → -1  (только элемент -1)

// Разбор по шагам ДП:

// Состояние: DP[i] — максимальная сумма подмассива, который заканчивается на позиции i.
// Рекуррентность:
// Если DP[i-1] > 0: продолжать выгодно → DP[i] = DP[i-1] + arr[i].
// Иначе: начинать заново → DP[i] = arr[i].
// Вместе: DP[i] = max(arr[i], DP[i-1] + arr[i]).
// База: DP[0] = arr[0].
// Порядок: слева направо.

// Ответ: max(DP[i]) по всем i — не DP[n-1], потому что максимум может быть не в конце.

// Почему здесь ДП: у задачи есть 2 необходимых свойства для ДП:
// - оптимальная подструктура (максимум подмассива, кончающегося в i, зависит только от i-1)
// - перекрывающиеся подзадачи.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int maxSubarraySum(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int current = arr[0];  // DP[i]
    int best = arr[0];     // max(DP[i])

    for (int i = 1; i < n; i++) {
        current = max(arr[i], current + arr[i]);
        best = max(best, current);
    }
    return best;
}

void runTests() {
    assert(maxSubarraySum({-2,1,-3,4,-1,2,1,-5,4}) == 6);
    assert(maxSubarraySum({1}) == 1);
    assert(maxSubarraySum({5,4,-1,7,8}) == 23);
    assert(maxSubarraySum({-3,-1,-5}) == -1);
    assert(maxSubarraySum({-1}) == -1);
    assert(maxSubarraySum({0}) == 0);
    assert(maxSubarraySum({2, -1, 2, 3}) == 6);
    assert(maxSubarraySum({-2,-3,-1,0}) == 0);
    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();

    // Демонстрация
    vector<int> demo = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Ответ: " << maxSubarraySum(demo) << endl;
    return 0;
}

// Сложность: O(n) по времени, O(1) по памяти.