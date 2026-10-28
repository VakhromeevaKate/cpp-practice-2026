#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
2. «Второй по величине» (15 мин)
Тема: массивы, циклы, доступ по индексу.

Условие: Дан массив целых чисел.
Найдите второй по величине элемент (без сортировки).

int arr[8] = {10, 20, 4, 45, 99, 99, 7, 1};

Ожидаемый ответ: 45 (99 — максимум, 45 — второй)
Подсказка: заведите две переменные — max и secondMax. Пройдитесь по массиву один раз.
*/

int find_second(vector<int> arr) {
    if (arr.size() < 2) {
        return -1;
    }
    
    int max = INT_MIN;
    int second_max = INT_MIN;

    
    
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }
    
    
    return second_max;
}

int main() {
	// your code goes here
    std::vector<int> arr = {10, 20, 4, 45, 99, 99, 7, 1};
    std::cout << find_second(arr) << std::endl;
    return 0;
}
