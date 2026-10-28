#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// задание 1 
void reverse_array(vector<int> my_arr) {
    int n = my_arr.size();

    for (int i = 0; i < n / 2; i++) {
        swap(my_arr[i], my_arr[n - 1 - i]);
    }

    for (int i = 0; i < n; i++) {
        cout << my_arr[i] << " ";
    }
    cout << endl;
}

// задание 2 
int second_min(vector<int> my_arr) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < my_arr.size(); i++) {
        if (my_arr[i] < first) {
            second = first;
            first = my_arr[i];
        } else if (my_arr[i] > first && my_arr[i] < second) {
            second = my_arr[i];
        }
    }

    if (second == INT_MAX) {
        return -1;
    }
    return second;
}

int main() {
    // массивы
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {10, 20, 45, 99, 99, 7};
    vector<int> arr3 = {5, 5, 5};
    vector<int> arr4 = {7};
    vector<int> arr5 = {};

    // 1
    cout << "задание 1:" << endl;
    reverse_array(arr1); 
    reverse_array(arr2); 
    reverse_array(arr3); 
    reverse_array(arr4); 
    reverse_array(arr5); 

    // 2
    cout << "\nЗадание 2:" << endl;
    cout << second_min(arr1) << endl; 
    cout << second_min(arr2) << endl; 
    cout << second_min(arr3) << endl; 
    cout << second_min(arr4) << endl;
    cout << second_min(arr5) << endl; 

    return 0;
}