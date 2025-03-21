cmake_minimum_required(VERSION 3.10.0)
project(example VERSION 0.1.0 LANGUAGES C CXX)

add_executable(main example.cpp)

include_directories(
    ${PROJECT_SOURCE_DIR}/core
    ${PROJECT_SOURCE_DIR}/utils
)
