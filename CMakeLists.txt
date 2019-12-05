cmake_minimum_required(VERSION 3.14)
project(Galaga_enC C)
set(CMAKE_C_STANDARD 99)

add_executable(Galaga_enC juego/main.c juego/libgalaga.c juego/libgalaga.h)

