#pragma once

#include <string>
#include <vector>

// Шаблонная структура для хранения одного набора тестовых данных
template <typename T>
struct TestData
{
    std::string test_name;  // Имя конкретного набора данных (для читабельности ошибок)
    std::vector<T> args;    // Вектор аргументов для тестируемой функции
    T result;               // Ожидаемый результат
};
