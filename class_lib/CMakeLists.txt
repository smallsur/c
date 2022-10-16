project(class_lib)

add_library(sales_data Sales_data.cpp)

target_include_directories(sales_data PUBLIC ${PROJECT_SOURCE_DIR})