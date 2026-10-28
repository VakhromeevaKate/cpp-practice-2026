#include <iostream>
#include <vector>

void reverse_array(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; i++) {
        int a = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = a;
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    reverse_array(arr);
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}