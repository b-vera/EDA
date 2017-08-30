#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef enum {FALSE=0, TRUE=1} bool;

#define SINBOMBA 0
#define BOMBA -3
#define FLAG -4
#define MOVE -5

//funcion que retorna true si se ha perdido el juego y false en el caso contrario
bool verificarDerrota(int ** tablero,int ** jugadas,int filas, int columnas){
    if ( tablero[filas][columnas]== BOMBA && jugadas[filas][columnas]== MOVE ) {
        return TRUE;
    }
    return FALSE;
}

//funcion que retorna true si se ha ganado el juego y false en el caso contrario
bool verificarVictoria (int ** jugadas,int filas, int columnas,int cantMinas){
    int i,j,total;
    int contador=0;
    total = (filas*columnas)-cantMinas;
    for ( i = 0; i < filas; i++) {
        for ( j = 0; j < columnas; j++) {
            if (jugadas[i][j]==SINBOMBA) {
                contador++;
            }
        }
    }
    if (contador==cantMinas) {
        return TRUE;
    }
    return FALSE;
}

//funcion encargada de posicionar las bombas en el tablero segun la cantidad indicada por el usuario
void insertarMinas (int ** tablero,int filas, int columnas, int cantMinas,int x,int y) {
    int posX,posY;
    int i=0;
    srand(time(NULL));
    while (i<cantMinas) {
        posX = rand() % filas;
        posY = rand() % columnas;
        printf("usuario == x %d y %d\n",x,y);
        printf("px %d py %d\n",posX,posY);
        if ((posX != x && posY != y) || (tablero[posX][posY] != BOMBA)) {
            tablero[posX][posY] = BOMBA;
            i++;
        }
    }
}

//funcion que crea un archivo de salida con la solucion en el
void crearArchivo (int ** tablero,int filas, int columnas) {
    FILE *fp;
    fp = fopen ( "solucion.out", "w" );
    int i,j;
    for (i = 0; i < columnas; i++) {
        for (j = 0; j < filas; j++) {
            if (tablero[i][j] == 0) {
                fprintf(fp,"%3s","-");
            }else if(tablero[i][j] == -3){
                fprintf(fp,"%3s","B");
            }else if(tablero[i][j] == -4){
                fprintf(fp,"%3s","X");
            }else if(tablero[i][j] == -5){
                fprintf(fp,"%3s","O");
            }else{
                fprintf(fp, "%3i", tablero[i][j]);
            }

        }
        fprintf(fp, "\n");
    }
 	fclose ( fp );
}

//funcion que imprime la matriz de datos deseada con formato de tablero
void printMatriz (int ** matriz, int filas, int columnas) {

    int i,j;
    for(i = -2; i < filas; i++){
        //columnas
        if (i == -2 || i ==-1) {
            printf("      ");
        } else {
            printf("%3i",i+1);
            printf("%3s","|" );
        }
        for(j = 0; j < columnas; j++){
            //filas
            if (i == -2){
                printf("%3i",j+1);
            }else if (i == -1) {
                printf("%3s","=");
            }else {
                if (matriz[i][j] == SINBOMBA) {
                    printf("%3s","-");
                }else if(matriz[i][j] == BOMBA){
                    printf("%3s","B");
                }else if(matriz[i][j] == FLAG){
                    printf("%3s","X");
                }else if(matriz[i][j] == MOVE){
                    printf("%3s","O");
                }else{
                    printf("%3d", matriz[i][j]);
                }
            }
        }
        printf("\n");
    }
}

//funcion filtro para verificar que la posicion a revisar no este fuera de los margenes
int verificarMargen(int i, int j, int filas, int columnas){
    if (i<0 || j< 0 || i>= filas || j>= columnas) {
        return 0;
    }else {
        return 1;
    }
}

//funcion que inserta los valores alrededor de las bombas
void insertarNumeros (int ** matriz, int filas, int columnas) {
    int i,j;
    for ( i = 0; i < filas; i++ ) {
        for ( j = 0; j < columnas; j++) {
            if (matriz[i][j] != BOMBA) {
                if (verificarMargen(i-1,j,filas,columnas)==1 && matriz[i-1][j]==BOMBA) {
                    matriz[i][j]+=1;
                }
                if (verificarMargen(i+1,j,filas,columnas)==1 && matriz[i+1][j]==BOMBA) {
                    matriz[i][j]+=1;
                }
                if (verificarMargen(i,j+1,filas,columnas)==1 && matriz[i][j+1]==BOMBA) {
                    matriz[i][j]+=1;
                }
                if (verificarMargen(i,j-1,filas,columnas)==1 && matriz[i][j-1]==BOMBA) {
                    matriz[i][j]+=1;
                }
                if (verificarMargen(i-1,j-1,filas,columnas)==1 && matriz[i-1][j-1]==BOMBA) {
                    matriz[i][j]+=1;
                }
                if (verificarMargen(i+1,j+1,filas,columnas)==1 && matriz[i+1][j+1]==BOMBA) {
                    matriz[i][j]+=1;
                }
                if (verificarMargen(i+1,j-1,filas,columnas)==1 && matriz[i+1][j-1]==BOMBA) {
                    matriz[i][j]+=1;
                }
                if (verificarMargen(i-1,j+1,filas,columnas)==1 && matriz[i-1][j+1]==BOMBA) {
                    matriz[i][j]+=1;
                }
            }
        }
    }
}

