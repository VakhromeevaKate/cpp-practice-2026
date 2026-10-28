// Задача 2. «Заправки на маршруте» (20 мин)
// Тема: жадность с ограничением ресурса.

// Условие: Вы едете из города A в город B. Бак вмещает C литров. 
//  пути есть заправки на расстояниях d[0], d[1], ..., d[n-1] от старта. 
// В каждой заправке можно заправиться до полного бака.
// Изначально бак полон.
// Найдите минимальное число заправок, чтобы доехать. Если невозможно — верните -1.

// Входные данные:

// text
// C = 20 (литров)
// Расстояние до B = 100
// Заправки: [20, 40, 55, 70, 85]
// Расход: 1 литр на 1 км
// Жадная стратегия: всегда заправляемся на самой далёкой заправке, до которой можем доехать.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minRefuels(int distance, int capacity, vector<int>& stations) {
    // Добавляем финальную точку как «заправку» с 0 топлива
    stations.push_back(distance);
    sort(stations.begin(), stations.end());

    int refuels = 0;
    int currentPos = 0;
    int fuel = capacity;

    int i = 0;
    while (currentPos < distance) {
        // Ищем самую дальнюю заправку в пределах досягаемости
        int farthest = -1;
        while (i < (int)stations.size() && stations[i] <= currentPos + fuel) {
            farthest = stations[i];
            i++;
        }

        // Если финальная точка в зоне досягаемости — доехали
        if (farthest == distance) return refuels;

        // Не нашли ни одной заправки — застряли
        if (farthest == -1) return -1;

        // Двигаемся до дальней заправки и заправляемся
        fuel -= (farthest - currentPos);
        currentPos = farthest;
        fuel = capacity;
        refuels++;
    }
    return refuels;
}

int main() {
    int distance = 100;
    int capacity = 20;
    vector<int> stations = {20, 40, 55, 70, 85};

    int result = minRefuels(distance, capacity, stations);
    if (result == -1) cout << "Невозможно доехать" << endl;
    else cout << "Минимальное число заправок: " << result << endl;

    return 0;
}

// currentPos = 0, fuel = 20. Достижимые заправки: 20. Едем до 20. refuels = 1. fuel = 20.
// currentPos = 20, fuel = 20. Достижимые: 40. Едем до 40. refuels = 2. fuel = 20.
// currentPos = 40, fuel = 20. Достижимые: 55. Едем до 55. refuels = 3. fuel = 20.
// currentPos = 55, fuel = 20. Достижимые: 70, 75... 70. Едем до 70. refuels = 4. fuel = 20.
// currentPos = 70, fuel = 20. Достижимые: 85. Едем до 85. refuels = 5. fuel = 20.
// currentPos = 85, fuel = 20. Достижимые: 100 (финал). Возвращаем 5.