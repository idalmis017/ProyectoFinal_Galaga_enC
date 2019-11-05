#include <stdlib.h>
#include <stdio.h>

#ifndef GALAGA_ENC_INSTRUCCION_H
#define GALAGA_ENC_INSTRUCCION_H
void menu();
void juego();
void configuraciones();
void calificaciones();
void instrucciones();
void salir();
void limpiar();
void datos();

void recopilacion_datos(struct JUGADOR nuevo);

typedef struct Jugador{
    char* id;
    char* nombre;
    char* edad;
    char* nacionalidad;

}jgdr;
#endif //GALAGA_ENC_INSTRUCCION_H
