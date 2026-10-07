// Задача 2. «Уникальные пути»
// Тема: 2D ДП, оптимизация памяти.

// Условие: Робот стоит в левом верхнем углу сетки m × n.
// Он может двигаться только вправо или вниз.
// Сколько существует уникальных путей до правого нижнего угла?

// Примеры:
// m = 3, n = 7  → 28
// m = 3, n = 2  → 3
// m = 3, n = 3  → 6
// m = 1, n = 1  → 1

// Разбор по четырём шагам ДП:

// 1. Состояние: DP[i][j] — число путей из (0,0) в клетку (i,j).

// 2. Рекуррентность: в (i,j) можно прийти только сверху (i-1,j) или слева (i,j-1), поэтому
// DP[i][j] = DP[i-1][j] + DP[i][j-1].

// 3. База:
// DP[0][j] = 1 — в первой строке только один путь (всё время вправо).
// DP[i][0] = 1 — в первом столбце только один путь (всё время вниз).

// 4. Порядок: по строкам сверху вниз, внутри строки — слева направо.

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Классическая версия: O(m*n) памяти
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

// Оптимизация памяти: O(n)
int uniquePathsOptimized(int m, int n) {
    vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j-1]; // dp[j] = сверху, dp[j-1] = слева
        }
    }
    return dp[n-1];
}

void runTests() {
    assert(uniquePathsOptimized(3, 7) == 28);
    assert(uniquePathsOptimized(3, 2) == 3);
    assert(uniquePathsOptimized(3, 3) == 6);
    assert(uniquePathsOptimized(1, 1) == 1);
    assert(uniquePathsOptimized(1, 5) == 1);
    assert(uniquePathsOptimized(5, 1) == 1);
    assert(uniquePathsOptimized(4, 4) == 20);

    // Проверка, что оптимизированная версия даёт тот же ответ
    for (int m = 1; m <= 8; m++) {
        for (int n = 1; n <= 8; n++) {
            assert(uniquePaths(m, n) == uniquePathsOptimized(m, n));
        }
    }
    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();
    cout << "3x7 = " << uniquePaths(3, 7) << endl;
    cout << "3x3 = " << uniquePaths(3, 3) << endl;
    return 0;
}

// Сложность: O(m·n) по времени; O(m·n) памяти в классической версии, O(n) в оптимизированной.