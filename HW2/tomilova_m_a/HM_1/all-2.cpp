#include <iostream>
#include <vector>
#include <climits>

int findSecondMin(const std::vector<int>& arr) {
    int min1 = INT_MAX; 
    int min2 = INT_MAX; 

    for (int x : arr) {
        if (x < min1) {
            min2 = min1;  
            min1 = x;   
        } else if (x < min2 && x != min1) {
            min2 = x;     
        }
    }

    return min2;
}

int main() {
    std::vector<int> arr = {10, 20, 45, 99, 99, 7};

    int result = findSecondMin(arr);
    std::cout << result << std::endl;

    return 0;
}
