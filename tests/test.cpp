#include <gtest/gtest.h>
#include "test.h"

// Параметризованный тестовый класс. Наследуется от ::testing::TestWithParam<TestData>.
// TestData указывает, какой тип данных будет параметром для теста.
class CalculationTest : public ::testing::TestWithParam<TestData<int>> {
};

// (Макрос) Определяет параметризованный тест.
TEST_P(CalculationTest, VectorIntSum) {
    // GetParam() возвращает текущий экземпляр TestData от DataProvider для данного теста
    const TestData<int>& data = GetParam();
    int result = get_sum<int>(data.arg);
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
    CalculationTest,                        // Имя тестового класса
    ::testing::ValuesIn(DataProvider_GetSum::get_test_cases()),  // Набор данных
    [](const ::testing::TestParamInfo<TestData<int>>& info)
        {
            // Формируем имя теста (опционально, для лучшей читаемости)
            return info.param.test_name;    // Используем имя из структуры TestData
        }
        );



// Stand-alone тест проверки базовой функциональности. Не связан с DataProvider
// Этот тест запустится первым, до параметризованного теста
TEST(StandAloneTestsSuite, BasicTest_01) {
    std::vector<int> v1 {10, 20, 30, 5 };
    ASSERT_NEAR(get_sum<int>(v1), 65, 1e-6);
}
TEST(StandAloneTestsSuite, BasicTest_02) {
    std::vector<int> v1 {-10, -20, -30};
    ASSERT_NEAR(get_sum<int>(v1), -60, 1e-6);
}
