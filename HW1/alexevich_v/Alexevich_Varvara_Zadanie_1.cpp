#include <bits/stdc++.h>
using namespace std;

	// your code goes here


void reverse_array(vector<int>& arr) {
    int left = 0;
    int right = (int)arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}


int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    reverse_array(arr1);
    cout << "Reverse: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n";
    return 0;
}
