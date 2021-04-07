cmake_minimum_required(VERSION 3.17)
project(pcad_1 C)

set(CMAKE_C_STANDARD 11)
include_directories(matrix)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

link_libraries(Threads::Threads)

add_executable(esercizio_1 esercizio_1.c)
add_executable(esercizio_2 esercizio_2.c matrix/matrix.h matrix/matrix.c)

