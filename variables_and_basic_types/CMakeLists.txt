project(variables_and_basic_types)
add_subdirectory(extern_type)
add_executable(main_1 main.cpp )
#target_link_directories() 外部的lib
#link_directories() 所有的目标共享的lib
#target_include_directories() 外部lib的头文件
#target_include_directories( main_1
#        PUBLIC ${PROJECT_SOURCE_DIR}
#        )
#message(${PROJECT_SOURCE_DIR})
#message(${PROJECT_BINARY_DIR})
target_link_libraries(main_1 externType)
target_link_libraries(main_1 sales_data)
target_link_libraries(main_1 window_mgr)
target_link_libraries(main_1 screen)
