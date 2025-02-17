cmake_minimum_required(VERSION 3.28)
project(cpp_gtest_data_provider VERSION 0.0.1)

# Путь до библиотеки xsimd
#set(USER_HOME_DIRECTORY $ENV{USERPROFILE})
#set(XSIMD_INCLUDE_DIR "${USER_HOME_DIRECTORY}/projects/CppProjects/cpp-recall-molecular/xsimd")
#include_directories(${XSIMD_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-12")
#set(CMAKE_CXX_FLAGS "-mavx")   Включение SIMD (SSE) команд при использовании библиотеки xsimd

# Включаем модуль FetchContent
include(FetchContent)

FetchContent_Declare(
        # Объявляем, что хотим "скачать" GoogleTest
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0 # Укажите нужную версию Google Test
)

# Чтобы избежать повторной загрузки, делаем так:
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    # ВНИМАНИЕ! Следующую команду нужно использовать с любой версией, а не только для версий ниже v1.14!!!
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# Включаем поддержку тестов в CMake
enable_testing()

# Отладочные сообщения
message(STATUS "GTest_FOUND: ${GTest_FOUND}")
message(STATUS "GTest_INCLUDE_DIRS: ${GTest_INCLUDE_DIRS}")
message(STATUS "GTest_LIBRARIES: ${GTest_LIBRARIES}")
message(STATUS "If above variables are empty, there no GoogleTest library on local system, check FetchContent or uncomment googletest_SOURCE_DIR")

# Мы не можем слинковать 2 исполняемых файла, поэтому оставим исполняемым файл тестов,
# а наш основной проект будем линковать как статическую библиотеку (.a)
add_library(cpp-gtest-data-provider STATIC
        main.cpp
        src/cube.h
        src/cube.cpp
)

# Линкуем gtest_main, чтобы не создавать функцию main для каждого тестового файла
target_link_libraries(cpp-gtest-data-provider PUBLIC GTest::gtest)

# Добавляем поддиректорию test, в которой нужно обработать свой файл CMakeLists.txt
add_subdirectory(tests)
