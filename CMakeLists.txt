cmake_minimum_required(VERSION 3.14)
project(Galaga_enC C)
set(CMAKE_C_STANDARD 99)

add_executable(Galaga_enC main.c libgalaga.c libgalaga.h juego.c juego.h)
add_executable(Menu menu/Instruccion.c menu/Instruccion.h menu/menu.h menu/como_jugar.c menu/como_jugar.h menu/menu.c)
add_executable(pantalla interfaz/Inte_color_fondo.c interfaz/Inte_color_fondo.h)
