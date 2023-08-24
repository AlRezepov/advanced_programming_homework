cmake_minimum_required(VERSION 3.5)

project(MyTest)

add_subdirectory (../Catch2 Catch2-build)
add_executable(MyTest task_02.cpp)
target_link_libraries(MyTest PRIVATE Catch2::Catch2)