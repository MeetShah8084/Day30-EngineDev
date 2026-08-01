cmake_minimum_required(VERSION 3.30)
project(Day4 LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(Day4 src/main.cpp)
target_include_directories(Day4 PRIVATE ${CMAKE_SOURCE_DIR}/include)
# target_link_libraries(Day4 PRIVATE libList)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Day4 PRIVATE -Wall -Wextra -pedantic -O3 -fdump-lang-class)
elseif(CMAKE_COMPILER_D STREQUAL "MSVC")
    target_compile_options(Day4 PRIVATE /W4 /permissive- /O2 /d1reportSingleClassLayoutA)
endif()

