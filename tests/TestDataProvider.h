#pragma once

#include <vector>
#include <string>

// Шаблонная структура одного набора тестовых данных для хранения в векторах
template <typename T> requires (std::is_arithmetic_v<T>)
struct TestDatasetWithVector
{
    std::string test_name;  // Имя конкретного набора данных (для читабельности ошибок)
    std::vector<T> args;    // Вектор аргументов для тестируемой функции
    T expected_result;      // Ожидаемый результат
};

// Шаблонная структура одного набора тестовых данных для хранения в векторах
template <typename T> requires (std::is_arithmetic_v<T>)
struct TestDatasetWithScalar
{
    std::string test_name;  // Имя конкретного набора данных (для читабельности ошибок)
    T arg;                  // Аргумент для тестируемой функции
    T expected_result;      // Ожидаемый результат
};

// Шаблонная структура одного набора тестовых данных для хранения в векторах
template <typename T> requires (std::is_arithmetic_v<T>)
struct TestDatasetBothVectors
{
    std::string test_name;              // Имя конкретного набора данных (для читабельности ошибок)
    std::vector<T> args;                // Вектор аргументов для тестируемой функции
    std::vector<T> expected_result;     // Вектор ожидаемых результатов
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


// Шаблонный класс Data Provider для функции multiply_by_two
template <typename T> requires (std::is_arithmetic_v<T>)
class DataProvider_MultiplyBy2
{
public:
    static std::vector<TestDatasetBothVectors<T>> get_test_cases()
    {
        return get_data();
    }

private:
    // Приватная шаблонная функция (дефолтная). Требуется ее специализация
    // для каждого поддерживаемого дата провайдером типа данных
    static std::vector<TestDatasetBothVectors<T>> get_data()
    {
        return {};
    }
};