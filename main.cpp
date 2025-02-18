#include <gtest/gtest.h>                // GoogleTest
#include <iostream>

#include "tests/test.h"                 // Наши тесты

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock();        // В этом проекте нам не нужно парсить аргументы командной строки
    return RUN_ALL_TESTS();
    //return 0;
}
