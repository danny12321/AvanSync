cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)

project(AvanSync)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(client)
add_subdirectory(server)