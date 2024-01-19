cmake_minimum_required(VERSION 3.28)

project(probable_guide)

add_executable(probable_guide 
    src/main.cpp
    src/probable_guide.cpp
    src/window.cpp
    src/vulkan_context.cpp
)

set_property(TARGET probable_guide PROPERTY CXX_STANDARD 23)

target_include_directories(probable_guide PRIVATE include)

target_link_libraries(probable_guide PRIVATE glfw glm Vulkan::Vulkan)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git  
    GIT_TAG        3.3.9
)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG     0.9.9.8
)

set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "glfw docs not needed")

FetchContent_MakeAvailable(glfw glm)

find_package(Vulkan REQUIRED)

# vim:set sw=4 ts=4 et:
