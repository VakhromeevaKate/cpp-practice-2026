# 📝 Домашнее задание 4

# Задача 1. Класс Vector2D
Тема: инкапсуляция, конструкторы, перегрузка операторов, const-корректность.

Условие. Реализуйте класс Vector2D — вектор на плоскости с приватными полями x_, y_ типа double.
Требуется:
- Конструктор Vector2D(double x = 0, double y = 0).
- Геттеры x(), y() (const).
- length() — длина вектора, const-метод.
- operator+ и operator- — покомпонентные сложение и вычитание, возвращают новый вектор.
- operator* — две перегрузки:
- Vector2D operator*(double k) const — умножение на скаляр.
- double operator*(const Vector2D& other) const — скалярное произведение.
- operator== и operator!=.
- operator- (унарный) — противоположный вектор.
- operator<< — вывод в формате (x, y).