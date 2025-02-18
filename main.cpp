#include <gtest/gtest.h>                // GoogleTest
#include <iostream>

#include "tests/test.h"                 // Наши тесты

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    // Uncomment if you want to use Google Mock
    //::testing::InitGoogleMock(&__argc, __argv)
    return RUN_ALL_TESTS();
    //return 0;
}
