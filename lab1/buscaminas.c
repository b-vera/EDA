#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define SINBOMBA 0
#define BOMBA -3
#define GANAR FALSE
#define PERDER FALSE


void verificarFinal () {
    if (GANAR==TRUE) {
        printf("Usted ha ganado!\n");
    }else {
        printf("Usted ha perdido!\n");
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
                printf("%i %i\n",i+1,j+1);
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

void iniciar () {
    // int filas, columnas,cantMinas;
    //
    // printf("Ingrese cantidad de filas y columnas:");
    // scanf("%i  %i",&filas,&columnas);
    //
    // printf("Ingrese la cantidad de minas:");
    // scanf("%i",&cantMinas);

    int filas = 8, columnas = 8, cantMinas = 8;
    //ACTIVAR CON EL WHILE DE MAS ABAJO
    //int filaIngresada, columnaIngresada;
    //char jugada;
    //int contadorJugadas=0;

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

    insertarMinas(tablero, filas, columnas,cantMinas);
    printMatriz(tablero, filas, columnas);
    printf("\n");
    insertarNumeros(tablero, filas, columnas);
    printf("\n");
    printMatriz(tablero, filas, columnas);
    crearArchivo(tablero, filas, columnas);
    printf("\n");
    liberarMemoria(tablero,filas);
    liberarMemoria(jugadas,filas);

    /*while (GANAR == FALSE && PERDER == FALSE) {
        printf("Ingrese Jugada: ");
        scanf("%i  %i %c",&filaIngresada,&columnaIngresada,&jugada);
        if (contadorJugadas==0) {
            insertarMinas(jugadas, filas, columnas,cantMinas);

        }
    }*/
    //verificarFinal();
}

int main() {
    iniciar();
    return 0;
}
