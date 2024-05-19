cmake_minimum_required(VERSION 3.5)
project(COSI)

if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif ()

if (NOT CMAKE_COMPILER_IS_GNUCXX)
    #message( FATAL_ERROR "COMPILER IS NOT GNU_CXX, EXITING" )
endif ()


if (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC /include)
