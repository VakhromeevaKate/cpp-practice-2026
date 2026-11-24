#include <iostream>
#include <thread>

int counter = 0;

void increment() {
    for (int i = 0; i < 100000; ++i) ++counter;
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "counter = " << counter << "\n";  // ОЖИДАЕМ 200000
}

/**
 * Почему: ++counter — это три операции: загрузить → сложить → записать.
 * Два потока могут загрузить одно и то же значение, каждый прибавить 1,
 * оба записать — в итоге счётчик увеличился на 1 вместо 2.
 */
