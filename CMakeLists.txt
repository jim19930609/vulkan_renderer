cmake_minimum_required(VERSION 3.17)

project(vulkan_tutorial)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_VISIBILITY_PRESET default)

################################
# Prepare third party packages #
################################
find_package(Vulkan REQUIRED)
message("Using Vulkan Include Dir: ${Vulkan_INCLUDE_DIRS}")
message("Using Vulkan Lib: ${Vulkan_LIBRARIES}")

find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)

add_subdirectory(renderer)

add_executable(vulkan_app main.cpp)
target_link_libraries(vulkan_app 
                      ${Vulkan_LIBRARIES}
                      renderer)
target_include_directories(vulkan_app PUBLIC
                           ${Vulkan_LIBRARIES}
                           ${CMAKE_SOURCE_DIR}
                           ${CMAKE_SOURCE_DIR}/renderer)

execute_process(COMMAND glslc "${CMAKE_SOURCE_DIR}/shaders/shader.frag" -o "${CMAKE_SOURCE_DIR}/shaders/frag.spv")
execute_process(COMMAND glslc "${CMAKE_SOURCE_DIR}/shaders/shader.vert" -o "${CMAKE_SOURCE_DIR}/shaders/vert.spv")
