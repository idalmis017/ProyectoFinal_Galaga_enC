#include "juego.h"

void Game_Play()
{
    int sizey = 23;
    int sizex = 40;
    int x, y, yi;
    char world[sizey][sizex];
    char player = 'A';
    char playerLaser = '^';
    char enemy = 'M';
    char enemyShielded = 'O';
    char enemyLaser = 'U';
    char explosion = 'X';
    int score = 0;
    int victory = 1;
    int laserReady = 1;
    int enemyReady = 0;

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



    while(currentEnemies > 0 && victory)
    {
        int drop = 0;
        int enemySpeed = 1 + 10 * currentEnemies / totalEnemies;
        laserReady ++;

        //Imprime el juego
        system("cls");
        printf("     SCORE:    %d", score);
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
                }
                else if (world[y][x] == playerLaser && world[y-1][x] == enemyShielded)
                {
                    //Cuando se elimina el escudo de la primera linea de enemigos se suma 50 puntos
                    //Y se muestra el enemigo despotregido
                    world[y][x] = ' ';
                    world[y-1][x] = enemy;
                    currentEnemies --;
                    score = score + 50;
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
                }
            }
        }

        i ++;
        Sleep(50);
    }

}
