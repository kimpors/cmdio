cmake_minimum_required(VERSION 3.20.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(cmdio VERSION 1.0.0 LANGUAGES C)
set(CMAKE_C_STANDART 23)

set(PROJECT_DEMO_NAME ${PROJECT_NAME}_demo)

add_executable(${PROJECT_DEMO_NAME} demo.c cmdio.c)
add_library(${PROJECT_NAME} SHARED cmdio.c)