//funcion recursiva encargada de expandir la matriz cuando se selecciona casilla vacia
void expandirMatriz (int ** tablero,int ** jugadas,int filas, int columnas, int posX,int posY) {

    //printf("entra posicion:(%i,%i)\n",posX+1,posY+1);
    if (tablero[posX][posY] == BOMBA) {
        return;
    }
    if (tablero[posX][posY] != SINBOMBA && jugadas[posX][posY]!=tablero[posX][posY]) {
        //printf("Entre\n");
        jugadas[posX][posY]=tablero[posX][posY];
        expandirMatriz(tablero,jugadas,filas,columnas,posX,posY);
    }
    //arriba
    if (verificarMargen(posX-1,posY,filas,columnas)==1 && tablero[posX-1][posY] == SINBOMBA && jugadas[posX-1][posY] != MOVE) {
        //printf("arriba\n");
        jugadas[posX-1][posY]=MOVE;
        expandirMatriz(tablero,jugadas,filas,columnas,posX-1,posY);
    }
    //arriba derecha
    if (verificarMargen(posX-1,posY+1,filas,columnas)==1 && tablero[posX-1][posY+1] == SINBOMBA && jugadas[posX-1][posY+1] != MOVE) {
        //printf("arriba derecha\n");
        jugadas[posX-1][posY+1]=MOVE;
        expandirMatriz(tablero,jugadas,filas,columnas,posX-1,posY+1);
    }
    //derecha
    if (verificarMargen(posX,posY+1,filas,columnas)==1 && tablero[posX][posY+1] == SINBOMBA && jugadas[posX][posY+1] != MOVE) {
        //printf("derecha\n");
        jugadas[posX][posY+1]=MOVE;
        expandirMatriz(tablero,jugadas,filas,columnas,posX,posY+1);
    }
    //abajo derecha
    if (verificarMargen(posX+1,posY+1,filas,columnas)==1 && tablero[posX+1][posY+1] == SINBOMBA && jugadas[posX+1][posY+1] != MOVE) {
        //printf("abajo derecha\n");
        jugadas[posX+1][posY+1]=MOVE;
        expandirMatriz(tablero,jugadas,filas,columnas,posX+1,posY+1);
    }
    //abajo
    if (verificarMargen(posX+1,posY,filas,columnas)==1 && tablero[posX+1][posY] == SINBOMBA && jugadas[posX+1][posY] != MOVE) {
        //printf("abajo\n");
        jugadas[posX+1][posY]=MOVE;
        expandirMatriz(tablero,jugadas,filas,columnas,posX+1,posY);
    }
    //abajo izquierda
    if (verificarMargen(posX+1,posY-1,filas,columnas)==1 && tablero[posX+1][posY-1] == SINBOMBA && jugadas[posX+1][posY-1] != MOVE) {
        //printf("abajo izquierda\n");
        jugadas[posX+1][posY-1]=MOVE;
        expandirMatriz(tablero,jugadas,filas,columnas,posX+1,posY-1);
    }
    //izquierda
    if (verificarMargen(posX,posY-1,filas,columnas)==1 && tablero[posX][posY-1] == SINBOMBA && jugadas[posX][posY-1] != MOVE) {
        //printf("izquierda\n");
        jugadas[posX][posY-1]=MOVE;
        expandirMatriz(tablero,jugadas,filas,columnas,posX,posY-1);
    }
    //arriba izquierda
    if (verificarMargen(posX-1,posY-1,filas,columnas)==1 && tablero[posX-1][posY-1] == SINBOMBA && jugadas[posX-1][posY-1] != MOVE) {
        //printf("arriba izquierda\n");
        jugadas[posX-1][posY-1]=MOVE;
        expandirMatriz(tablero,jugadas,filas,columnas,posX-1,posY-1);
    }
}

