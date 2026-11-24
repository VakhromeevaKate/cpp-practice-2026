#include <iostream>
#include <thread>
#include <mutex>

int counter_bad = 0;       // версия без защиты
int counter_good = 0;      // версия с mutex
std::mutex mtx;

// Без защиты — race condition
void increment_bad() {
    for (int i = 0; i < 1'000'000; ++i) {
        ++counter_bad;
    }
}

// С защитой - все ок
void increment_good() {
    for (int i = 0; i < 1'000'000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);   // RAII-блокировка
        ++counter_good;
    }
}

int main() {
    // Версия 1: без защиты
    std::thread t1(increment_bad);
    std::thread t2(increment_bad);
    t1.join();   // здесь потоки СЛИВАЮТСЯ с main
    t2.join();
    std::cout << "Без mutex: " << counter_bad
              << " (ожидалось 2'000'000)\n";

    // Версия 2: с mutex
    std::thread t3(increment_good);
    std::thread t4(increment_good);
    t3.join();
    t4.join();
    std::cout << "С mutex:   " << counter_good
              << " (ожидалось 2'000'000)\n";

    return 0;
}