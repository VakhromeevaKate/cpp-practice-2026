// 1. Линейный поиск: «Найди первое вхождение» (10 мин)
// Тема: линейный поиск, O(n).

// Условие: Напишите функцию, которая возвращает индекс первого вхождения элемента key в массиве. Если элемента нет — верните -1.

#include <iostream>
#include <vector>

using namespace std;

/*
Разминка: Линейный поиск: «Найди первое вхождение» (10 мин)
Тема: линейный поиск, O(n).

Условие: Напишите функцию, которая возвращает индекс первого вхождения элемента key
в массиве. Если элемента нет — верните -1.
*/

int linear_search(std::vector<int> my_arr, int key)  {
    for (int i = 0; i < my_arr.size(); i++) {
        if (my_arr[i] == key) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    std::vector<int> arr = {10, 20, 4, 45, 99, 99, 7, 1};
    std::vector<int> arr1 = {0, 0, 0, 0, 0, 0};
    std::vector<int> arr2 = {};
    std::vector<int> arr3 = {1};
    std::vector<int> arr4 = {-10, 20, 4, 45, -99, 99, 7, 1, 0};
    std::vector<int> arr5 = {10, 20, 4, 45, 99, 99, 7, 1, 0};
    int key = 40;
    int key1 = 0;
    int key4 = 0;
	// your code goes here
	
	std::cout << linear_search(arr, key) << std::endl;
	std::cout << linear_search(arr1, key1) << std::endl;
	std::cout << linear_search(arr2, key) << std::endl;
	std::cout << linear_search(arr3, key) << std::endl;
	std::cout << linear_search(arr4, key4) << std::endl;
	std::cout << linear_search(arr5, key4) << std::endl;
	
	
    return 0;
}

