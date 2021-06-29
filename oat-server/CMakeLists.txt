cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(disco-ps VERSION 1.0.0)

# Define lib code
set(LIB_NAME ${PROJECT_NAME}-lib)
add_library(${LIB_NAME} src)

# Oat++
find_package(oatpp 1.2.5 REQUIRED)

# Bundle lib
target_link_libraries(${LIB_NAME}
    PUBLIC oatpp::oatpp)

target_include_directories(${LIB_NAME} PUBLIC src)

# Bundle executable
set(EXECUTABLE_NAME ${PROJECT_NAME}-core)
add_executable(${EXECUTABLE_NAME} 
    src/App.cpp)
 
target_link_libraries(${EXECUTABLE_NAME} ${LIB_NAME})
add_dependencies(${EXECUTABLE_NAME} ${LIB_NAME})