//
// Created by hola on 20/11/2019.
//
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<direct.h>
#include<time.h>

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


void inicio()
{

    int opcion;
    do{
        printf("\t*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*\n"
               "\t _______   _______   _         _______   _______   _______ \n"
               "\t|  ___  | |  ___  | | |       |  ___  | |  ___  | |  ___  |\n"
               "\t| |   |_| | |   | | | |       | |   | | | |   |_| | |   | |\n"
               "\t| |  ___  | |___| | | |       | |___| | | |  ___  | |___| |\n"
               "\t| | |_  | |  ___  | | |       |  ___  | | | |_  | |  ___  |\n"
               "\t| |___| | | |   | | | |_____  | |   | | | |___| | | |   | |\n"
               "\t|_______| |_|   |_| |_______| |_|   |_| |_______| |_|   |_| \n"
               "\t*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*\n"
               "\n\t*----------------------* "
               "\n\t|1 - Menu Principal     |"
               "\n\t------------------------ "
               "\n\t|2 -      Salir         |"
               "\n\t------------------------ "
               "\n\t ->Tu opcion:  ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                fflush(stdin);
                menu_principal();
                break;
            case 2:
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        fflush(stdin);
        system("pause");


    }while(opcion>2 && opcion<1);



}
void limpiar()
{
    system("cls");
}
void menu_principal()
{

    limpiar();
    fflush(stdin);
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
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                fflush(stdin);
                juego();
                break;
            case 2:
                fflush(stdin);
                calificaciones();
                break;
            case 3:
                fflush(stdin);
                como_jugar();
                break;
            case 4:
                fflush(stdin);
                configuraciones();
                break;
            case 5:
                fflush(stdin);
                intrucc();
                break;
            case 6:
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }

    }while(opcion > 6);
    system("pause");
    limpiar();

}
void intrucc()
{
    limpiar();
    int opcion;
    do{
        printf("\t\t------------------------------------------\n"
               "\t\t| B I E N V E N I D O   A   G A L A G A  |\n"
               "\t\t------------------------------------------\n");
        printf("\t-------------------------------------------------------------------------------\n");
        printf("\t|  Galaga es un videojuego matamarcianos creado en 1981 por la empresa Namco. |\n"
               "\t|            Fue creado como el sucesor del Galaxian (1979).                  |\n"
               "\t|  El jugador controla una nave que debe enfrentarse contra un enjambre de    |\n"
               "\t|  aliens con forma de insecto que le atacaran disparando bombas              |\n"
               "\t|                 y actuando como kamikazes.                                  |\n"
               "\t-------------------------------------------------------------------------------\n\n\n"
               "\t------------------------------------------------------------------------------\n"
               "\t|        Plataformas: Arcade, Nintendo, Entertainmnt System.                 |\n"
               "\t|        Desarrolladores: Namco, Majesco Entertainment, Namco Networks       |\n"
               "\t|        Distribuidores: Namco, Atari, Bandai Namco Games.                   |\n"
               "\t|        Game: Videojuego de un jugador. Videojuego multijugador             |\n"
               "\t------------------------------------------------------------------------------\n");
        printf("\n\n 1-VOLVER AL MENU PRINCIPAL                               2-SALIR DEL JUEGO"
               "\n ->");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                fflush(stdin);
                menu_principal();
                break;
            case 2:
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        system("pause");
        limpiar();

    }while(opcion > 2 && opcion < 1);
}

