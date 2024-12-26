cmake_minimum_required(VERSION 3.20.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(cmdio VERSION 1.0.0 LANGUAGES C)
set(C_STANDART 23)

add_library(${PROJECT_NAME} SHARED cmdio.c)
