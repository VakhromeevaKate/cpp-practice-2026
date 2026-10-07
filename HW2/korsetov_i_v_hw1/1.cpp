#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int> arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};

    reverse_array(arr);

    return 0;
}