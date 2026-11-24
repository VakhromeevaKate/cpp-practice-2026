#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int find_second_min(vector<int> arr) {
    if (arr.size() < 2) {
        return -1;
    }
    
    int mn = INT_MAX;
    int mn2 = INT_MAX;
    
    for (int j = 0; j < arr.size(); j++) {
        if (arr[j] < mn) {
            mn2 = mn;
            mn = arr[j];
        } else if (arr[j] < mn2 && arr[j] != mn) {
            mn2 = arr[j];
        }
    }
    
    return mn2;
}

int main() {
    std::vector<int> arr = {10, 20, 45, 99, 99, 7};
    std::cout << find_second_min(arr) << "\n";
    return 0;
}