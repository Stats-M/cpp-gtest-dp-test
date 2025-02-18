# Линкуем тесты как исполняемый файл (см. ../CMakeLists.txt)
add_executable(runTests
        test.cpp
        test.h
        TestDataProvider.cpp
        TestDataProvider.h)

# Линкуем библиотеку cpp-gtest-data-provider к исполняемому файлу runTests.
# Это позволяет использовать функции, определённые в main.cpp в файле test.cpp.
## -runTests: Имя исполняемого файла, к которому мы добавляем библиотеки.
## -cpp-gtest-data-provider: Имя нашей основной библиотеки, которую мы линкуем
##      к тестовому исполняемому файлу. Это позволит нам использовать функции и
##      классы, определенные в ней.
## -GTest::gtest - цель (target) CMake, определенная Google Test, представляющая
##      саму библиотеку Google Test (без main()).
## -GTest::gmock - цель (target) CMake, подключающая GMock и делающая доступными в
##      тестах заголовочные файлы <gmock/gmock*.h>
target_link_libraries(runTests cpp-gtest-data-provider GTest::gtest GTest::gmock)
# Включает модуль GoogleTest, который упрощает процесс добавления тестов.
include(GoogleTest)
# Команда CMake для автоматического обнаружения и добавления тестов GoogleTest.
# runTests - имя исполняемого файла, для которого необходимо обнаружить тесты.
gtest_discover_tests(runTests)
