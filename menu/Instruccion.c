

#include "Instruccion.h"
#include "como_jugar.h"
#include "menu.h"

void opcion(){
    int opcion;
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
        gets(opcion);
        switch(opcion){
            case '1':
                juego();
            case '2':
                calificaciones();
            case '3':
                como_jugar();
            case '4':
                configuraciones();
            case '5':
                intrucc();
            case '6':
                salir();
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
        }
    system("cls");
    }while(opcion < 6);

}
void datos(){
    jgdr nuevo;
    printf("\t-*-------------------------*-");
    printf("\t %cR E G I S T R A T E!");
    printf("\t-*-------------------------*-");
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

    printf("\t-*-------------------------*-");
    printf("\t %cL I S T O!");
    printf("\t-*-------------------------*-");
    printf("%cPREPARATE PARA JUGAR!");
    limpiar();
    menu();

}
void recopilacion_datos(){

}

void salir(){
    exit(0);
}