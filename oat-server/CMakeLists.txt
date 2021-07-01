cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(disco-ps VERSION 1.0.0)

# Define lib code
set(LIB_NAME ${PROJECT_NAME}-lib)
set(LIBS 
    src/AppComponent.hpp
    src/controller/AppController.hpp
    src/controller/AppController.cpp
    src/dto/DTOs.hpp)

add_library(${LIB_NAME} STATIC ${LIBS})
 
# Oat++ (server)
find_package(oatpp 1.2.5 REQUIRED)

# sleepy-discord (api lib)
add_subdirectory(vendor/sleepy-discord)

# dotenv (client secrets)
add_subdirectory(vendor/cpp-dotenv)

# Bundle lib
set(VENDOR_LIBRARIES
    oatpp::oatpp
    sleepy-discord
    cpp_dotenv)

target_link_libraries(${LIB_NAME} ${VENDOR_LIBRARIES})

target_include_directories(${LIB_NAME} PUBLIC src)

# Bundle executable
set(EXECUTABLE_NAME ${PROJECT_NAME}-core)
add_executable(${EXECUTABLE_NAME} 
    src/App.cpp)
 
target_link_libraries(${EXECUTABLE_NAME} ${LIB_NAME})
add_dependencies(${EXECUTABLE_NAME} ${LIB_NAME})

# Copy local env file after build
add_custom_command(TARGET ${LIB_NAME} PRE_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/.env
            ${CMAKE_CURRENT_BINARY_DIR}/.env)