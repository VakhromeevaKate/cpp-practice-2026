// Задача 3. «Распределение конфет» (25 мин)
// Тема: жадность с двумя проходами, классическая задача с LeetCode.

// Условие: Есть n детей в ряд, у каждого — оценка (rating[i]).
// Нужно раздать конфеты так, чтобы:
// Каждый ребёнок получил минимум одну конфету.
// Ребёнок с большей оценкой, чем сосед, получил больше конфет.
// Найдите минимальное суммарное число конфет.

// Входные данные:
// ratings = [1, 0, 2]
// Ответ: [2, 1, 2] → сумма 5.

// Идея: жадность в двух проходах.
// Левый проход: если rating[i] > rating[i-1], то candies[i] = candies[i-1] + 1.
// Правый проход: если rating[i] > rating[i+1], то candies[i] = max(candies[i], candies[i+1] + 1).

#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;

    vector<int> candies(n, 1); // каждый минимум 1

    // Левый проход: растущие последовательности
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Правый проход: убывающие последовательности
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int total = 0;
    for (int c : candies) total += c;
    return total;
}

int main() {
    vector<int> r1 = {1, 0, 2};
    cout << "ratings = [1, 0, 2] -> " << candy(r1) << endl; // 5

    vector<int> r2 = {1, 2, 2};
    cout << "ratings = [1, 2, 2] -> " << candy(r2) << endl; // 4

    vector<int> r3 = {1, 3, 2, 2, 1};
    cout << "ratings = [1, 3, 2, 2, 1] -> " << candy(r3) << endl;

    return 0;
}