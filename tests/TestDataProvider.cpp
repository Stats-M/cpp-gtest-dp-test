#include "TestDataProvider.h"

/**
 * (static) Метод возвращает очередной набор данных для теста функции get_sum()
 * @return TestDatasetWithVector<int>
 */
std::vector<TestDatasetWithVector<int>> DataProvider_GetSum::get_test_cases()
{
    std::vector<TestDatasetWithVector<int>> test_cases;

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
std::vector<TestDatasetWithScalar<double>> DataProvider_GetCube::get_test_cases()
{
    std::vector<TestDatasetWithScalar<double>> test_cases;

    // Пример 1: Положительное целое значение
    test_cases.push_back({
                                 "PositiveValue",       // Имя теста
                                 4.0,                        // Исходные данные
                                 64.0,              // Ожидаемый результат
                         });

    // Пример 2: Отрицательное целое значение
    test_cases.push_back({
                                 "NegativeValue",       // Имя теста
                                 -2,                         // Исходные данные
                                 -8,                // Ожидаемый результат
                         });

    // Пример 3: Нулевое значение
    test_cases.push_back({
                                 "ZeroValue",           // Имя теста
                                 0.0,                        // Исходные данные
                                 0.0,               // Ожидаемый результат
                         });

    // Пример 4: Положительное дробное значение
    test_cases.push_back({
                                 "PositiveFractionalValue",    // Имя теста
                                 0.5,                               // Исходные данные
                                 0.125,                    // Ожидаемый результат
                         });

    // Пример 5: Отрицательное дробное значение
    test_cases.push_back({
                                 "NegativeFractionalValue",    // Имя теста
                                 -0.25,                             // Исходные данные
                                 -0.015625,                 // Ожидаемый результат
                         });

    // Пример 6: Большое значение
    test_cases.push_back({
                                 "LargeValue",          // Имя теста
                                 100.0,                      // Исходные данные
                                 1000000.0,         // Ожидаемый результат
                         });

    // Можно загружать данные из CSV-файла, JSON-файла, базы данных и т.д.
    // Например, загрузка из CSV файла:
    // load_data_from_csv("test_data.csv", test_cases);

    return test_cases;
}


/**
 * (static) Метод возвращает очередной набор данных для теста функции get_pow_2()
 * @return double
 */
std::vector<TestDatasetWithScalar<double>> DataProvider_GetPow2::get_test_cases()
{
    std::vector<TestDatasetWithScalar<double>> test_cases;

    // Пример 1: Положительное целое значение
    test_cases.push_back({
                                 "PositiveValue",       // Имя теста
                                 4.0,                        // Исходные данные
                                 16.0,              // Ожидаемый результат
                         });

    // Пример 2: Отрицательное целое значение
    test_cases.push_back({
                                 "NegativeValue",       // Имя теста
                                 -2,                         // Исходные данные
                                 4,                 // Ожидаемый результат
                         });

    // Пример 3: Нулевое значение
    test_cases.push_back({
                                 "ZeroValue",           // Имя теста
                                 0.0,                        // Исходные данные
                                 0.0,               // Ожидаемый результат
                         });

    // Пример 4: Положительное дробное значение
    test_cases.push_back({
                                 "PositiveFractionalValue",    // Имя теста
                                 0.5,                               // Исходные данные
                                 0.25,                     // Ожидаемый результат
                         });

    // Пример 5: Отрицательное дробное значение
    test_cases.push_back({
                                 "NegativeFractionalValue",    // Имя теста
                                 -0.25,                             // Исходные данные
// ПРИМЕР РАБОТЫ ТЕСТОВ ПРИ НАЛИЧИИ ОШИБКИ:
//                                 0.0625,                    // Ожидаемый результат
                                 555,                    // Ожидаемый результат
                         });

    // Пример 6: Большое значение
    test_cases.push_back({
                                 "LargeValue",             // Имя теста
                                 100.0,                         // Исходные данные
                                 10000.0,              // Ожидаемый результат
                         });

    // Можно загружать данные из CSV-файла, JSON-файла, базы данных и т.д.
    // Например, загрузка из CSV файла:
    // load_data_from_csv("test_data.csv", test_cases);

    return test_cases;
}

/**
 * Специализация DataProvider_MultiplyBy2 для типа int
 * @return
 */
template <>
std::vector<TestDatasetBothVectors<int>> DataProvider_MultiplyBy2<int>::get_data()
{
    return {
        {"Positive Integers", {1, 2, 3}, {2, 4, 6}},
        {"Negative Integers", {-1, -2, -3}, {-2, -4, -6}},
        {"Mixed Integers", {1, -2, 3}, {2, -4, 6}},
        {"All zeroes", {0, 0, 0}, {0, 0, 0}},
    };
}

/**
 * Специализация DataProvider_MultiplyBy2 для типа double
 * @return
 */
template <>
std::vector<TestDatasetBothVectors<double>> DataProvider_MultiplyBy2<double>::get_data() {
    return {
        {"Positive Doubles", {1.5, 2.5, 3.5}, {3.0, 5.0, 7.0}},
        {"Negative Doubles", {-1.5, -2.5, -3.5}, {-3.0, -5.0, -7.0}},
        // ПРИМЕР РАБОТЫ ТЕСТОВ ПРИ НАЛИЧИИ ОШИБКИ:
        //{"Mixed Doubles", {1.5, -2.5, 3.5}, {3.0, -5.0, 7.0}},
        {"Mixed Doubles", {1.5, -2.5, 3.5}, {3.0, -5.0, 8.0}},
        {"All zeroes", {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}},
    };
}

