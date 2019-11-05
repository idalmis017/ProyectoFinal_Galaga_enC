

#include "Instruccion.h"

void opcion(){
    int opcion;
    do{
        printf("\t1 - Inicio \n\t2 - Calificaciones \n\t 3 - Instrucciones \n\t4 - Configuraciones \n\t5 - Salir");
        gets(opcion);
        switch(opcion){
            case '1':
                juego();
            case '2':
                calificaciones();
            case '3':
                instrucciones();
            case '4':
                configuraciones();
            case '5':
                salir();
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
        }
    system("cls");
    }while(opcion > 6);

}
void datos(){
    jgdr nuevo;
    printf("\t-*-------------------------*-");
    printf("\t %cR E G I S T R A T E!");
    printf("\t-*-------------------------*-");
    printf("\n");
    printf("\tNombre: ");gets(nuevo.nombre);
    printf("\n");
    printf("\tEdad: ");gets(nuevo.edad);
    printf("\n");
    fflush(stdin);
    printf("\tNacionalidad: ");gets(nuevo.nacionalidad);
    printf("\n");
    printf("\tDigita el ID de tu preferencia: ");gets(nuevo.id);
    printf("\n");

    printf("\t-*-------------------------*-");
    printf("\t %cL I S T O!");
    printf("\t-*-------------------------*-");
    printf("%cPREPARATE PARA JUGAR!");
    limpiar();
    menu();

}
void recopilacion_datos(){

}