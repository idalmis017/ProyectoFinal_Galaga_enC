#ifndef GALAGA_ENC_LIBGALAGA_H
#define GALAGA_ENC_LIBGALAGA_H

#endif //GALAGA_ENC_LIBGALAGA_H

#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<direct.h>

typedef struct Jugador{
    char* id;
    char* nombre;
    char* edad;
    char* nacionalidad;
    char*puntuacion;

}jgdr;
void datos();
void inicio();
void como_jugar();
void menu_principal();
void limpiar();
void salir();
void configuraciones();
void calificaciones();
void intrucc();

