cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(Day1 src/main.cpp src/add.cxx)

target_include_directories(Day1 PUBLIC ${CMAKE_SOURCE_DIR}/include)


# To get all the warnings,make sure code is based on C++ standard and   
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "CLANG")
    target_compile_options(Day1 PRIVATE -Wextra -Wall -pedentic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Day1 PRIVATE /W4)
endif()
