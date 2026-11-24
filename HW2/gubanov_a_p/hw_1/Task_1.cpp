#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


int main() {
	
	std::vector<int> arr = {1, 2, 3, 4, 5};
	
	int left = 0;
    int right = arr.size() - 1;
    
    while (left < right){
        swap(arr[left], arr[right]);
        
        left++;
        right--;
    }
    
    for (int i : arr) {
    cout << i << ' ';
    }
    
	return 0;
}