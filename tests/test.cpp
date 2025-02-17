#include <gtest/gtest.h>
#include "test.h"

#include "../src/cube.h"          // Заголовочный файл с проверяемым кодом

// Параметризованный тестовый класс. Наследуется от ::testing::TestWithParam<TestData>.
// TestData указывает, какой тип данных будет параметром для теста.
class CalculationTest : public ::testing::TestWithParam<TestData<int>> {
};

// Определяем тестовый случай
// Макрос, который определяет параметризованный тест.
// GetParam() возвращает текущий экземпляр TestData для данного теста.
TEST_P(CalculationTest, MatrixCalculation) {
    const TestData<int>& data = GetParam();
    int result = get_sum<int>(data.args);
    ASSERT_NEAR(result, data.expected_result, 1e-6) << "Test Case: " << data.test_name; // Добавляем имя для отладки
}

// Генерируем тестовые случаи
// Макрос, который "инстанцирует" параметризованный тест.
//   * Первый аргумент - префикс для имен тестов.
//   * Второй аргумент - имя тестового класса.
//   * Третий аргумент - набор данных, который будет использоваться для параметризации
//     (в нашем случае, результат MyDataProvider::get_test_cases()).
//   * Четвертый аргумент (опционально) - функция, которая формирует имя теста на основе параметра.
INSTANTIATE_TEST_SUITE_P(
    MyCalculationTests,                     // Префикс для имен тестов
    CalculationTest,                        // Имя тестового класса
    ::testing::ValuesIn(MyDataProvider::get_test_cases()),  // Набор данных
    [](const ::testing::TestParamInfo<TestData<int>>& info)
        {
            // Формируем имя теста (опционально, для лучшей читаемости)
            return info.param.test_name;    // Используем имя из структуры TestData
        }
        );

TEST(TestSuiteName, SimpleTest) {
// Простой тест для проверки базовой функциональности
std::vector<int> v1 {1, 2, 3, 4 };
ASSERT_NEAR(get_sum<int>(v1), 10, 1e-6);
}
