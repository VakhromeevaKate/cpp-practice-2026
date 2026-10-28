#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

//Напишите программу, которая выводит массив в обратном порядке. Используйте один цикл и обмен элементов местами (без создания второго массива). 

// std::vector<int> arr = {1, 2, 3, 4, 5};

// Вывод: 5 4 3 2 1

void reverse_list(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left ++;
        right --;
     
        
    }
    
}
int main () {
    vector<int>arr{1, 2, 3, 4, 5};
    
    reverse_list(arr);
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    return 0;
}


