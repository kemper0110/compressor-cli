cmake_minimum_required(VERSION 3.28)
project(compressor_cli)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(compressor-cpp)


add_executable(compressor_cli main.cpp)

target_include_directories(compressor_cli PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/compressor-cpp/include)

target_link_libraries(compressor_cli PRIVATE compressor)
