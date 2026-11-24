// Трухан П. задание 1

#include <iostream>
#include <vector>

using namespace std;


void reverse(std::vector<int>& arr){
    int i = 0;
    int j = arr.size()-1;
    
    while (i<j) {
        
        int swap = arr[i]; // присваивается меньшее значение по индексу в массиве
        arr[i] = arr[j]; // большее значение по индексу
        arr[j] = swap; // в правую часть меньшее значение
        i++; // итерация вправо
        j--; // итер. влево
        
    }
}


int main(){
    std::vector<int> arr = {1,2,3,4,5};
    reverse(arr);
    
    for (int n : arr) {
        std::cout << n << std::endl;
    }
    
    return 0;
}