//Задача 2 Ограбление домов

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }

    int prev2 = 0;
    int prev1 = 0;

    for (int i = 0; i < nums.size(); i++) {
        int take = prev2 + nums[i];
        int skip = prev1;

        if (take > skip) {
            prev2 = prev1;
            prev1 = take;
        } else {
            prev2 = prev1;
            prev1 = skip;
        }
    }

    return prev1;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 1};
    vector<int> arr2 = {2, 7, 9, 3, 1};
    vector<int> arr3 = {5};
    vector<int> arr4 = {2, 1};
    vector<int> arr5 = {};

    cout << rob(arr1) << endl;
    cout << rob(arr2) << endl;
    cout << rob(arr3) << endl;
    cout << rob(arr4) << endl;
    cout << rob(arr5) << endl;

    return 0;
}
