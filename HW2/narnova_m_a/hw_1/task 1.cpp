#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    

    int left = 0;
    int right = arr.size() - 1;
    
    while (left < right) {
        std::swap(arr[left], arr[right]);
        ++left;
        --right;
    }
    
    
    for (int x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    
    return 0;
}