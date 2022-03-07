add_executable(test test.cpp)
target_include_directories(test PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(test ${PYTHON_LIBRARIES})

add_executable(animation animation.cpp)
target_include_directories(animation PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(animation ${PYTHON_LIBRARIES})

add_executable(3d_plot 3d_plot.cpp)
target_include_directories(3d_plot PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(3d_plot ${PYTHON_LIBRARIES})

add_executable(hello hello.cpp)
