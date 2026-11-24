#include <iostream>
#include <vector>
int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    for (int i = 0; i < arr.size() / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1 - i] = temp;
    }
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}