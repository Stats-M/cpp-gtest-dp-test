#include <gtest/gtest.h>                // GoogleTest
#include <iostream>

#include "tests/test.h"                 // Наши тесты

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    //return 0;
}
