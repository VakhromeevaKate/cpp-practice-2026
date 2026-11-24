#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};

    reverse_array(arr);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i != arr.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}