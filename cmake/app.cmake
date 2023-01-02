function(add_app NAME SOURCES)
    add_executable(${NAME} ${SOURCES})
    target_link_libraries(${NAME} 
                          ${Vulkan_LIBRARIES}
                          renderer)
    target_include_directories(${NAME} PUBLIC
                               ${Vulkan_LIBRARIES}
                               ${CMAKE_SOURCE_DIR})
endfunction()
