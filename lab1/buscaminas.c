#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef enum {FALSE=0, TRUE=1} bool;

#define SINBOMBA 0
#define BOMBA -3
#define FLAG -4
#define MOVE -5

bool verificarDerrota(int ** tablero,int ** jugadas,int filas, int columnas){
    if ( tablero[filas][columnas]== BOMBA && jugadas[filas][columnas]== MOVE ) {
        return TRUE;
    }
    return FALSE;
}

bool verificarVictoria (int filas, int columnas,int cantMinas, int cantJugadas){
    if (cantJugadas == ((filas*columnas)-cantMinas)) {
        return TRUE;
    }
    return FALSE;
}

void insertarMinas (int ** tablero,int filas, int columnas, int cantMinas,int x,int y) {
    int posX,posY;
    int i=0;
    printf("cantminas: %i\n",cantMinas);
    srand(time(NULL));
    while (i<cantMinas) {
        posX = rand() % filas;
        posY = rand() % columnas;
        if ((posX != x && posY != y) && tablero[posX][posY] != BOMBA) {
            tablero[posX][posY] = BOMBA;
        }else{
            i--;
        }
        i++;
    }
}

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
                if (matriz[i][j] == 0) {
                    printf("%3s","-");
                }else if(matriz[i][j] == -3){
                    printf("%3s","B");
                }else if(matriz[i][j] == -4){
                    printf("%3s","X");
                }else if(matriz[i][j] == -5){
                    printf("%3s","O");
                }else{
                    printf("%3d", matriz[i][j]);
                }
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
        printf("\n");
        printMatriz(tablero, filas, columnas);
        printf("\nUSTED HA GANADO!\n\n");


    }else {

        printf("\nUSTED HA PERDIDO!\n\nSOLUCION :\n\n");
        printMatriz(tablero,filas,columnas);
        printf("\n");
    }
}

void expandirMatriz (int ** tablero,int ** jugadas,int filas, int columnas, int posX,int posY) {
    int i,j;
    for ( i = 0; i < filas; i++ ) {
        for ( j = 0; j < columnas; j++) {
            if (tablero[i][j] == SINBOMBA) {
                if (verificarMargen(i-1,j,filas,columnas)==1 && tablero[i-1][j]==BOMBA) {
                    tablero[i][j]+=1;
                }
                if (verificarMargen(i+1,j,filas,columnas)==1 && tablero[i+1][j]==BOMBA) {
                    tablero[i][j]+=1;
                }
                if (verificarMargen(i,j+1,filas,columnas)==1 && tablero[i][j+1]==BOMBA) {
                    tablero[i][j]+=1;
                }
                if (verificarMargen(i,j-1,filas,columnas)==1 && tablero[i][j-1]==BOMBA) {
                    tablero[i][j]+=1;
                }
                if (verificarMargen(i-1,j-1,filas,columnas)==1 && tablero[i-1][j-1]==BOMBA) {
                    tablero[i][j]+=1;
                }
                if (verificarMargen(i+1,j+1,filas,columnas)==1 && tablero[i+1][j+1]==BOMBA) {
                    tablero[i][j]+=1;
                }
                if (verificarMargen(i+1,j-1,filas,columnas)==1 && tablero[i+1][j-1]==BOMBA) {
                    tablero[i][j]+=1;
                }
                if (verificarMargen(i-1,j+1,filas,columnas)==1 && tablero[i-1][j+1]==BOMBA) {
                    tablero[i][j]+=1;
                }
            }
        }
    }


}
void iniciar () {
    int filas, columnas,cantMinas;
    printf("\n####################################\n");
    printf("#            BUSCAMINAS            #\n");
    printf("####################################\n");
    printf("\nIngrese cantidad de filas y columnas:");
    scanf("%i  %i",&filas,&columnas);
    printf("\nIngrese la cantidad de minas:");
    scanf("%i",&cantMinas);
    printf("\n");

    //int filas = 10, columnas = 10, cantMinas = 10;

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

        if (tolower(jugada)== 'o') {
            jugadas[filaIngresada-1][columnaIngresada-1] = MOVE;
        }else {
            jugadas[filaIngresada-1][columnaIngresada-1] = FLAG ;
        }


        if (contadorJugadas==0) {
            insertarMinas(tablero, filas, columnas,cantMinas,filaIngresada,columnaIngresada);
            insertarNumeros(tablero, filas, columnas);
            crearArchivo(tablero, filas, columnas);
        }

        if (jugada != 'x') {
            contadorJugadas += 1;
        }

        if (verificarDerrota(tablero,jugadas,filaIngresada-1,columnaIngresada-1)== TRUE) {
            perder= TRUE;
        }else if(verificarVictoria(filas,columnas,cantMinas,contadorJugadas)== TRUE){
            ganar= TRUE;
        }
        else{
            printf("\n");
            printMatriz(tablero, filas, columnas);
            printf("\n");
            printMatriz(jugadas, filas, columnas);
            printf("\n");
        }
    }
    verificarFinal(tablero,filas,columnas,ganar);
    liberarMemoria(tablero,filas);
    liberarMemoria(jugadas,filas);
}

int main() {
    iniciar();
    return 0;
}

// arreglar que no se inicie una bomba en la primera jugadas(listo)
// arreglar el random (listo)
// expandir mapa
//victoria
