#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int find_second_min(vector<int> arr) {
    if (arr.size() < 2) {
        return -1;
    }

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    return min2;
}

int main() {
    std::vector<int> arr = {10, 20, 45, 99, 99, 7};
    std::cout << find_second_min(arr) << std::endl;
    return 0;
}