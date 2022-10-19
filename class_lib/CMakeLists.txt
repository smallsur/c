project(class_lib)

add_library(sales_data Sales_data.cpp)
add_library(screen Screen.cpp)
add_library(window_mgr Window_mgr.cpp)

target_include_directories(sales_data PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(screen PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(window_mgr PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(window_mgr screen)