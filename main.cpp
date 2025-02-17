#include <gtest/gtest.h>
#include <iostream>

#include "tests/test.h"




// Класс, который генерирует тестовые данные (DataProvider)
class MyDataProvider
{
public:
    static std::vector<TestData<int>> get_test_cases()
    {
        std::vector<TestData<int>> test_cases;

        // Пример 1: Простой случай
        test_cases.push_back({
                                     "SimpleMatrix",            // Имя теста
                                     {1, 2, 3, 4},    // Вектор исходных данных
                                     10,                           // Ожидаемый результат
                             });

        // Пример 2: Другой случай
        test_cases.push_back({
                                     "ZeroMatrix",                // Имя теста
                                     {0, 0, 0, 0},      // Матрица
                                     0,                              // Ожидаемый результат
                             });

        // Пример 3: Более сложный случай
        test_cases.push_back({
                                     "NegativeMatrix",            // Имя теста
                                     {-1, 1, 2, -2},    // Матрица
                                     -3,                             // Ожидаемый результат
                             });

        // Можно загружать данные из CSV-файла, JSON-файла, базы данных и т.д.
        // Например, загрузка из CSV файла:
        // load_data_from_csv("test_data.csv", test_cases);

        return test_cases;
    }

private:
    // Пример загрузки данных из файла CSV (нужна дополнительная реализация)
    // void load_data_from_csv(const std::string& filename, std::vector<TestData>& test_cases) { ... }
};

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    //return 0;
}