//funcion que entrega el resultado en caso de una victoria o una derrota
void verificarFinal (int ** tablero,int filas, int columnas,bool ganar) {
    if ( ganar==TRUE ) {
        printf("\n");
        printMatriz(tablero, filas, columnas);
        printf("\n¡USTED HA GANADO!\n\n");
    }else {

        printf("\n¡USTED HA PERDIDO!\n\nSOLUCION :\n\n");
        printMatriz(tablero,filas,columnas);
        printf("\n");
    }
}

//funcion encargada de liberar la memoria para arreglos dinamicos bidimensionales
void liberarMemoria (int ** matriz, int filas) {
    int i;
    for(i = 0; i < filas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

//funcion que realiza las iniciaciones de variables y llama a las otras funciones
void iniciar () {
    int filas, columnas,cantMinas;
    bool verificadorMinas = TRUE;

    printf("\n####################################\n\n");
    printf("             BUSCAMINAS             \n\n");
    printf("####################################\n");
    printf("\nIngrese cantidad de filas y columnas: ");
    scanf("%i  %i",&filas,&columnas);
    do {
        if (verificadorMinas==TRUE) {
            verificadorMinas = FALSE;
            printf("\nIngrese la cantidad de minas: ");
            scanf("%i",&cantMinas);
            printf("\n");
        }else{
            printf("\nIngrese la cantidad de minas nuevamente: ");
            scanf("%i",&cantMinas);
            printf("\n");
        }
    } while(cantMinas>(filas*columnas) || cantMinas==0);

    int filaIngresada,columnaIngresada;
    char jugada;
    int contadorJugadas=0;
    bool jugadaValida = TRUE;
    bool ganar = FALSE;
    bool perder = FALSE;


    //inicializar matrices
    int ** jugadas = (int**)malloc(filas * sizeof(int*));
    int ** tablero = (int**)malloc(filas * sizeof(int*));

    //Se inicializan los valores en matrices tablero y jugadas
    int i,j;
    for(i = 0; i < filas; i++){
        jugadas[i] = (int*)malloc(columnas * sizeof(int));
        tablero[i] = (int*)malloc(columnas * sizeof(int));
        for(j = 0; j < columnas; j++){
            tablero[i][j] = SINBOMBA;
            jugadas[i][j] = FALSE;
        }
    }

    printMatriz(jugadas, filas, columnas);
    printf("\n");

    while (ganar == FALSE && perder == FALSE) {
        //// configurar  verificador
        if (jugadaValida==TRUE) {
            printf("Ingrese Jugada: ");
            scanf("%i  %i %c",&filaIngresada,&columnaIngresada,&jugada);
        }else{
            printf("\nIngrese Jugada Valida: ");
            scanf("%i  %i %c",&filaIngresada,&columnaIngresada,&jugada);
        }
        if(verificarMargen(filaIngresada-1,columnaIngresada-1,filas,columnas)==0){
            jugadaValida = FALSE;
        }else{
            if(jugadas[filaIngresada-1][columnaIngresada-1]==MOVE){
                jugadaValida = FALSE;
            } else if (tolower(jugada)== 'o') {
                jugadas[filaIngresada-1][columnaIngresada-1] = MOVE;
                jugadaValida = TRUE;
            } else if (tolower(jugada)== 'x') {
                jugadas[filaIngresada-1][columnaIngresada-1] = FLAG ;
                jugadaValida = TRUE;
            } else{
                jugadaValida = FALSE;
            }
        }

        /////////////////////////////////////
        if (jugadaValida == TRUE) {
            if (contadorJugadas==0) {
                insertarMinas(tablero, filas, columnas,cantMinas,filaIngresada,columnaIngresada);
                insertarNumeros(tablero, filas, columnas);
                crearArchivo(tablero, filas, columnas);
            }

            if (tolower(jugada) == 'o') {
                expandirMatriz(tablero,jugadas,filas,columnas,filaIngresada-1,columnaIngresada-1);
            }

            if (tolower(jugada) != 'x') {
                contadorJugadas += 1;
            }

            if (verificarDerrota(tablero,jugadas,filaIngresada-1,columnaIngresada-1)== TRUE) {
                perder= TRUE;
            }else if(verificarVictoria(jugadas,filas,columnas,cantMinas)== TRUE){
                ganar= TRUE;
            }
            else{
                printf("\n");
                printMatriz(jugadas, filas, columnas);
                printf("\n");
            }
        }
    }
    verificarFinal(tablero,filas,columnas,ganar);
    liberarMemoria(tablero,filas);
    liberarMemoria(jugadas,filas);
}

//funcion principal del codigo
int main() {
    iniciar();
    return 0;
}
