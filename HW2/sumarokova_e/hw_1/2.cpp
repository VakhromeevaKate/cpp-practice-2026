#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int find_second_min(vector<int> arr) {
    if (arr.size() < 2) {
        return -1;
    }
    
    int min_val = INT_MAX;
    int second_min = INT_MAX;
    
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min_val) {
            second_min = min_val;
            min_val = arr[i];
        } else if (arr[i] < second_min && arr[i] != min_val) {
            second_min = arr[i];
        }
    }
    
    
    return second_min;
}

int main() {
    std::vector<int> arr = {10, 20, 45, 99, 99, 7};
    std::cout << find_second_min(arr) << std::endl;
    return 0;
}
