project(TestImGui)

set(CMAKE_CXX_STANDARD 14)

#fetched these using vcpkg manager
find_package(glfw3 CONFIG REQUIRED) # sudo apt-get install libglfw3 libglfw3-dev
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(glad STATIC src/glad.c)

target_include_directories(glad PUBLIC ${PROJECT_SOURCE_DIR}/include)

set(exec_name ${PROJECT_NAME}_exec)

set(IMGUI_SRC
    imgui/src/implot_demo.cpp
    imgui/src/implot_items.cpp
    imgui/src/implot.cpp
    imgui/src/imgui.cpp
    imgui/src/imgui_draw.cpp
    imgui/src/imgui_impl_glfw.cpp
    imgui/src/imgui_impl_opengl3.cpp
    imgui/src/imgui_impl_sdl2.cpp
    imgui/src/imgui_tables.cpp
    imgui/src/imgui_widgets.cpp
    imgui/src/imgui_demo.cpp
)
add_executable(${exec_name} main_sdl2_opengl3.cpp ${IMGUI_SRC})

target_include_directories(${exec_name} PUBLIC 
    ${PROJECT_SOURCE_DIR}/imgui/include
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/imgui/src
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${exec_name} PRIVATE glfw glad SDL2::SDL2 OpenGL::GL)
