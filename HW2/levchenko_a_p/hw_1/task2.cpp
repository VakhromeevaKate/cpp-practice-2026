#include <iostream>
#include <vector>
int main() {
    std::vector<int> arr = {10, 20, 45, 99, 99, 7};
    int min1 = arr[0];
    int min2 = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }
    std::cout << min2;
    return 0;
}