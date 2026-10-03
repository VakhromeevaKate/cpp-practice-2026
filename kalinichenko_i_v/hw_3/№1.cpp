//Задача 1. «Максимальное произведение двух чисел»
// Тема: жадный выбор без сортировки, работа с краевыми случаями.

// Условие: Дан массив целых чисел (могут быть отрицательные). Найдите максимальное произведение двух чисел.

// Примеры:
// [1, 2, 3]          -> 6
// [1, 2, 3, 4]       -> 12
// [-1, -2, -3, 1]    -> 6
// [-10, -10, 5, 2]   -> 100
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MultiPair (const vector<int>& arr) {
	int n = arr.size();
	if (n < 2) return 0;

	int max1 = INT_MIN, max2 = INT_MIN;
	int min1 = INT_MAX, min2 = INT_MAX;

		for (int i = 0; i < n; ++i) {
		if(arr[i] > max1) {
			max2 = max1;
			max1 = arr[i];
		} else if (arr[i] > max2) {
			max2 = arr[i];
		}
		if(arr[i] < min1) {
			min2 = min1;
			min1 = arr[i];
		} else if (arr[i] < min2) {
			min2 = arr[i];
		}
	}

	return max(max1 * max2, min1 * min2);
}
int main() {
    cout << MultiPair({1, 2, 3}) << endl;            // 6
    cout << MultiPair({1, 2, 3, 4}) << endl;         // 12
    cout << MultiPair({-1, -2, -3, 1}) << endl;      // 6
    cout << MultiPair({-10, -10, 5, 2}) << endl;     // 100
    return 0;
}


