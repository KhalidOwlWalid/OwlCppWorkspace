cmake_minimum_required(VERSION 3.15...4.0)

project(union_onion)

set(exec_name union_onion)
set(exec_source_file union_onion.cpp)

find_package(spdlog REQUIRED)

message("Building example for ${exec_name}")
add_executable(${exec_name} ${exec_source_file})
target_link_libraries(${exec_name} PRIVATE spdlog::spdlog)
