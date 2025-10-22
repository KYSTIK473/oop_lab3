cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(figures_main
    src/main.cpp
    src/figure.cpp
    src/rhombus.cpp
    src/fugl.cpp
    src/sugl.cpp
    src/arr.cpp
)


# Тесты
find_package(GTest REQUIRED)
add_executable(figures_tests
    tests/tests.cpp
    src/figure.cpp
    src/rhombus.cpp
    src/fugl.cpp
    src/sugl.cpp
    src/arr.cpp
)

target_link_libraries(figures_tests GTest::GTest GTest::Main)