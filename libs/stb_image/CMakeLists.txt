cmake_minimum_required(VERSION 3.8)

project(stb_image)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include/)