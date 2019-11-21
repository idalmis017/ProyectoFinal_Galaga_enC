//
// Created by hola on 20/11/2019.
//

#include "libgalaga.h"
#include "juego.h"

void inicio(){
    char opcion;
    do{
        printf("\t*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*\n"
               "\t _______   _______   _         _______   _______   _______ \n"
               "\t|  ___  | |  ___  | | |       |  ___  | |  ___  | |  ___  |\n"
               "\t| |   |_| | |   | | | |       | |   | | | |   |_| | |   | |\n"
               "\t| |  ___  | |___| | | |       | |___| | | |  ___  | |___| |\n"
               "\t| | |_  | |  ___  | | |       |  ___  | | | |_  | |  ___  |\n"
               "\t| |___| | | |   | | | |_____  | |   | | | |___| | | |   | |\n"
               "\t|_______| |_|   |_| |_______| |_|   |_| |_______| |_|   |_| \n"
               "\t*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*\n");
        printf("\n\t\t*----------------------*"
               "\n\t\t|1 - Menu Principal     |"
               "\n\t\t------------------------"
               "\n\t\t|2 -      Salir         |"
               "\n\t\t------------------------");
        scanf("%c",&opcion);
        switch(opcion){
            case '1':
                fflush(stdin);
                menu_principal();
                break;
            case '2':
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        fflush(stdin);
        system("pause");
        limpiar();
    }while(opcion!=1 && opcion !=2);



}
void limpiar(){
    system("cls");
}
void menu_principal(){
    char opcion;
    do{

        printf("\n\t"
               "*----------------------*\n\t"
               "|1 - Inicio            |\n\t"
               "------------------------\n\t"
               "|2 - Calificaciones    |\n\t"
               "------------------------\n\t"
               "|3 - Instrucciones     |\n\t"
               "------------------------\n\t"
               "|4 - Configuraciones   |\n\t"
               "------------------------\n\t"
               "|5 - Sobre el juego    |\n\t"
               "------------------------\n\t"
               "|6 - Salir             |\n\t"
               "*----------------------*\n\t");
        scanf("%c",&opcion);
        switch(opcion){
            case '1':
                fflush(stdin);
                juego();
                break;
            case '2':
                fflush(stdin);
                calificaciones();
                break;
            case '3':
                fflush(stdin);
                como_jugar();
                break;
            case '4':
                fflush(stdin);
                configuraciones();
                break;
            case '5':
                fflush(stdin);
                intrucc();
                break;
            case '6':
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        system("pause");
        limpiar();
    }while(opcion > 6);

}
void intrucc(){
    char opcion;
    do{
        printf("\t\t------------------------------------------\n"
               "\t\t| B I E N V E N I D O   A   G A L A G A  |\n"
               "\t\t------------------------------------------\n");
        printf("\t-------------------------------------------------------------------------------");
        printf("\t|  Galaga es un videojuego matamarcianos creado en 1981 por la empresa Namco. |\n"
               "\t|            Fue creado como el sucesor del Galaxian (1979).                  |\n"
               "\t|  El jugador controla una nave que debe enfrentarse contra un enjambre de    |\n"
               "\t|  aliens con forma de insecto que le atacarán disparando bombas              |\n"
               "\t|                 y actuando como kamikazes.                                  |\n"
               "\t-------------------------------------------------------------------------------\n\n\n"
               "\t------------------------------------------------------------------------------"
               "\t|        Plataformas: Árcade, Nintendo, Entertainmnt System.                 |\n"
               "\t|        Desarrolladores: Namco, Majesco Entertainment, Namco Networks       |\n"
               "\t|        Distribuidores: Namco, Atari, Bandai Namco Games.                   |\n"
               "\t|        Game: Videojuego de un jugador. Videojuego multijugador             |\n"
               "\t------------------------------------------------------------------------------\n");
        printf("\n\n 1-VOLVER AL MENU PRINCIPAL                               2-SALIR DEL JUEGO");
        scanf("%c",&opcion);
        switch(opcion){
            case '1':
                fflush(stdin);
                menu_principal();
                break;
            case '2':
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        system("pause");
        limpiar();

    }while(opcion!=1 && opcion !=2);
}

void salir(){
    exit(0);
}
void como_jugar(){
    char opcion;
    do{
        printf("\t\t------------------------------------------\n"
               "\t\t|     C O M O  J U G A R  G A L A G A     |\n"
               "\t\t------------------------------------------\n");
        printf("\t-------------------------------------------------------------------------------");
        printf("\t|  Para jugar esta version del gran juego es tan simple como beber un vaso de  |\n"
               "\t|                               agua.                                          |\n"
               "\t|  Estos son los botones que debes usar para controlar la nave:                |\n"
               "\t|  * La tecla A                   ...           MUEVES LA NAVE A LA DERECHA    |\n"
               "\t|  * La tecla D                   ...           MUEVES LA NAVE A LA IZQUIERDA  |\n"
               "\t|  * La tecla M                   ...           UTILIZALA PARA DISPARAR        |\n"
               "\t-------------------------------------------------------------------------------\n\n\n"
               "\t------------------------------------------------------------------------------"
               "\t|    Recuerda que no debes dejar que te golpeen los lasers de los aliens.      |\n"
               "\t|    Si te golpean 5 veces PIERDES LA PARTIDA.                                 |\n"
               "\t|    Las naves escudadas (las que se presenten con un cuadrado negro ),        |\n"
               "\t|    se eliminan al dispararle 2 veces.                                        |\n"
               "\t|    Al eliminar una nave obtienes    ...                50 puntos             |\n"
               "\t|    Si te eliminan pero sobrepasas los 1500 puntos, puedes obtar por el        |\n"
               "\t|    NIVEL BONUS, donde tendras la opotunidad de eliminar a las nave madre,    |\n"
               "\t|    estas poseen unos fuertes escudos y solo las eliminas al dispararle 5     |\n"
               "\t|    veces.Cada nave madre eliminada, te da 150 pts en tu puntuacion final.    |\n"
               "\t|    Ganas al completar una puntuacion de 3750 puntos                          |\n"
               "\t|    Al terminar o ser eliminado, puedes guardar tus datos para añadirte a     |\n"
               "\t|    la  tabla de puntuaciones del juego.                                      |\n"
               "\t------------------------------------------------------------------------------\n");
        printf("\n\n 1-VOLVER AL MENU PRINCIPAL                               2-SALIR DEL JUEGO");
        scanf("%c",&opcion);
        switch(opcion){
            case '1':
                fflush(stdin);
                menu_principal();
                break;
            case '2':
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        system("pause");
        limpiar();

    }while(opcion!=1 && opcion !=2);
}

void calificaciones(){
    //Esta funcion  se esta desempeñando aparte y sera una de las ultimas, se creo la estructura
    //Jugardor (jgdr), para ir almancenando todos los datos del jugador si este lo desea en un file.

}
void configuraciones(){
    int color;
    printf("Configuraciones de pantalla");
    do{
        printf("Combinaciones de colores: \n"
               " _______________________________________"
               "|  Opcion ----- Pantalla-----  Texto    |\n"
               "|_______________________________________|"
               "|    1   ------- Blanco ----  Agua      |\n"
               "|    2   ------- Azul  -----  Amarillo  |\n"
               "|    3   ------- Rojo  -----  Negro     |\n"
               "|    4   ------- Gris  -----  Azul      |\n"
               "|    5   -----  Purpura ----  Verde     |\n"
               "|_______________________________________|\n\n");
        scanf("%d",&color);
        switch (color){
            case 1 :
                fflush(stdin);
                system("color 7B ");
                break;
            case 2 :
                fflush(stdin);
                system("color 1E");
                break;
            case 3:
                fflush(stdin);
                system("color 40");
                break;
            case 4:
                fflush(stdin);
                system("color 81");
            case 5:
                fflush(stdin);
                system("color D2");

            default:
                printf("No existe esa combinacion");
                break;

        }
        limpiar();
    }while(color<1 && color>6);


}


void datos(){
    jgdr nuevo;
    printf("\t---------------------------");
    printf("\t %cR E G I S T R A T E!");
    printf("\t---------------------------");
    printf("\n");
    printf("\tNombre: ");gets(nuevo.nombre);
    printf("\n\n");
    printf("\tEdad: ");gets(nuevo.edad);
    printf("\n\n");
    fflush(stdin);
    printf("\tNacionalidad: ");gets(nuevo.nacionalidad);
    printf("\n\n");
    printf("\tDigita el ID de tu preferencia: ");gets(nuevo.id);
    printf("\n\n");

    printf("\t---------------------------");
    printf("\t %cL I S T O!");
    printf("\t---------------------------");
    limpiar();
    menu();

}

