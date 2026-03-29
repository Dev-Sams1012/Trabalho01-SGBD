cmake_minimum_required(VERSION 3.10)
project(SGBD_BufferManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(buffer_manager
    src/main.cpp
    src/page.cpp
    src/buffer_manager.cpp
    src/buffer_manager_FIFO.cpp
    src/buffer_manager_LRU.cpp
    src/buffer_manager_MRU.cpp
    src/buffer_manager_CLOCK.cpp
)