void salir()
{

    exit(0);
}
void como_jugar()
{
    int opcion;
    do{
        printf("\t\t------------------------------------------\n"
               "\t\t|     C O M O  J U G A R  G A L A G A     |\n"
               "\t\t------------------------------------------\n");
        printf("\t-------------------------------------------------------------------------------\n");
        printf("\t|  Para jugar esta version del gran juego es tan simple como beber un vaso de  |\n"
               "\t|                               agua.                                          |\n"
               "\t|  Estos son los botones que debes usar para controlar la nave:                |\n"
               "\t|  * La tecla A                   ...           MUEVES LA NAVE A LA DERECHA    |\n"
               "\t|  * La tecla D                   ...           MUEVES LA NAVE A LA IZQUIERDA  |\n"
               "\t|  * La tecla M                   ...           UTILIZALA PARA DISPARAR        |\n"
               "\t-------------------------------------------------------------------------------\n\n\n"
               "\t------------------------------------------------------------------------------\n"
               "\t|    Recuerda que no debes dejar que te golpeen los lasers de los aliens.      |\n"
               "\t|    Si te golpean 5 veces PIERDES LA PARTIDA.                                 |\n"
               "\t|    Las naves escudadas (las que se presenten con un cuadrado negro ),        |\n"
               "\t|    se eliminan al dispararle 2 veces.                                        |\n"
               "\t|    Al eliminar una nave obtienes    ...                50 puntos             |\n"
               "\t|    Si te eliminan pero sobrepasas los 500 puntos, puedes obtar por el        |\n"
               "\t|    NIVEL BONUS, donde tendras la opotunidad de eliminar a las nave madre,    |\n"
               "\t|    estas poseen unos fuertes escudos y solo las eliminas al dispararle 5     |\n"
               "\t|    veces.Cada nave madre eliminada, te da 150 pts en tu puntuacion final     |\n"
               "\t|    Al terminar o ser eliminado, puedes guardar tus datos para agregarte a     |\n"
               "\t|    la  tabla de puntuaciones del juego.                                      |\n"
               "\t------------------------------------------------------------------------------\n");
        printf("\n\n 1-VOLVER AL MENU PRINCIPAL                               2-SALIR DEL JUEGO"
               "\n -> ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                fflush(stdin);
                menu_principal();
                break;
            case 2:
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        system("pause");
        limpiar();

    }while(opcion > 2 && opcion < 1);
}

void calificaciones()
{

    //Esta funcion  se esta desempeñando aparte y sera una de las ultimas, se creo la estructura
    //Jugardor (jgdr), para ir almancenando todos los datos del jugador si este lo desea en un file.
    int opcion;
    fflush(stdin);
    limpiar();
    do{
        printf("\t\t\t---------------------------------\n"
               "\t\t\t PUNTUACIONES DE LOS JUGADORES\n"
               "\t\t\t---------------------------------\n\n\n"
               "\t NOMBRE DEL JUGADOR ----------PUNTUACION-----------TIEMPO TARDADO");
        mostrar_archivo();
        printf("\n\n\t 1-VOLVER AL MENU PRINCIPAL                               2-SALIR DEL JUEGO"
               "\n -> ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                fflush(stdin);
                menu_principal();
                break;
            case 2:
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        system("pause");
        limpiar();

    }while(opcion > 2 && opcion < 1);


}
void configuraciones()
{
    int color,opcion,c;
    printf("Configuraciones de pantalla\n");
    do{
        limpiar();
        printf("Combinaciones de colores: \n"
               " _______________________________________\n"
               "|  Opcion ----- Pantalla-----  Texto    |\n"
               "|_______________________________________|\n"
               "|    1   ------- Blanco ----  Agua      |\n"
               "|    2   ------- Azul  -----  Amarillo  |\n"
               "|    3   ------- Rojo  -----  Negro     |\n"
               "|    4   ------- Gris  -----  Azul      |\n"
               "|    5   -----  Purpura ----  Verde     |\n"
               "|_______________________________________|\n\n"
               "-> ");
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
                break;
            case 5:
                fflush(stdin);
                system("color D2");
                break;

            default:
                printf("No existe esa combinacion");

        }
        printf("Desea otro color? \n"
               "1-Si       2- No\n"
               "->");
        scanf("%d",&c);

    }while((color<1 && color>6) || (c == 1));
    do{
        fflush(stdin);
        printf("1- MENU PRINCIPAL                    2- SALIR"
               "\n ->");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                fflush(stdin);
                menu_principal();
                break;
            case 2:
                fflush(stdin);
                salir();
                break;
            default:
                printf("La opcion ingresada no esta contenida en el men%c\n\tPor favor digite una de las mencionadas anteriormente");
                break;
        }
        fflush(stdin);
        system("pause");


    }while(opcion>2 && opcion<1);



}

