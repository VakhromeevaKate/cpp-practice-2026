#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int> nums) {
    int prev2 = 0; 
    int prev1 = 0; 

    for (int x : nums) {
        int cur = max(prev1, x + prev2);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

int main() {
    cout << rob({1, 2, 3, 1}) << endl;     
    cout << rob({2, 7, 9, 3, 1}) << endl;  
    cout << rob({5}) << endl;              
    cout << rob({2, 1}) << endl;           
    cout << rob({}) << endl;              
}