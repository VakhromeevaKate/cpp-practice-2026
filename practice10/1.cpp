#include <iostream>
#include <thread>

void hello(int id) {
    std::cout << "Hello from thread " << id << "\n";
}

int main() {
    std::thread t1(hello, 1);
    std::thread t2(hello, 2);

    t1.join();  // дождаться завершения
    t2.join();
    // без join() программа упадёт: std::terminate при выходе из main
}