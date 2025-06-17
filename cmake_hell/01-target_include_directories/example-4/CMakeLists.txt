cmake_minimum_required(VERSION 3.10.0)
project(example VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(core)

add_executable(main example.cpp)
# target_link_libraries(main PRIVATE core)

# target_include_directories(main INTERFACE
#     ${PROJECT_SOURCE_DIR}/core/include
#     # ${PROJECT_SOURCE_DIR}/utils
# )

# target_include_directories(main PUBLIC
#     ${PROJECT_SOURCE_DIR}/utils
# )
