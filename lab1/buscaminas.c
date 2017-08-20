#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef enum {FALSE=0, TRUE=1} bool;

#define SINBOMBA 0
#define BOMBA -3
#define FLAG -4
#define MOVE -5


void verificarJugada(int ** tablero,int ** jugadas,int filas, int columnas,bool perder){
    printf("entre aca\n");
    if ( tablero[filas][columnas]== BOMBA && jugadas[filas][columnas]== MOVE ) {
        printf("ñaca ñaca\n");
        perder = TRUE;
    }

}

void insertarMinas (int ** tablero,int filas, int columnas, int cantMinas) {
    int posX,posY;
    int i=0;
    srand(time(NULL));
    while (i<cantMinas) {
        posX = rand() % filas;
        posY = rand() % columnas;
        tablero[posX][posY] = BOMBA;
        i++;
    }
}

void crearArchivo (int ** tablero,int filas, int columnas) {
    FILE *fp;
    fp = fopen ( "solucion.out", "w" );
    int i,j;
    for (i = 0; i < columnas; i++) {
        for (j = 0; j < filas; j++) {
            fprintf(fp, "%3i", tablero[i][j]);
        }
        fprintf(fp, "\n");
    }
 	fclose ( fp );
}

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
                printf("%3s","-");
            }else {
                printf("%3d", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

int verificarMargen(int i, int j, int filas, int columnas){
    if (i<0 || j< 0 || i>= filas || j>= columnas) {
        return 0;
    }else {
        return 1;
    }
}

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

void liberarMemoria (int ** matriz, int filas) {
    int i;
    for(i = 0; i < filas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void verificarFinal (int ** tablero,int filas, int columnas,bool ganar) {
    if ( ganar==TRUE ) {
        printf("Usted ha ganado!\n");
    }else {
        printf("Usted ha perdido!\n");
        printf("Solucion:\n");
        printMatriz(tablero,filas,columnas);
    }
}

void iniciar () {
    // int filas, columnas,cantMinas;
    //
    // printf("Ingrese cantidad de filas y columnas:");
    // scanf("%i  %i",&filas,&columnas);
    //
    // printf("Ingrese la cantidad de minas:");
    // scanf("%i",&cantMinas);

    int filas = 8, columnas = 8, cantMinas = 10;

    int filaIngresada, columnaIngresada;
    char jugada;
    int contadorJugadas=0;
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
        printf("Ingrese Jugada: ");
        scanf("%i  %i %c",&filaIngresada,&columnaIngresada,&jugada);
        if (contadorJugadas==0) {
            insertarMinas(tablero, filas, columnas,cantMinas);
            insertarNumeros(tablero, filas, columnas);
            crearArchivo(tablero, filas, columnas);
        }
        if (tolower(jugada)== 'o') {
            jugadas[filaIngresada-1][columnaIngresada-1] = MOVE;
        }else {
            jugadas[filaIngresada-1][columnaIngresada-1] = FLAG ;
        }
        printf("\n");
        printMatriz(tablero, filas, columnas);
        printf("\n");
        printMatriz(jugadas, filas, columnas);
        printf("\n");
        contadorJugadas += 1;
        verificarJugada(tablero,jugadas,filaIngresada-1,columnaIngresada-1,perder);
        printf("%i\n",perder);
    }
    verificarFinal(tablero,filas,columnas,ganar);
    liberarMemoria(tablero,filas);
    liberarMemoria(jugadas,filas);
}

int main() {
    iniciar();
    return 0;
}
