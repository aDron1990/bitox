cmake_minimum_required(VERSION 3.5)

project(bitox VERSION 0.0.1)

#set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(OpenGL REQUIRED)
add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)
add_subdirectory(libs/glew)
add_subdirectory(libs/ntree)
add_subdirectory(libs/stb_image)

add_compile_definitions("BITOX_BUILD")

include_directories(include/)

file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE headers "include/*.hpp")
add_library(${PROJECT_NAME} STATIC ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL libglew_static glfw stb_image)
target_link_libraries(${PROJECT_NAME} INTERFACE glm ntree)
target_include_directories(${PROJECT_NAME} PUBLIC include/)