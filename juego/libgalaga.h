#ifndef GALAGA_ENC_LIBGALAGA_H
#define GALAGA_ENC_LIBGALAGA_H

#endif //GALAGA_ENC_LIBGALAGA_H

#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<direct.h>


typedef struct JUGADOR{
    char nombre[20];
    int puntuacion;
    float tiempo;
}jugador;

void inicio();
void juego();
void como_jugar();
void menu_principal();
void limpiar();
void salir();
void configuraciones();
void calificaciones();
void intrucc();
void nuevo(jugador jgdr, float TiempoTranscurrido, int score);
int obtener_archivo(jugador jdr);
int mostrar_archivo();
void ExtraLevel(int extrascore, float extratime, int extraenemies, jugador jdr);
void Final_Juego(int victory, int score, int EnemiesDisplay, float TiempoTranscurrido, int choice, jugador jdr);
