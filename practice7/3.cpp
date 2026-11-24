/*
Блок 3. Контейнеры
Заголовки: <vector>, <array>, <map>, <unordered_map>,
<set>, <stack>, <queue>
Для чего: Хранение данных.
vector — массивы,
map — словари,
set — уникальные значения,
stack/queue — очереди.
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

int main() {
    // Vector — динамический массив
    std::vector<int> v = {3, 1, 4};
    v.push_back(5);
    std::cout << "Vector size: " << v.size() << "\n";
    
    // Map — отсортированный словарь (красно-черное дерево)
    std::map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    for (const auto& [name, age] : ages) {
        std::cout << name << ": " << age << "\n";
    }
    
    // Unordered_map — хеш-таблица (быстрее, но без порядка)
    std::unordered_map<std::string, int> uages = {{"Charlie", 35}};
    std::cout << "Charlie: " << uages["Charlie"] << "\n";
    
    // Set — уникальные элементы (дубликаты отбрасываются)
    std::set<int> s = {3, 1, 4, 1, 5};
    std::cout << "Set size: " << s.size() << "\n"; // 4
    
    // Stack (LIFO) и Queue (FIFO)
    std::stack<int> st; st.push(1); st.push(2);
    std::cout << "Stack top: " << st.top() << "\n"; // 2
    
    std::queue<int> q; q.push(10); q.push(20);
    std::cout << "Queue front: " << q.front() << "\n"; // 10
    return 0;
}
