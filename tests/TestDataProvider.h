#pragma once

#include <vector>
#include <string>

// Шаблонная структура для хранения одного набора тестовых данных
template <typename T>
struct TestData
{
    std::string test_name;  // Имя конкретного набора данных (для читабельности ошибок)
    std::vector<T> arg;     // Вектор аргументов для тестируемой функции
    T expected_result;      // Ожидаемый результат
};

// Класс Data Provider для функции get_sum
class DataProvider_GetSum
{
public:
    static std::vector<TestData<int>> get_test_cases();
private:
};

// Класс Data Provider для функции get_cube
class DataProvider_GetCube
{
public:
    static double get_test_cases();
private:
};
