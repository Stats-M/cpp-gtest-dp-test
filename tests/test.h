#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "TestDataProvider.h"   // Поставщик данных
#include "../src/cube.h"        // Заголовочный файл с проверяемым кодом

#include <string>
#include <vector>

// Фиксируем тип шаблонной функции, которую тестируем
double get_sum(std::vector<int> args);

// Обычная функция, которую тестируем. Уже объявлена в cube.h
//double get_cube(double arg);

// Обычная функция, которую тестируем. Уже объявлена в cube.h
//double get_pow_2(double arg);



// Шаблонный тестовый класс для работы с шаблонным data provider
template <typename T>
class TestMultiplyBy2 : public ::testing::Test
{
public:
    // Обязательно public или использовать struct вместо class,
    // иначе тип не будет виден в макросе TYPED_TEST
    using ParamType = T;
};




/**
 * Шаблонная функция для проверки равенства двух векторов по значениям их элементов.
 * Векторы разной длины не равны друг другу.
 * Если требуется более сложное сравнение, используйте Google Mock
 * @tparam T тип данных вектора
 * @param expected ссылка на вектор с ожидаемыми данными
 * @param actual ссылка на сравниваемый вектор
 */
template <typename T>
void AssertVectorsAreEqual(const std::vector<T>& expected, const std::vector<T>& actual)
{
    // Если обе ссылки ведут на один и тот же вектор, векторы равны
    if (&expected == &actual)
    {
        return;
    }

    // Сначала проверяем размеры
    ASSERT_EQ(expected.size(), actual.size()) << "Vectors have different sizes";

    // Сравниваем поэлементно, т.к. при таком подходе можно будет узнать индекс различающихся элементов
    for (size_t i = 0; i < expected.size(); ++i)
    {
        ASSERT_EQ(expected[i], actual[i]) << "Elements at index " << i << " are different";
    }
}