#include <bits/stdc++.h>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {11, 12, 23, 44, 75};
    int siz = arr.size();

    for (int i = 0; i < siz / 2; i++) {
        int a = arr[i];
        arr[i] = arr[siz - 1 - i];
        arr[siz - 1 - i] = a;
    }

    for (int i = 0; i < siz; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
