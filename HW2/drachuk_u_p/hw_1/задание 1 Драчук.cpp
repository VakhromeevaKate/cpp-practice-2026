#include <bits/stdc++.h>
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
    vector<int> arr = {1, 2, 3, 4, 5};

    reverse_array(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
