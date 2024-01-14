cmake_minimum_required(VERSION 3.22)

project(probable_guide)

add_executable(probable_guide 
    src/main.cpp
    src/probable_guide.cpp
    src/window.cpp
)

set_property(TARGET probable_guide PROPERTY CXX_STANDARD 23)

target_include_directories(probable_guide PRIVATE include)

target_link_libraries(probable_guide PRIVATE glfw)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git  
    GIT_TAG        3.3.9
)

FetchContent_MakeAvailable(glfw)

