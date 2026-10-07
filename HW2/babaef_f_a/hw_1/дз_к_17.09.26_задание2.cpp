#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//int arr[8] = {10, 20, 45, 99, 99, 7};

int second_min(vector<int> arr) {
    if (arr.size() < 2) {
        return -1;
    }
    int min = INT_MAX;
    int second_min = INT_MAX;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min) {
            second_min = min;
            min = arr[i];
        } 
        else if (arr[i] > min && arr[i] < second_min) {
            second_min = arr[i];
        }
    }
    return second_min;
}

int main() {
    std::vector<int> arr = {10, 20, 45, 99, 99, 7};
    std::cout << second_min(arr) << std::endl;
    return 0;
}