void juego()
{

    int sizey = 23;
    int sizex = 40;
    int x, y, yi;
    char world[sizey][sizex];
    char player = 'A';
    char playerLaser = '^';
    char enemy = 'W';
    char enemyShielded = 'O';
    char enemyLaser = 'V';
    char explosion = 'X';
    int score = 0;
    int victory = 1;
    int laserReady = 1;
    int enemyReady = 0;
    int choice = 0;
    jugador jdr;

    srand(time(NULL));

    //Crea la matriz de las naves enemigas
    int totalEnemies = 0;
    for (x = 0; x < sizex; x ++)
    {
        for (y = 0; y < sizey; y ++)
        {
            if ((y+1) % 2 == 0 && y < 7 && x > 4 && x < sizex - 5 && x % 2 ==0)
            {
                //Agrega las naves enemigas con solo una vida
                world[y][x] = enemy;
                totalEnemies ++;
            }
            else if ((y+1) % 2 == 0 && y >= 7 && y < 9 && x > 4 && x < sizex - 5 && x % 2 ==0)
            {
                //Agrega los enemigos con dos vidas (un escudo)
                world[y][x] = enemyShielded;
                totalEnemies = totalEnemies + 2;
            }
            else
            {
                //Los espacios en blanco en el que se moveran los enemigos
                world[y][x] = ' ';
            }
        }
    }


    //Crea la nave del jugador
    world[sizey - 1][sizex / 2] = player;
    int i = 1;
    char direction = 'l';
    char keyPress;
    int currentEnemies = totalEnemies;
    int EnemiesDisplay = 0;
    float TiempoTranscurrido = 0;


    while(currentEnemies > 0 && victory && player != ' ')
    {
        int drop = 0;
        //Aumenta la velocidad del enemigo
        int enemySpeed = 1 + 10 * currentEnemies / totalEnemies;
        laserReady ++;

        //Imprime el juego
        system("cls");
        printf("SCORE: %d  ENEMIES KILLED: %d  TIME: %.2f ", score, EnemiesDisplay, TiempoTranscurrido);
        printf("\n");

        for (y = 0; y < sizey; y ++)
        {
            //Imprime el juego
            printf("|");
            for (x = 0; x < sizex; x ++)
            {
                printf("%c",world[y][x]);
            }
            printf("|");
            printf("\n");
        }

        //Efectos de los ataques
        for (x = 0; x < sizex; x ++)
        {
            for (y = sizey-1; y >= 0; y --)
            {
                if (i%2 == 0 && world[y][x] == enemyLaser && (world[y+1][x] != enemy & world[y+1][x] != enemyShielded))
                {
                    //Mueve el lazer del enemigo hacia abajo y se asegura de que solo los enemigos de la linea de abajo puedan atacar
                    world[y+1][x] = enemyLaser;
                    world[y][x] = ' ';
                }
                else if (i%2 == 0 && world[y][x] == enemyLaser && (world[y+1][x] == enemy | world[y+1][x] == enemyShielded))
                {
                    //Borra los lazer enemigos si choca contra otro enemigo
                    world[y][x] = ' ';
                }
            }
        }

        for (x = 0; x < sizex; x ++)
        {
            for (y = 0; y < sizey; y ++)
            {
                //Evalua si el enemigo puede disparar
                if ((i % 5) == 0 && (world[y][x] == enemyShielded | world[y][x] == enemy) && (rand() % 15) > 13 && world[y+1][x] != playerLaser)
                {
                    for (yi = y+1; yi < sizey; yi ++)
                    {
                        //No le permite disparar al enimigo si tiene otra nave enemiga en frente
                        if (world[yi][x] == enemy | world[yi][x] == enemyShielded)
                        {
                            enemyReady = 0;
                            break;
                        }
                        enemyReady = 1;
                    }
                    //Si no tiene naves enemigas entonces dispara
                    if (enemyReady)
                    {
                        world[y+1][x] = enemyLaser;
                    }
                }
                if (world[y][x] == playerLaser && world[y-1][x] == enemy)
                {
                    //Cuando se elemina una nave enimiga muestra una explocion y se suman 50 puntos
                    world[y][x] = ' ';
                    world[y-1][x] = explosion;
                    currentEnemies --;
                    score = score + 50;
                    EnemiesDisplay+= 1;
                    Beep(800,200);
                }
                else if (world[y][x] == playerLaser && world[y-1][x] == enemyShielded)
                {
                    //Cuando se elimina el escudo de la primera linea de enemigos se suma 50 puntos
                    //Y se muestra el enemigo despotregido
                    world[y][x] = ' ';
                    world[y-1][x] = enemy;
                    currentEnemies --;
                    score = score + 50;
                    Beep(600,200);
                }
                else if (world[y][x] == playerLaser && world[y-1][x] == enemyLaser)
                {
                    //Cuando el lazer enimgo choca con el lazer del jugador, el del jugador desaparece
                    world[y][x] = ' ';
                }
                else if (world[y][x] == explosion)
                {
                    //Cuando hay una explocion se elimina la nave enemiga
                    world[y][x] = ' ';
                }
                else if ((i+1) % 2 == 0 && world[y][x] == enemyLaser && world[y+1][x] == player)
                {
                    //Cuando el lazer del enimgo mata al jugar este a perdido
                    world[y+1][x] = explosion;
                    world[y][x] = ' ';
                    victory = 0;
                }
                else if (world[y][x] == playerLaser && world[y-1][x] != enemyLaser)
                {
                    //Cuando el lazer del jugador no se encuentra con nada este sigue moviendose hacia arriba
                    world[y][x] = ' ';
                    world[y-1][x] = playerLaser;
                }
            }
        }

        //Actualiza la direccion a donde se dirigen las naves enemigas
        for (y = 0; y < sizey; y ++)
        {
            if (world[y][0] == enemy)
            {
                //Mueve las naves hacia a la derecha
                direction = 'r';
                drop = 1;
                break;
            }
            if (world[y][sizex-1] == enemy)
            {
                //Mueve las navez hacia a la izquierda
                direction = 'l';
                drop = 1;
                break;
            }
        }

        //Actualiza la posicion de los enemigos
        if (i % enemySpeed == 0)
        {
            if (direction == 'l')
            {
                for (x = 0; x < sizex - 1; x ++)
                {
                    for (y = 0; y < sizey; y ++)
                    {
                        if (drop && (world[y-1][x+1] == enemy || world[y-1][x+1] == enemyShielded))
                        {
                            //Los enemigos bajan y se mueven a la direccion mostrada (izquierda)
                            world[y][x] = world[y-1][x+1];
                            world[y-1][x+1] = ' ';
                        }
                        else if (!drop && (world[y][x+1] == enemy || world[y][x+1] == enemyShielded))
                        {
                            //Solo se mueve a la direccion indicada (izquierda)
                            world[y][x] = world[y][x+1];
                            world[y][x+1] = ' ';
                        }
                    }
                }
            }
            else
            {
                for (x = sizex; x > 0; x --)
                {
                    for (y = 0; y < sizey; y ++)
                    {
                        if (drop && (world[y-1][x-1] == enemy || world[y-1][x-1] == enemyShielded))
                        {
                            //Los enemigos bajan y se mueven a la direccion mostrada (derecha)
                            world[y][x] = world[y-1][x-1];
                            world[y-1][x-1] = ' ';
                        }
                        else if (!drop && (world[y][x-1] == enemy || world[y][x-1] == enemyShielded))
                        {
                            //Solo se mueve a la direccion indicada (derecha)
                            world[y][x] = world[y][x-1];
                            world[y][x-1] = ' ';
                        }
                    }
                }
            }
            for (x = 0; x < sizex; x ++)
            {
                //Actualiza la condicion de victoria
                if (world[sizey - 1][x] == enemy)
                {
                    victory = 0;
                }
            }
        }


        //Controles del jugador
        if(kbhit())
        {
            keyPress = getch();
        }
        else
        {
            keyPress = ' ';
        }
        if (keyPress == 'a')
        {
            //El jugador se mueve a la izquierda
            for (x = 0; x < sizex; x = x+1)
            {
                if ( world[sizey-1][x+1] == player)
                {
                    world[sizey-1][x] = player;
                    world[sizey-1][x+1] = ' ';
                }
            }
        }

        if (keyPress == 'd')
        {
            //El jugador de mueve a la derecha
            for (x = sizex - 1; x > 0; x = x-1)
            {
                if ( world[sizey-1][x-1] == player)
                {
                    world[sizey-1][x] = player;
                    world[sizey-1][x-1] = ' ';
                }
            }
        }
        if (keyPress == 'm' && laserReady > 2)
        {
            //El jugador dispara su lazer
            for (x = 0; x < sizex; x = x+1)
            {
                if ( world[sizey-1][x] == player)
                {
                    world[sizey - 2][x] = playerLaser;
                    laserReady = 0;
                    Beep(500,200);
                }
            }
        }


        i ++;
        TiempoTranscurrido= TiempoTranscurrido + 0.31;
        Sleep(50);
    }

    Final_Juego(victory, score, EnemiesDisplay, TiempoTranscurrido, choice, jdr);

    nuevo(jdr,TiempoTranscurrido,score);


}

