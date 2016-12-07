cmake_minimum_required(VERSION 3.6)
project(dbengine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES
        "main.c"
        "dbFunctions.c"
        "dbFunctions.h")

add_executable(dbengine ${SOURCE_FILES})