cmake_minimum_required(VERSION 2.6.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(myprogram C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(ex1 ex1.c)
add_executable(ex2 ex2.c)
#add_executable(ex3 ex3.c)
