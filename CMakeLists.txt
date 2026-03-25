cmake_minimum_required(VERSION 3.10)
project(SGBD_BufferManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(buffer_manager
    src/main.cpp
)
