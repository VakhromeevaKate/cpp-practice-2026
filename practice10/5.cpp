#include <iostream>
#include <future>

long long heavy(int n) {
    long long sum = 0;
    for (long long i = 0; i < n; ++i) sum += i;
    return sum;
}

int main() {
    auto f1 = std::async(std::launch::async, heavy, 100'000'000);
    auto f2 = std::async(std::launch::async, heavy, 100'000'000);
    auto f3 = std::async(std::launch::async, heavy, 100'000'000);

    long long result = f1.get() + f2.get() + f3.get();
    std::cout << result << "\n";
}