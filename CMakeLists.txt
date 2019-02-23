cmake_minimum_required(VERSION 3.12)
project(LaboratoryWork_1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


add_executable(LaboratoryWork_1 main.cpp Tests/List.h Tests/UnitTests.cpp)
target_link_libraries(LaboratoryWork_1 gtest gtest_main)