void nuevo(jugador jgdr, float TiempoTranscurrido, int score)
{
    printf("Su nombre de usuario: ");
    scanf("%s",&jgdr.nombre);
    jgdr.puntuacion = score;
    jgdr.tiempo = TiempoTranscurrido;

}

int obtener_archivo(jugador jdr)
{
    FILE * f;
    f = fopen("calificaciones.txt", "a");
    if(f != NULL){
        fprintf(f,"\n\t%s -------- %d -------- %.2f",jdr.nombre,jdr.puntuacion,jdr.tiempo);
        fclose(f);

    }else{
        perror("Error en la creacion");
        return 1;
    }

}

int mostrar_archivo()
{
    FILE * f;
    f = fopen("calificaciones.txt","r");
    int c=0;
    if(f== NULL){
        perror("\n\tError en la apertura del archivo");
    }
    fseek(f,0,SEEK_END);
    int n_elementos = ftell(f);
    rewind(f);
    char * cadena = calloc(sizeof(char),n_elementos);

    if (cadena == NULL){
        perror("\n\tError en reserva la memoria");
        return 1;
    }
    int n_leidos = fread(cadena,sizeof(char),n_elementos,f);
    if (n_leidos != n_elementos){
        perror("\n\tError leyendo el archivo");
        return 1;
    }

    printf("%s",cadena);
    free(cadena);
    fclose(f);

}

