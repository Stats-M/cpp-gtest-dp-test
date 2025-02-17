#pragma once

#include "test.h"

#include <vector>

// Класс Data Provider'а
class MyDataProvider
{
public:
    static std::vector<TestData<int>> get_test_cases();
private:
};
