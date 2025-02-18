# cpp-gtest-dp-test
## Test use of Data Providers within Google Test (python way for tests)

Пробный проект использования пакета Google Test (Test + Mock). Установка библиотеки производится в локальную build-директорию силами самого CMake полностью автоматически при загрузке проекта
Обычно это <project_dir>/cmake-build-debug/_deps/googletest-src

Проект Google Test собирается как application, а тестируемые классы линкуются к нему как статическая библиотека, см. файлы CMakeLists.txt в корне проекта и директории /tests

Т.к. основной исполняемый файл и есть тесты, достаточно просто запустить проект в IDE как обычное приложение.
В наборы тестовых данных заранее внесено несколько ошибок, чтобы можно было оценить формат и степень подробности диагностических сообщений.

### Стартовый файл для изучения - tests/test.cpp

* -main.cpp - запуск проекта, инициализация Google Test
* -tests/test.h - заголовки функций, шаблонные реализации
* -tests/test.cpp - наборы тестов различной реализации для сравнения и выбора наиболее удобного или поднобного из них
* -tests/TestDataProvider.h - шаблоны наборов тестовых данных, шаблоны или объявления data provider'ов
* -tests/TestDataProvider.cpp - определения data provider'ов (фактически, задание наборов тестовых данных)
* -src/cube.h - заголовки проверяемых функций
* -src/cube.cpp - определения проверяемых функций

