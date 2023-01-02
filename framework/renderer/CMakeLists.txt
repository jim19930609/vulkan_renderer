add_library(renderer renderer.cpp)
target_link_libraries(renderer 
                      ${Vulkan_LIBRARIES}
                      glm::glm
                      glfw)
target_include_directories(renderer PUBLIC
                           ${Vulkan_LIBRARIES}
                           ${CMAKE_SOURCE_DIR}
                           )
