#pragma once

#include "TestDataProvider.h"   // Поставщик данных
#include "../src/cube.h"        // Заголовочный файл с проверяемым кодом

#include <string>
#include <vector>

// Фиксируем тип шаблонной функции, которую тестируем
double get_sum(std::vector<int> args);

// Обычная функция, которую тестируем. Уже объявлена в cube.h
//double get_cube(double arg);

// Обычная функция, которую тестируем. Уже объявлена в cube.h
//double get_pow_2(double arg);
