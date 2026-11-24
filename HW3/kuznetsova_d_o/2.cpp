// Задача 2. «Ограбление домов»
// Тема: 1D ДП, оптимизация памяти.

//Условие: Вы — грабитель, планирующий ограбление домов на улице.
// В каждом доме i лежит nums[i] денег. 
//Единственное ограничение: нельзя грабить два соседних дома (сработает сигнализация). 
//Найдите максимальную сумму, которую можно украсть.


#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


// Классическая версия: O(n) памяти
int rob(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
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

    int prev2 = 0;        
    int prev1 = nums[0];  
    for (int i = 1; i < n; i++) {
        int current = max(prev1, nums[i] + prev2);

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
    assert(robOptimized({2, 1, 1, 2}) == 4);
    assert(robOptimized({10, 1, 1, 10}) == 20);

    // Проверка, что оптимизированная версия даёт тот же ответ
    for (int n = 0; n <= 8; n++) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back(i + 1);
        }
        assert(rob(nums) == robOptimized(nums));
    }
    cout << "accessed!" << endl;
}


int main() {
    runTests();
    cout << "[1, 2, 3, 1] = "
         << rob({1, 2, 3, 1}) << endl;

    cout << "[2, 7, 9, 3, 1] = "
         << rob({2, 7, 9, 3, 1}) << endl;

    return 0;
}



