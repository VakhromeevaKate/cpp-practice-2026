// Реверс


#include <iostream>
#include <vector>

using namespace std;

void reverse_array(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1 - i] = temp;
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};

    reverse_array(arr);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}