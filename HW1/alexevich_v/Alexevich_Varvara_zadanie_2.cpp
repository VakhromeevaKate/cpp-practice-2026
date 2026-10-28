#include <bits/stdc++.h>
using namespace std;

	// your code goes here


int second_min(const vector<int>& arr) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (int x : arr) {
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x > min1 && x < min2) {
            min2 = x;
        }
    }

    return (min2 == INT_MAX) ? INT_MIN : min2;
}

int main() {
    vector<int> arr = {10, 20, 45, 99, 99, 7};

    cout << second_min(arr) << "\n";
     return 0;
}
