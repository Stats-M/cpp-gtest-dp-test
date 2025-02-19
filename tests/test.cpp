#include "test.h"

// Переехало в test.h
//#include <gtest/gtest.h>
//#include <gmock/gmock.h>

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример теста для функции, принимающей vector<int> в качестве аргумента.
// Связка class (фиксация типа) + TEST_P + INSTANTIATE_TEST_SUITE_P
// РЕАЛИЗАЦИЯ: DataProvider + параметризованный тест (*_P)
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
        VectorCalculationTest,                  // Имя тестового класса
        ::testing::ValuesIn(DataProvider_GetSum::get_test_cases()),  // Набор данных
        [](const ::testing::TestParamInfo<TestDatasetWithVector<int>>& info)
            {
                // Формируем имя для каждого набора данных теста (опционально, для лучшей читаемости)
                return info.param.test_name;    // Используем имя из структуры TestDatasetWithVector
            }
                        );


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример теста для функции, принимающей скаляр double в качестве аргумента.
// Связка class (фиксация типа) + TEST_P + INSTANTIATE_TEST_SUITE_P
// РЕАЛИЗАЦИЯ: DataProvider + параметризованный тест (*_P)
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
// Пример теста для функции, принимающей скаляр double в качестве аргумента.
// Связка class (фиксация типа) + TEST_P + INSTANTIATE_TEST_SUITE_P
// РЕАЛИЗАЦИЯ: DataProvider + НЕпараметризованный тест
// Недостаток: данные из DP передаются в test_cases все и сразу
// Достоинства: простота реализации
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Непараметризованый тест
TEST(CalculationTest, ScalarPow2) {
    auto test_cases = DataProvider_GetPow2::get_test_cases();

    for (const auto& data : test_cases)
    {
        double result = get_pow_2(data.arg);
        ASSERT_NEAR(result, data.expected_result, 1e-6) << "Test Case: " << data.test_name;
    }
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример шаблонного теста для функции типа vector, принимающей const vector в качестве аргумента.
// Связка шаблонных функции + DataProvider + тестовый класс + параметризованый тест (TYPED_TEST)
// РЕАЛИЗАЦИЯ: DataProvider + параметризованный тест
// Недостаток: данные из DP передаются в test_cases все и сразу, const-вектор, return копия
// Достоинства: шаблонный DP, разные наборы данных для разных типов
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Определяем типы данных для тестов, используя Type Definitions.
using IntDoubleTypes = ::testing::Types<int, double>;
// Т.к. тестовый класс сейчас шаблонный, он определен в test.h
TYPED_TEST_SUITE(TestMultiplyBy2, IntDoubleTypes);

// Параметризованный по типам тест
TYPED_TEST(TestMultiplyBy2, ConstVectorMultiplyByTwo)
{
    // To refer to typedefs in the fixture, add the 'typename TestFixture::'
    // prefix.  The 'typename' is required to satisfy the compiler.
    using T = typename TestFixture::ParamType;
    // Или: using ParamType = typename TestFixture::ParamType;

    // Получаем все наборы данных разом. Эмуляция получения по одному набору за раз слишком переусложнена.
    std::vector<TestDatasetBothVectors<T>> test_cases = DataProvider_MultiplyBy2<T>::get_test_cases();

    for (const TestDatasetBothVectors<T>& data : test_cases)
    {
        std::vector<T> result = multiply_by_two(data.args);

        // Кастомная функция поэлементного сравнения через ASSERT_EQ
        AssertVectorsAreEqual<T>(data.expected_result, result, data.test_name);
    }
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример шаблонного теста для void-функции, принимающей не-const ссылку на вектор в качестве аргумента.
// Связка шаблонных функции + DataProvider + тестовый класс + параметризованый тест (TYPED_TEST)
// РЕАЛИЗАЦИЯ: DataProvider + параметризованный тест
// Недостаток: данные из DP передаются в test_cases все и сразу, const-ограничения макроса остаются
// Достоинства: шаблонный DP, разные наборы данных для разных типов, для не-const аргументов
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Определяем типы данных для тестов, используя Type Definitions.
//using IntDoubleTypes = ::testing::Types<int, double>;             // <- Переиспользуем тип из предыдущего теста
// Т.к. тестовый класс сейчас шаблонный, он определен в test.h
TYPED_TEST_SUITE(TestMultiplyBy2, IntDoubleTypes);                  // <- Переиспользуем тип из предыдущего теста

// Параметризованный по типам тест
TYPED_TEST(TestMultiplyBy2, VectorMultiplyByTwoByRef) {
    // To refer to typedefs in the fixture, add the 'typename TestFixture::'
    // prefix.  The 'typename' is required to satisfy the compiler.
    using T = typename TestFixture::ParamType;
    // Или: using ParamType = typename TestFixture::ParamType;

    // Получаем все наборы данных разом. Эмуляция получения по одному набору за раз слишком переусложнена.
    auto test_cases = DataProvider_MultiplyBy2<T>::get_test_cases();

    for (const auto& data : test_cases) {
        std::vector<T> input_copy = data.args;  // Создаем копию входного вектора, т.к. нельзя обойти const-ограничение макроса
        multiply_by_two_void(input_copy);    // Вызываем функцию для изменения копии

        // Сравниваем измененную копию с ожидаемым результатом
        AssertVectorsAreEqual(data.expected_result, input_copy, data.test_name);
    }
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример простых stand-alone тестов без использования DataProvider
// Классические unit-тесты с генерацией тестовых кейсов на лету
// РЕАЛИЗАЦИЯ: Локальные наборы тестовых данных
// Недостаток: не используется DP
// Достоинства: самая простая реализации
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
TEST(StandAloneTestsSuite, VectorTest_01)
{
    std::vector<double> expected{1.0, -4.0, 3.0, 0.5};
    std::vector<double> actual{1.0, 20.0, 55.0, 0.5};
    ASSERT_NE(actual, expected);
}
TEST(StandAloneTestsSuite, VectorTest_02)
{
    std::vector<double> expected{1.0, -4.0, 3.0, 0.5};
    std::vector<double> actual{2.0, -4.0, 3.0, 0.5};
    ASSERT_GT(actual, expected);
}
TEST(StandAloneTestsSuite, VectorTest_03Fail)
{
    std::vector<double> expected{1.0, -4.0, 3.0, 0.5};
    std::vector<double> actual{0.0, -4.0, 3.0, 0.5};
    ASSERT_GT(actual, expected);
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Пример работы макросов из библиотеки Google Mock. Используется для
// выполнения более сложных проверок контейнеров при помощи Matchers
// Недостаток: отдельный макрос, совместимость с другими тестами под вопросом
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
TEST(VectorTest, AreEqualUsingMatchers) {
    std::vector<int> expected {10, 20, 30, 5 };
    std::vector<int> actual {10, 20, 30, 5 };
    ASSERT_THAT(actual, ::testing::ContainerEq(expected));
}
