#pragma once

#include <vector>

/**
 * Пример шаблонной функции, которую требуется протестировать
 * @tparam T Тип параметра функции
 * @param args Вектор значений типа T
 * @return Сумма значений вектора
 */
template <typename T>
T get_sum(std::vector<T> args)
{
    T sum = static_cast<T>(0);
    for (T el : args)
    {
        sum += el;
    }
    return sum;
}

/**
 * Пример обычной нешаблонной функции, которую требуется протестировать
 * @param arg
 * @return Кубическая степень параметра arg
 */
double get_cube(double arg = 0.0);

/**
 * Пример обычной нешаблонной функции, которую требуется протестировать
 * @param arg
 * @return Квадрат параметра arg
 */
double get_pow_2(double arg = 0.0);
