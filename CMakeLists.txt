cmake_minimum_required(VERSION 3.14)

project(InventoryManagement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(inventory_app src/main.cpp)
include(CTest)

if(BUILD_TESTING)
    add_executable(inventory_tests tests/inventory_tests.cpp)
    add_test(NAME inventory_tests COMMAND inventory_tests)
endif()