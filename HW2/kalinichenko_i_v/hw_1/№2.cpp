#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <iostream>

//Задача 2. «Второй минимум
//Модифицируйте задачу из аудитории так, чтобы она находила второй по величине минимум:
// std::vector<int> arr = {10, 20, 45, 99, 99, 7}; Ожидаемый ответ: 10

int second_min(vector <int> arr) {
    if (arr.size() < 2) return -1;
    
    int min = INT_MAX;
    int second_min = INT_MAX;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min) {
            second_min = min;
            min = arr[i];
        } else if (arr[i] < second_min & arr[i] != min) {
            second_min = arr[i];
        }
    }
    return second_min;
}


int main() {
    vector<int> arr = {10, 20, 45, 99, 99, 7}; 
	cout << second_min(arr) << endl;
	return 0;

}
