#include <gtest/gtest.h>
#include "test.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример теста для функции, принимающей vector<int> в качестве аргумента:
// связка class (фиксация типа) + TEST_P + INSTANTIATE_TEST_SUITE_P
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Параметризованный тестовый класс. Наследуется от ::testing::TestWithParam<TestDatasetWithVector>.
// TestDatasetWithVector указывает, какой тип данных будет параметром для теста.
class VectorCalculationTest : public ::testing::TestWithParam<TestDatasetWithVector<int>> {
};

// (Макрос) Определяет параметризованный тест VectorIntSum в пакете тестов класса VectorCalculationTest.
TEST_P(VectorCalculationTest, VectorIntSum) {
    // GetParam() возвращает текущий экземпляр TestDatasetWithVector от DataProvider для данного теста
    const TestDatasetWithVector<int>& data = GetParam();
    int result = get_sum<int>(data.args);
    ASSERT_NEAR(result, data.expected_result, 1e-6) << "Test Case: " << data.test_name; // Добавляем имя для отладки
}

// Генерируем тестовые случаи
// Макрос, который "инстанцирует" параметризованный тест.
//   * Первый аргумент - префикс для имен тестов.
//   * Второй аргумент - имя тестового класса.
//   * Третий аргумент - набор данных, который будет использоваться для параметризации
//     (в нашем случае, результат DataProvider_GetSum::get_test_cases()).
//   * Четвертый аргумент (опционально) - функция, которая формирует имя теста на основе параметра.
INSTANTIATE_TEST_SUITE_P(
        TestingFile_CubeCpp,                    // Префикс для имен тестов
    VectorCalculationTest,                      // Имя тестового класса
    ::testing::ValuesIn(DataProvider_GetSum::get_test_cases()),  // Набор данных
    [](const ::testing::TestParamInfo<TestDatasetWithVector<int>>& info)
        {
            // Формируем имя для каждого набора данных теста (опционально, для лучшей читаемости)
            return info.param.test_name;    // Используем имя из структуры TestDatasetWithVector
        }
                        );


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример теста для функции, принимающей скаляр double в качестве аргумента:
// связка class (фиксация типа) + TEST_P + INSTANTIATE_TEST_SUITE_P
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Параметризованный тестовый класс. Наследуется от ::testing::TestWithParam<TestDatasetWithScalar>.
// TestDatasetWithScalar указывает, какой тип данных будет параметром для теста.
class ScalarCalculationTest : public ::testing::TestWithParam<TestDatasetWithScalar<double>> {
};

// (Макрос) Определяет параметризованный тест ScalarCube в пакете тестов класса ScalarCalculationTest.
TEST_P(ScalarCalculationTest, ScalarCube) {
    // GetParam() возвращает текущий экземпляр TestDatasetWithScalar от DataProvider для данного теста
    const TestDatasetWithScalar<double>& data = GetParam();
    double result = get_cube(data.arg);
    ASSERT_NEAR(result, data.expected_result, 1e-6) << "Test Case: " << data.test_name; // Добавляем имя для отладки
}

// Генерируем тестовые случаи
// Макрос, который "инстанцирует" параметризованный тест.
//   * Первый аргумент - префикс для имен тестов.
//   * Второй аргумент - имя тестового класса.
//   * Третий аргумент - набор данных, который будет использоваться для параметризации
//     (в нашем случае, результат DataProvider_GetCube::get_test_cases()).
//   * Четвертый аргумент (опционально) - функция, которая формирует имя теста на основе параметра.
INSTANTIATE_TEST_SUITE_P(
        TestingFile_CubeCpp,                    // Префикс для имен тестов
        ScalarCalculationTest,                  // Имя тестового класса
        ::testing::ValuesIn(DataProvider_GetCube::get_test_cases()),  // Набор данных
        [](const ::testing::TestParamInfo<TestDatasetWithScalar<double>>& info)
            {
                // Формируем имя теста (опционально, для лучшей читаемости)
                return info.param.test_name;    // Используем имя из структуры TestDatasetWithScalar
            }
                        );



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример простых stand-alone тестов без использования DataProvider
// Классические unit-тесты с генерацией тестовых кейсов на лету
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Stand-alone тесты проверки базовой функциональности. Не связаны с DataProvider
// Эти тесты запустятся первыми, до параметризованных тестов
TEST(StandAloneTestsSuite, BasicTest_01) {
    std::vector<int> v1 {10, 20, 30, 5 };
    ASSERT_NEAR(get_sum<int>(v1), 65, 1e-6);
}
TEST(StandAloneTestsSuite, BasicTest_02) {
    std::vector<int> v1 {-10, -20, -30};
    ASSERT_NEAR(get_sum<int>(v1), -60, 1e-6);
}
TEST(StandAloneTestsSuite, BasicTest_03) {
    double arg {5};
    ASSERT_NEAR(get_cube(arg), 125, 1e-6);
}
TEST(StandAloneTestsSuite, BasicTest_04) {
    double arg {0};
    ASSERT_NEAR(get_cube(arg), 0, 1e-6);
}
