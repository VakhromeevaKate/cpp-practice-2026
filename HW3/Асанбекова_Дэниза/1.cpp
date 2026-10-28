#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    std::vector<long long> nums;
    long long x;
    while (std::cin >> x) {
        nums.push_back(x);
    }
    
    // Проверка
    if (nums.size() < 2) {
        return 0;
    }

    // Инициализируем два максимума и два минимума
    long long max1 = LLONG_MIN, max2 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    for (long long num : nums) {
        // Максимумы
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
        
        // Минимумы
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    // Макс произведение 
    long long prod1 = max1 * max2; 
    long long prod2 = min1 * min2; 
    
    std::cout << std::max(prod1, prod2) << std::endl;
    return 0;
}
