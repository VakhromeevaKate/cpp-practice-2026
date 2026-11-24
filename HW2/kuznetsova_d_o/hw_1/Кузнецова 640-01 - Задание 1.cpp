#include <iostream>
#include <vector>

void reverse_array(std::vector<int>& arr) {
    int size = arr.size();
    for (int j = 0; j < size / 2; j++) {
        int temporary = arr[j];
        arr[j] = arr[size - 1 - j];
        arr[size - 1 - j] = temporary;
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