#pragma once

#include <vector>
#include <string>

// Шаблонная структура для хранения одного набора тестовых данных в виде вектора
template <typename T>
struct TestDatasetWithVector
{
    std::string test_name;  // Имя конкретного набора данных (для читабельности ошибок)
    std::vector<T> args;    // Вектор аргументов для тестируемой функции
    T expected_result;      // Ожидаемый результат
};

// Шаблонная структура для хранения одного набора тестовых данных
template <typename T>
struct TestDatasetWithScalar
{
    std::string test_name;  // Имя конкретного набора данных (для читабельности ошибок)
    T arg;                  // Аргумент для тестируемой функции
    T expected_result;      // Ожидаемый результат
};

// Класс Data Provider для функции get_sum
class DataProvider_GetSum
{
public:
    static std::vector<TestDatasetWithVector<int>> get_test_cases();
private:
};

// Класс Data Provider для функции get_cube
class DataProvider_GetCube
{
public:
    static std::vector<TestDatasetWithScalar<double>> get_test_cases();
private:
};

// Класс Data Provider для функции get_pow_2
class DataProvider_GetPow2
{
public:
    static std::vector<TestDatasetWithScalar<double>> get_test_cases();
private:
};
