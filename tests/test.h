#pragma once

#include "TestDataProvider.h"   // Поставщик данных
#include "../src/cube.h"        // Заголовочный файл с проверяемым кодом

#include <string>
#include <vector>

// Пример шаблонной функции, которую тестируем
double get_sum(std::vector<int> args);

// Пример обычной функции, которую тестируем
double get_cube(double arg);
