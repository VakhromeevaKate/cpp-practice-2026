#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int>& arr) {
    for (int i = 0; i < arr.size() / 2; i++) {
        swap(arr[i], arr[arr.size() - 1 - i]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    reverse_array(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
