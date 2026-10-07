#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
long long maxProductOfTwo(const std::vector<int>& nums) {
    // Краевой случай, когда в массиве меньше 2 элементов
    if (nums.size() < 2) {
        std::cout << "Нужно минимум 2 элемента\n";
        return 0; 
    }
    if (nums.size() == 2) return static_cast<long long>(nums[0]) * nums[1]; // Краевой случай, когда в массиве 2 элемента
    int max1 = INT_MIN, max2 = INT_MIN; //самое маленько число с которым будут сравниваться числа в массиве для поиска двух наибольших чисел
    int min1 = INT_MAX, min2 = INT_MAX; //самое большое число с которым будут сравниваться числа в массиве для поиска двух наименьших чисел
    for (int num : nums) {
        // Обновление двух максимальных значений
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
        // Двух минимальных значений
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }
    // Сравгение произведения двух наибольших и двух наименьших
    long long prod1 = static_cast<long long>(max1) * max2;
    long long prod2 = static_cast<long long>(min1) * min2;

    return std::max(prod1, prod2);
}

int main() {
    std::vector<int> nums = {-10, -3, 5, 6, -2, 10};
    std::cout << "Максимальное произведение: " << maxProductOfTwo(nums) << std::endl;
    return 0;
}
