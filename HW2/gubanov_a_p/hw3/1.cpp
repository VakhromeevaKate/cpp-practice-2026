#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int maxMult(const vector<int>& arr) {
    int n = arr.size();

    int max1, max2, min1, min2;

    if (arr[1] > arr[0]){
        max1 = arr[1];
        max2 = arr[0];
    } else {
        max1 = arr[0];
        max2 = arr[1];
    }
    for (int i=2; i < n; i++){
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }

    if (arr[1] < arr[0]){
        min1 = arr[1];
        min2 = arr[0];
    } else {
        min1 = arr[0];
        min2 = arr[1];
    }
    for (int i=2; i < n; i++){
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    int rez1 = max1 * max2;
    int rez2 = min1 * min2;

    if (rez1 > rez2){
        return rez1;
    } else {
        return rez2;
    }
}

void runTests() {
    assert(maxMult({1, 2, 3}) == 6);
    assert(maxMult({1, 2, 3, 4}) == 12);
    assert(maxMult({-1, -2, -3, 1}) == 6);
    assert(maxMult({-10, -10, 5, 2}) == 100);

    cout << "Tests Completed" << endl;
}

int main(){
    runTests();

    vector<int> demo = {2, 5, -6, 3, 9, -4};
    cout << maxMult(demo) << endl;
    return 0;
}