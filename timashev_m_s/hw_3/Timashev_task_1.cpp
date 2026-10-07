#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Тимашёв Михаил, гр. 640-02

int greedy_product(vector<int> arr) {
    if (arr.size() < 2) {
        return -1;
    }
    
    int int_a = INT_MIN;
    int int_b = INT_MIN;
    
    // Выбираем первый множитель (число с максимальным абсолютным значением)
    for (int i = 0; i < arr.size(); i++) {
        if (abs(arr[i]) > abs(int_a)) {
            int_a = arr[i];
        }
    }
    arr.erase(find(arr.begin(), arr.end(), int_a));
    
    if (int_a == 0) {
        return 0;
    }
    
    // Если первый множитель отрицателен: выбираем наименьшее число
    if (int_a < 0) {
        int_b = INT_MAX;
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] < int_b) {
                int_b = arr[i];
            }
        }
    }
    
    // Если первый множитель положителен: выбираем наибольшее число
    if (int_a > 0) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > int_b) {
                int_b = arr[i];
            }
        }
    }
    
    
    return (int_a * int_b);
}

int main() {
	std::vector<int> arr_1 = {1, 2, 3};
	std::vector<int> arr_2 = {1, 2, 3, 4};
	std::vector<int> arr_3 = {-1, -2, -3, 1};
	std::vector<int> arr_4 = {-10, -10, 5, 2};
	
	cout << "(1, 2, 3): " << greedy_product(arr_1) << endl;
	cout << "(1, 2, 3, 4): " << greedy_product(arr_2) << endl;
	cout << "(-1, -2, -3, 1): " << greedy_product(arr_3) << endl;
	cout << "(-10, -10, 5, 2): " << greedy_product(arr_4) << endl;
	
	return 0;

}
