#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int rob(const vector<int>& nums) {
    // prev2 = DP[i-2]
    // prev1 = DP[i-1]
    int prev2 = 0;
    int prev1 = 0;
    for (int money : nums) {
        int current = max(
            prev1,          // не грабим текущий дом
            prev2 + money   // грабим текущий дом
        );
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
int main() {
    cout << rob({2, 7, 9, 3, 1}) << '\n'; 
    return 0;
}
