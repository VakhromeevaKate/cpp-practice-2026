/**
 Задача 2. Иерархия банковских счетов: модификаторы доступа и наследование (15 мин)
 Тема: protected vs private, виртуальные функции, переопределение поведения.

 Условие. Реализуйте:
 Базовый класс Account с protected-полями owner_, balance_. Методы deposit, withdraw, balance, owner, type.
 SavingsAccount — накопительный счёт с методом addInterest(), который обращается к balance_ напрямую.
 CreditAccount — кредитный счёт с лимитом. Переопределяет withdraw так, чтобы разрешать уход в минус до limit_.
 */

 #include <iostream>
 #include <string>
 #include <vector>
 #include <memory>
 #include <cassert>
 using namespace std;
 
 class Account {
 protected:
     string owner_;
     double balance_;
 
 public:
     Account(const string& owner, double balance)
         : owner_(owner), balance_(balance) {}
 
     virtual ~Account() = default;
 
     double balance() const { return balance_; }
     const string& owner() const { return owner_; }
 
     virtual void deposit(double amount) {
         if (amount > 0) balance_ += amount;
     }
 
     virtual bool withdraw(double amount) {
         if (amount > 0 && amount <= balance_) {
             balance_ -= amount;
             return true;
         }
         return false;
     }
 
     virtual string type() const { return "Account"; }
 };
 
 class SavingsAccount : public Account {
     double rate_;
 public:
     SavingsAccount(const string& owner, double balance, double rate)
         : Account(owner, balance), rate_(rate) {}
 
     void addInterest() {
         balance_ *= (1 + rate_);   // доступ к protected полю базового класса
     }
 
     string type() const override { return "Savings"; }
 };
 
 class CreditAccount : public Account {
     double limit_;
 public:
     CreditAccount(const string& owner, double balance, double limit)
         : Account(owner, balance), limit_(limit) {}
 
     bool withdraw(double amount) override {
         if (amount > 0 && balance_ - amount >= -limit_) {
             balance_ -= amount;
             return true;
         }
         return false;
     }
 
     string type() const override { return "Credit"; }
 };
 
 void runTests() {
     SavingsAccount s("Alice", 1000, 0.05);
     s.deposit(500);
     assert(s.balance() == 1500);
     s.addInterest();
     assert(s.balance() == 1575.0);
 
     CreditAccount c("Bob", 100, 500);
     assert(c.withdraw(400));    // уходит в минус до -300 (в пределах лимита)
     assert(c.balance() == -300);
     assert(!c.withdraw(300));   // -600 < -500, отказ
     assert(c.balance() == -300);
 
     // Полиморфизм через указатель на базовый класс
     vector<unique_ptr<Account>> accounts;
     accounts.push_back(make_unique<SavingsAccount>("A", 100, 0.1));
     accounts.push_back(make_unique<CreditAccount>("B", 100, 200));
 
     assert(accounts[0]->type() == "Savings");
     assert(accounts[1]->type() == "Credit");
 
     cout << "Задача 2: все тесты пройдены!\n";
 }
 
 int main() {
     runTests();
     return 0;
 }