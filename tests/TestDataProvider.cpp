#include "TestDataProvider.h"

/**
 * (static) Метод возвращает очередной набор данных
 * @return TestData<int>
 */
std::vector<TestData<int>> MyDataProvider::get_test_cases()
{
    std::vector<TestData<int>> test_cases;

    // Пример 1: Простой случай
    test_cases.push_back({
                             "SimpleMatrix",            // Имя теста
                             {1, 2, 3, 4},    // Вектор исходных данных
                             10,                           // Ожидаемый результат
                         });

    // Пример 2: Нулевые аргументы
    test_cases.push_back({
                             "ZeroMatrix",                // Имя теста
                             {0, 0, 0, 0},      // Матрица
                             0,                              // Ожидаемый результат
                         });

    // Пример 3: Отрицательные аргументы
    test_cases.push_back({
                             "NegativeMatrix",            // Имя теста
                             {-1, 1, 2, -2},    // Матрица
                             0,                              // Ожидаемый результат
                         });

    // Можно загружать данные из CSV-файла, JSON-файла, базы данных и т.д.
    // Например, загрузка из CSV файла:
    // load_data_from_csv("test_data.csv", test_cases);

    return test_cases;
}
