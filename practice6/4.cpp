/* Задача 4. Рефакторинг: new/delete -> std::unique_ptr
Тема: умные указатели, владение (слайд 26).
Условие: Перепишите класс TaskManager так, чтобы он использовал std::unique_ptr вместо сырого new/delete.
Убедитесь, что копирование запрещено, а перемещение работает. */

#include <memory>
#include <string>

struct Task { 
    std::string name; 
};

class OldTaskManager {
    Task* task_;
public:
    OldTaskManager() : task_(new Task{"default"}) {}
    ~OldTaskManager() { delete task_; }
    Task* get() const { return task_; }
};

class TaskManager {
    std::unique_ptr<Task> task_;
public:
    TaskManager() : task_(std::make_unique<Task>(Task{"default"})) {}
    TaskManager(std::string name) : task_(std::make_unique<Task>(Task{name})) {}
    // Деструктор не нужен — RAII сделает всё сам
    
    Task* get() const { return task_.get(); }
    
    // Копирование запрещено (по умолчанию для unique_ptr)
    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;
    
    // Перемещение разрешено
    TaskManager(TaskManager&&) = default;
    TaskManager& operator=(TaskManager&&) = default;
};