#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> reverse_order(vector<int> arr) {
    for (int i = arr.size() + 1; i-- > 0; ) {
        arr.insert(arr.begin() + i, arr[0]);
        arr.erase(arr.begin());
    }
    return arr;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    for (auto i : reverse_order(arr))
        cout << i << " ";
    return 0;
}