void Final_Juego(int victory, int score, int EnemiesDisplay, float TiempoTranscurrido, int choice, jugador jdr)
{
    if(victory == 0)
    {
        system("cls");
        Beep(700,300);
        Beep(600,300);
        Beep(500,300);
        Beep(400,500);
        printf("\t o                                                \n"
               "\t \_/\o    GAME OVER                               \n"
               "\t( Oo)                    \|/  Los aliens han      \n"
               "\t(_=-)  .===O-  ~~~~~~ -O-  invadido la tierra     \n"
               "\t/   \_/U'                /|\                      \n"
               "\t||  |_/    High Score %d                          \n"
               "\t\\  |      Aliens Eliminados %d                   \n"
               "\t{K ||      Tiempo total %.2f segundos             \n"
               "\t | ||                                             \n"
               "\t | PP                Quiere:                      \n"
               "\t | ||         1. Guardar mi score                 \n"
               "\t (--\\     2. Salir    3. Volver al Menu          \n"
               "\t                                                  \n",score, EnemiesDisplay, TiempoTranscurrido);
        scanf("%d",&choice);
        if(choice == 1)
        {
            nuevo(jdr,TiempoTranscurrido,score);
            obtener_archivo(jdr);
        }
        if(choice == 2)
        {
            salir();
        }
        if(choice == 3)
        {
            menu_principal();
        }

    } else if (victory == 1)
    {
        system("cls");
        Beep(400,100);
        Beep(500,100);
        Beep(600,100);
        Beep(700,500);
        Beep(600,100);
        Beep(700,500);
        printf("\t                    HAS GANADO                      \n"
               "\t              LA TIERRA ESTA SALVADA                \n"
               "\t                                                    \n"
               "\t                High Score %d                       \n"
               "\t            Aliens Eliminados %d                    \n"
               "\t               Tiempo total %.2f                    \n"
               "\t                                                    \n"
               "\t                                .''.                \n"
               "\t      .''.             *''*    :_\/_:     .         \n"
               "\t     :_\/_:   .    .:.*_\/_*   : /\ :  .'.:.'.      \n"
               "\t .''.: /\ : _\(/_  ':'* /\ *  : '..'.  -=:o:=-      \n"
               "\t:_\/_:'.:::. /)\*''*  .|.* '.\'/.'_\(/_'.':'.'      \n"
               "\t: /\ : :::::  '*_\/_* | |  -= o =- /)\    '  *      \n"
               "\t '..'  ':::'   * /\ * |'|  .'/.\'.  '._____         \n"
               "\t     *        __*..* |  |     :      |.   |' .----| \n"
               "\t      _*   .-'   '-. |  |     .--'|  ||   | _|    | \n"
               "\t   .-'|  _.|  |    ||   '-__  |   |  |    ||      | \n"
               "\t   |' | |.    |    ||       | |   |  |    ||      | \n"
               "\t   |  '-'     '    ""       '-'   '-.'    '`      | \n"
               "\t            1. Guardar puntuacion                   \n"
               "\t            2. Nivel Extra                          \n"
               "\t            3. Volver al Menu                       \n"
               "\t            4. Salir                                \n" ,score, EnemiesDisplay, TiempoTranscurrido);

        scanf("%d",&choice);
        if(choice == 1)
        {
            nuevo(jdr,TiempoTranscurrido,score);
            obtener_archivo(jdr);
        }
        if(choice == 2)
        {
            ExtraLevel( score, TiempoTranscurrido, EnemiesDisplay, jdr);
        }
        if(choice == 3)
        {
            menu_principal();
        }
        if(choice == 4)
        {
            salir();
        }

    } else if(victory == 2)
    {
        system("cls");
        Beep(700,300);
        Beep(600,300);
        Beep(500,300);
        Beep(400,500);
        printf("\t                    HAS LLEGADO                     \n"
               "\t                     AL FINAL                       \n"
               "\t                                                    \n"
               "\t                High Score %d                       \n"
               "\t            Aliens Eliminados %d                    \n"
               "\t               Tiempo total %.2f                    \n"
               "\t                                                    \n"
               "\t            1. Guardar puntuacion                   \n"
               "\t            2. Volver al Menu                       \n"
               "\t            3. Salir                                \n" ,score, EnemiesDisplay, TiempoTranscurrido);
        scanf("%d",&choice);
        if(choice == 1)
        {
            nuevo(jdr,TiempoTranscurrido,score);
            obtener_archivo(jdr);
        }
        if(choice == 2)
        {
            menu_principal();
        }
        if(choice == 3)
        {
            salir();
        }

    }
}

