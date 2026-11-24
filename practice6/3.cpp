/* Задача 3. Класс DynamicArray: RAII и правило трёх
 Тема: RAII, глубокая копия, правило трёх (слайды 23–25).
 Условие: Реализуйте класс DynamicArray, который владеет массивом в куче:
 - Конструктор DynamicArray(size_t size).
 - Деструктор (освобождает память).
 - Копирующий конструктор (глубокая копия).
 - Копирующее присваивание (глубокая копия).
 - Методы size() и operator[] (с проверкой границ).
 */

#include <iostream>
#include <cassert>
#include <algorithm>

class DynamicArray {
    private:
        int* data_;
        size_t size_;
    
    public:
        DynamicArray(size_t size) : data_(new int[size]()), size_(size) {}
        
        ~DynamicArray() { 
            delete[] data_; 
        }
        
        // Копирующий конструктор
        DynamicArray(const DynamicArray& other) 
            : data_(new int[other.size_]), size_(other.size_) {
            std::copy(other.data_, other.data_ + size_, data_);
        }
        
        // Копирующее присваивание (через copy-and-swap — идиоматично)
        DynamicArray& operator=(const DynamicArray& other) {
            if (this != &other) { // защита от самоприсваивания
                DynamicArray tmp(other);
                std::swap(data_, tmp.data_);
                std::swap(size_, tmp.size_);
            }
            return *this;
        }
        
        size_t size() const { return size_; }
        
        int& operator[](size_t i) { return data_[i]; }
        const int& operator[](size_t i) const { return data_[i]; }
    };

void runTests() {
    DynamicArray a(5);
    for (size_t i = 0; i < a.size(); ++i) a[i] = i * 10;
    
    DynamicArray b = a; // Копия
    b[0] = 999;
    
    assert(a[0] == 0);   // a не должен измениться!
    assert(b[0] == 999);
    
    DynamicArray c(2);
    c = a;               // Присваивание
    c[1] = 777;
    assert(a[1] == 10);
    assert(c[1] == 777);
    assert(c[4] == a[4]);
    
    std::cout << "Все тесты пройдены!\n";
}

int main() {
    runTests();
    return (0);
}