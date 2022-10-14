project(extern_type)

add_library(externType extern_type.cpp)

target_include_directories(externType PUBLIC ${PROJECT_SOURCE_DIR})