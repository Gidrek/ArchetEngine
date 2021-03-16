cmake_minimum_required(VERSION 3.17)
project(ArchetEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(ArchetEngine
        src/main.cpp
        src/Engine/Window.cpp
        src/Engine/Window.h src/Utils/glad.c src/Engine/MouseListener.cpp src/Engine/MouseListener.h src/Engine/KeyListener.cpp src/Engine/KeyListener.h)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(ArchetEngine glfw ${OPENGL_LIBRARIES} ${CMAKE_DL_LIBS})