#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Тимашёв Михаил, гр. 640-02

int HouseRobber(vector<int> arr) {
    int n = arr.size();
    if (n == 0) return 0;
    
    int current = arr[0];
    int best = arr[0];
    int prev_best = 0;
    
    for (int i = 1; i < n; i++) {
        current = max(best, arr[i] + prev_best);
        prev_best = max(best, prev_best);
        best = max(current, best);
    }
    
    return best;
}

void runTests() {
    assert(HouseRobber({1, 2, 3, 1}) == 4);
    assert(HouseRobber({2, 7, 9, 3, 1}) == 12);
    assert(HouseRobber({5}) == 5);
    assert(HouseRobber({2, 1}) == 2);
    assert(HouseRobber({}) == 0);
    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();
	vector<int> houses = {3, 7, 2, 9, 11, 4, 5};
	cout << "(3, 7, 2, 9, 11, 4, 5): " << HouseRobber(houses) << endl;
	return 0;

}
