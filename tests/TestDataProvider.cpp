#include "TestDataProvider.h"

/**
 * (static) Метод возвращает очередной набор данных для теста функции get_sum()
 * @return TestData<int>
 */
std::vector<TestData<int>> DataProvider_GetSum::get_test_cases()
{
    std::vector<TestData<int>> test_cases;

    // Пример 1: Положительные значения
    test_cases.push_back({
                             "SimpleValues",                   // Имя теста
                             {1, 2, 3, 4},           // Вектор исходных данных
                             10,                            // Ожидаемый результат
                         });

    // Пример 2: Нулевые значения
    test_cases.push_back({
                             "ZeroValues",                      // Имя теста
                             {0, 0, 0, 0},            // Вектор исходных данных
                             0,                             // Ожидаемый результат
                         });

    // Пример 3: Отрицательные значения
    test_cases.push_back({
                                 "NegativeValues",              // Имя теста
                                 {-1, -2, -3, -4},    // Вектор исходных данных
                                 -10,                       // Ожидаемый результат
                         });

    // Пример 4: Смешанные значения
    test_cases.push_back({
                                 "MixedValues",                 // Имя теста
                                 {-1, 1, 2, -2},      // Вектор исходных данных
                                 0,                         // Ожидаемый результат
                         });

    // Пример 5: Отсутствующие значения (пустой вектор)
    test_cases.push_back({
                                 "NoValues",                    // Имя теста
                                 {},                                // Вектор исходных данных
                                 0,                         // Ожидаемый результат
                         });

    // Можно загружать данные из CSV-файла, JSON-файла, базы данных и т.д.
    // Например, загрузка из CSV файла:
    // load_data_from_csv("test_data.csv", test_cases);

    return test_cases;
}


/**
 * (static) Метод возвращает очередной набор данных для теста функции get_cube()
 * @return double
 */
double DataProvider_GetCube::get_test_cases()
{
    double test_cases;

    // Пример 1: Положительное значение
    test_cases.push_back({
                                 "PositiveValue",       // Имя теста
                                 4.0,                   // Исходные данные
                                 64.0,                  // Ожидаемый результат
                         });

    // Пример 2: Нулевое значение
    test_cases.push_back({
                                 "ZeroValue",           // Имя теста
                                 0.0,                   // Исходные данные
                                 0.0,                   // Ожидаемый результат
                         });

    // Пример 3: Отрицательное значение
    test_cases.push_back({
                                 "NegativeValue",       // Имя теста
                                 -2,                    // Исходные данные
                                 -8,                    // Ожидаемый результат
                         });

    // Можно загружать данные из CSV-файла, JSON-файла, базы данных и т.д.
    // Например, загрузка из CSV файла:
    // load_data_from_csv("test_data.csv", test_cases);

    return test_cases;
}
