// Задача 1 Максимальное произведение двух чисел

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_product(vector<int> arr) {
    if (arr.size() < 2) {
        return 0;
    }

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }

        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }

    int prod_max = max1 * max2;
    int prod_min = min1 * min2;

    if (prod_max > prod_min) {
        return prod_max;
    }
    return prod_min;
}

int main() {
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> arr3 = {-1, -2, -3, 1};
    vector<int> arr4 = {-10, -10, 5, 2};

    cout << max_product(arr1) << endl;
    cout << max_product(arr2) << endl;
    cout << max_product(arr3) << endl;
    cout << max_product(arr4) << endl;

    return 0;
}
