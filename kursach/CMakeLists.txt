cmake_minimum_required(VERSION 3.23)
project(train_management VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CONFIGURE_DEPENDS true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Исходные файлы
file(GLOB SRC 
    "src/*.cpp")

file(GLOB HEADERS 
    "headers/*.hpp")

add_executable(train_management
    main.cpp
    ${SRC}
    ${HEADERS}
)

target_include_directories(train_management PRIVATE
    ${CMAKE_SOURCE_DIR}/headers
)