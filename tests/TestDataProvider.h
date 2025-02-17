#pragma once

#include <vector>
#include <string>

// Шаблонная структура для хранения одного набора тестовых данных
template <typename T>
struct TestData
{
    std::string test_name;  // Имя конкретного набора данных (для читабельности ошибок)
    std::vector<T> args;    // Вектор аргументов для тестируемой функции
    T result;               // Ожидаемый результат
};

// Класс Data Provider'а
class MyDataProvider
{
public:
    static std::vector<TestData<int>> get_test_cases();
private:
};
