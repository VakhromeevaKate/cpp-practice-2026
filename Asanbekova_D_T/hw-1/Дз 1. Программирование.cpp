
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// реверс
void reverse_array(std::vector<int> my_arr) {
    int n = my_arr.size();
    
    for (int i = 0; i < n / 2; i++) {
        std::swap(my_arr[i], my_arr[n - 1 - i]);
    }


    for (int i = 0; i < n; i++) {
        std::cout << my_arr[i] << " ";
    }
    std::cout << std::endl;
}

// второй минимум 
int second_min(std::vector<int> my_arr) {
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

// массивы
int main() {

    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {10, 20, 45, 99, 99, 7};
    std::vector<int> arr3 = {5, 5, 5};
    std::vector<int> arr4 = {7};
    std::vector<int> arr5 = {};

    // Номер 1
    std::cout << " № 1:" << std::endl;
    reverse_array(arr1); 
    reverse_array(arr2); 
    reverse_array(arr3); 
    reverse_array(arr4); 
    reverse_array(arr5); 

    // Номер 2
    std::cout << "\n№ 2" << std::endl;
    std::cout << second_min(arr1) << std::endl; 
    std::cout << second_min(arr2) << std::endl; 
    std::cout << second_min(arr3) << std::endl; 
    std::cout << second_min(arr4) << std::endl; 
    std::cout << second_min(arr5) << std::endl;

    return 0;
}