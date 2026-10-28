/*
Блок 5. Математика и случайные числа
Заголовки: <cmath>, <complex>, <random>
Для чего: Корни, степени, тригонометрия,
комплексные числа, генерация случайных чисел (без rand()).
*/

#include <iostream>
#include <cmath>
#include <complex>
#include <random>

int main() {
    // Математика
    std::cout << "sqrt(16): " << std::sqrt(16) << "\n";
    std::cout << "pow(2,10): " << std::pow(2, 10) << "\n";
    std::cout << "abs(-5.5): " << std::abs(-5.5) << "\n";
    std::cout << "floor(3.7): " << std::floor(3.7) << "\n";
    
    // Комплексные числа
    std::complex<double> c1(1, 2), c2(3, 4);
    std::cout << "Complex sum: " << c1 + c2 << "\n"; // (4,6)
    
    // Случайные числа (современный подход)
    std::random_device rd;              // энтропия от ОС
    std::mt19937 gen(rd());             // генератор
    std::uniform_int_distribution<int> dist(1, 100);
    std::cout << "Random int: " << dist(gen) << "\n";
    return 0;
}