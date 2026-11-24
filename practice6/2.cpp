/*
Задача 2. «Найди все баги»
Тема: утечки, двойное удаление, висячие указатели (слайд 20).
Условие: В функции ниже пять ошибок, связанных с памятью.
Найдите их и объясните, к чему они приведут.
*/

#include <iostream>
using namespace std;

void processData() {
    int* single = new int(42);       // (1)
    int* array = new int[10];        // (2)
    
    if (*single > 40) {
        return;                      // (3)
    }
    
    int* copy = single;              // (4)
    delete single;
    delete copy;                     // (5)
    
    delete[] array;                  // (6)
    
    int* dangling = array;           // (7)
    *dangling = 5;                   // (8)
}

int main() {
    return 0;
}