void ExtraLevel(int extrascore, float extratime, int extraenemies, jugador jdr)
{
    int sizey = 23;
    int sizex = 40;
    int x, y, yi;
    char world[sizey][sizex];
    char player = 'A';
    char playerLaser = '^';
    char enemy = 'W';
    char enemyShielded = 'O';
    char enemyLaser = 'V';
    char explosion = 'X';
    int score = extrascore;
    int victory = 1;
    int laserReady = 1;
    int enemyReady = 0;
    int choice = 0;

    srand(time(NULL));

    printf(" Preciona cualquier tecla para comenzar ");
    getch();

    //Crea la matriz de las naves enemigas
    int totalEnemies = 0;
    for (x = 0; x < sizex; x ++)
    {
        for (y = 0; y < sizey; y ++)
        {
            if ((y+1) % 2 == 0 && y < 7 && x > 4 && x < sizex - 5 && x % 2 ==0)
            {
                //Agrega los enemigos con dos vidas (un escudo)
                world[y][x] = enemyShielded;
                totalEnemies = totalEnemies + 2;
            }
            else
            {
                //Los espacios en blanco en el que se moveran los enemigos
                world[y][x] = ' ';
            }
        }
    }


    //Crea la nave del jugador
    world[sizey - 1][sizex / 2] = player;
    int i = 1;
    char direction = 'l';
    char keyPress;
    int currentEnemies = totalEnemies;
    int EnemiesDisplay = extraenemies;
    float TiempoTranscurrido = extratime;


    while(currentEnemies > 0 && victory && player == 'A')
    {
        int drop = 0;
        //Aumenta la velocidad del enemigo
        int enemySpeed = 1 + 10 * currentEnemies / totalEnemies;
        laserReady ++;

        //Imprime el juego
        system("cls");
        printf("SCORE: %d  ENEMIES KILLED: %d  TIME: %.2f ", score, EnemiesDisplay, TiempoTranscurrido);
        printf("\n");

        for (y = 0; y < sizey; y ++)
        {
            //Imprime el juego
            printf("|");
            for (x = 0; x < sizex; x ++)
            {
                printf("%c",world[y][x]);
            }
            printf("|");
            printf("\n");
        }

        //Efectos de los ataques
        for (x = 0; x < sizex; x ++)
        {
            for (y = sizey-1; y >= 0; y --)
            {
                if (i%2 == 0 && world[y][x] == enemyLaser && (world[y+1][x] != enemy & world[y+1][x] != enemyShielded))
                {
                    //Mueve el lazer del enemigo hacia abajo y se asegura de que solo los enemigos de la linea de abajo puedan atacar
                    world[y+1][x] = enemyLaser;
                    world[y][x] = ' ';
                }
                else if (i%2 == 0 && world[y][x] == enemyLaser && (world[y+1][x] == enemy | world[y+1][x] == enemyShielded))
                {
                    //Borra los lazer enemigos si choca contra otro enemigo
                    world[y][x] = ' ';
                }
            }
        }

        for (x = 0; x < sizex; x ++)
        {
            for (y = 0; y < sizey; y ++)
            {
                //Evalua si el enemigo puede disparar
                if ((i % 5) == 0 && (world[y][x] == enemyShielded | world[y][x] == enemy) && (rand() % 15) > 13 && world[y+1][x] != playerLaser)
                {
                    for (yi = y+1; yi < sizey; yi ++)
                    {
                        //No le permite disparar al enimigo si tiene otra nave enemiga en frente
                        if (world[yi][x] == enemy | world[yi][x] == enemyShielded)
                        {
                            enemyReady = 0;
                            break;
                        }
                        enemyReady = 1;
                    }
                    //Si no tiene naves enemigas entonces dispara
                    if (enemyReady)
                    {
                        world[y+1][x] = enemyLaser;
                    }
                }
                if (world[y][x] == playerLaser && world[y-1][x] == enemy)
                {
                    //Cuando se elemina una nave enimiga muestra una explocion y se suman 50 puntos
                    world[y][x] = ' ';
                    world[y-1][x] = explosion;
                    currentEnemies --;
                    score = score + 50;
                    EnemiesDisplay+= 1;
                    Beep(800,200);
                }
                else if (world[y][x] == playerLaser && world[y-1][x] == enemyShielded)
                {
                    //Cuando se elimina el escudo de la primera linea de enemigos se suma 50 puntos
                    //Y se muestra el enemigo despotregido
                    world[y][x] = ' ';
                    world[y-1][x] = enemy;
                    currentEnemies --;
                    score = score + 50;
                    Beep(600,200);
                }
                else if (world[y][x] == playerLaser && world[y-1][x] == enemyLaser)
                {
                    //Cuando el lazer enimgo choca con el lazer del jugador, el del jugador desaparece
                    world[y][x] = ' ';
                }
                else if (world[y][x] == explosion)
                {
                    //Cuando hay una explocion se elimina la nave enemiga
                    world[y][x] = ' ';
                }
                else if ((i+1) % 2 == 0 && world[y][x] == enemyLaser && world[y+1][x] == player)
                {
                    //Cuando el lazer del enimgo mata al jugar este a perdido
                    world[y+1][x] = explosion;
                    world[y][x] = ' ';
                    victory = 0;
                }
                else if (world[y][x] == playerLaser && world[y-1][x] != enemyLaser)
                {
                    //Cuando el lazer del jugador no se encuentra con nada este sigue moviendose hacia arriba
                    world[y][x] = ' ';
                    world[y-1][x] = playerLaser;
                }
            }
        }

        //Actualiza la direccion a donde se dirigen las naves enemigas
        for (y = 0; y < sizey; y ++)
        {
            if (world[y][0] == enemy)
            {
                //Mueve las naves hacia a la derecha
                direction = 'r';
                drop = 1;
                break;
            }
            if (world[y][sizex-1] == enemy)
            {
                //Mueve las navez hacia a la izquierda
                direction = 'l';
                drop = 1;
                break;
            }
        }

        //Actualiza la posicion de los enemigos
        if (i % enemySpeed == 0)
        {
            if (direction == 'l')
            {
                for (x = 0; x < sizex - 1; x ++)
                {
                    for (y = 0; y < sizey; y ++)
                    {
                        if (drop && (world[y-1][x+1] == enemy || world[y-1][x+1] == enemyShielded))
                        {
                            //Los enemigos bajan y se mueven a la direccion mostrada (izquierda)
                            world[y][x] = world[y-1][x+1];
                            world[y-1][x+1] = ' ';
                        }
                        else if (!drop && (world[y][x+1] == enemy || world[y][x+1] == enemyShielded))
                        {
                            //Solo se mueve a la direccion indicada (izquierda)
                            world[y][x] = world[y][x+1];
                            world[y][x+1] = ' ';
                        }
                    }
                }
            }
            else
            {
                for (x = sizex; x > 0; x --)
                {
                    for (y = 0; y < sizey; y ++)
                    {
                        if (drop && (world[y-1][x-1] == enemy || world[y-1][x-1] == enemyShielded))
                        {
                            //Los enemigos bajan y se mueven a la direccion mostrada (derecha)
                            world[y][x] = world[y-1][x-1];
                            world[y-1][x-1] = ' ';
                        }
                        else if (!drop && (world[y][x-1] == enemy || world[y][x-1] == enemyShielded))
                        {
                            //Solo se mueve a la direccion indicada (derecha)
                            world[y][x] = world[y][x-1];
                            world[y][x-1] = ' ';
                        }
                    }
                }
            }
            for (x = 0; x < sizex; x ++)
            {
                //Actualiza la condicion de victoria
                if (world[sizey - 1][x] == enemy)
                {
                    victory = 0;
                }
            }
        }


        //Controles del jugador
        if(kbhit())
        {
            keyPress = getch();
        }
        else
        {
            keyPress = ' ';
        }
        if (keyPress == 'a')
        {
            //El jugador se mueve a la izquierda
            for (x = 0; x < sizex; x = x+1)
            {
                if ( world[sizey-1][x+1] == player)
                {
                    world[sizey-1][x] = player;
                    world[sizey-1][x+1] = ' ';
                }
            }
        }

        if (keyPress == 'd')
        {
            //El jugador de mueve a la derecha
            for (x = sizex - 1; x > 0; x = x-1)
            {
                if ( world[sizey-1][x-1] == player)
                {
                    world[sizey-1][x] = player;
                    world[sizey-1][x-1] = ' ';
                }
            }
        }
        if (keyPress == 'm' && laserReady > 2)
        {
            //El jugador dispara su lazer
            for (x = 0; x < sizex; x = x+1)
            {
                if ( world[sizey-1][x] == player)
                {
                    world[sizey - 2][x] = playerLaser;
                    laserReady = 0;
                    Beep(500,200);
                }
            }
        }


        i ++;
        TiempoTranscurrido= TiempoTranscurrido + 0.31;
        Sleep(50);
    }
    victory = 2;
    Final_Juego( victory, score, EnemiesDisplay, TiempoTranscurrido, choice, jdr);
}


