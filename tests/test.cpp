#include <gtest/gtest.h>
#include "../src/cube.h"          // Заголовочный файл с вашим кодом

// Пример функции, которую тестируем (замените на вашу)
//double get_sum(std::vector args);

TEST(TestSuiteName, SimpleTest) {
// Простой тест для проверки базовой функциональности
std::vector<int> v1 {1, 2, 3, 4 };
ASSERT_NEAR(get_sum(v1), 10, 1e-6);
}
