project(operation_system)



add_executable(os_main main.cpp)
add_executable(os_mutex os_mutex.cpp)
add_executable(os_producer_consumer os_producer_consumer.cpp)
add_executable(os_reader_writer os_reader_writer.cpp)
add_executable(os_apple_orange os_apple_orange.cpp)

target_link_libraries(os_main pthread)

target_link_libraries(os_mutex pthread)

target_link_libraries(os_producer_consumer pthread)

target_link_libraries(os_reader_writer pthread)

target_link_libraries(os_apple_orange pthread)