cmake_minimum_required(VERSION 3.22)
project(flex
        VERSION 0.0.1
        DESCRIPTION "typelist manipulation library"
        LANGUAGES CXX)

add_library(flex INTERFACE )
add_library(flex::flex ALIAS flex)

target_compile_features(flex INTERFACE cxx_std_17)

include(${CMAKE_CURRENT_SOURCE_DIR}/include/flex/CMakeLists.txt)
target_include_directories(flex INTERFACE include)

add_subdirectory(tests)