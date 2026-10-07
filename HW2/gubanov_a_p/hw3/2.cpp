#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int houseRobbery(const vector<int>& arr){
    int n = arr.size();
    int prev_h = 0;
    int curr_h = 0;

    for (int i = 0; i < n; i++){
        int curr_h2 = curr_h;

        curr_h = max(prev_h + arr[i], curr_h);

        prev_h = curr_h2;
    }
    return curr_h;
}

void runTests() {
    assert(houseRobbery({1, 2, 3, 1}) == 4);
    assert(houseRobbery({2, 7, 9, 3, 1}) == 12);
    assert(houseRobbery({5}) == 5);
    assert(houseRobbery({2, 1}) == 2);
    assert(houseRobbery({}) == 0);

    cout << "Tests Completed" << endl;
}

int main() {
    runTests();

    vector<int> demo = {2, 5, 6, 3, 9, 4};
    cout << houseRobbery(demo) << endl;
    return 0;
}