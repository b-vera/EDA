#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SINBOMBA -1
#define BOMBA -2
#define GANAR -3
#define PERDER -4


void imprimirTablero(int filas,int columnas) {
    int mayor = 0;
    int cifras = 1;
    if(filas>mayor){
        mayor = filas;
    }else {
        mayor = columnas;
    }
    while(mayor/10>0){
        mayor=mayor/10;
        cifras++;
    }
    for (int x = 0; x <= filas; x++) {
        //imprime columna x
        if (x==0) {
            printf("  ");
        }else{

            printf("%i ",x);
        }
        for (int y = 0; y <= columnas; y++) {
            //imprime filas iniciales
            if ((x==0 && y !=0) || (x==0 && y == 0)) {
                printf("%i ",y);
            }else {
                printf("- ");
            }
        }
        printf("\n");
    }
}
void crearArchivo(int ** tablero,int filas, int columnas) {
    FILE *fp;
    fp = fopen ( "solucion.out", "w" );
    int i,j;
    for (i = 0; i < columnas; i++) {
        for (j = 0; j < filas; j++) {
            fprintf(fp, "%i", tablero[i][j]);
        }
        printf("\n");
    }
 	fclose ( fp );
}

void printMatriz(int ** m, int filas, int columnas){
    int i,j;
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

void iniciar() {
    // int filas, columnas,cantMinas;
    //
    // printf("Ingrese cantidad de filas y columnas:");
    // scanf("%i  %i",&filas,&columnas);
    //
    // printf("Ingrese la cantidad de minas:");
    // scanf("%i",&cantMinas);

    int filas = 10, columnas = 10, cantMinas = 10;

    int ** jugadas = (int**)malloc(filas * sizeof(int*));
    int ** tablero = (int**)malloc(filas * sizeof(int*));

    int i,j;
    for(i = 0; i < filas; i++){
        jugadas[i] = (int*)malloc(columnas * sizeof(int));
        tablero[i] = (int*)malloc(columnas * sizeof(int));
        for(j = 0; j < columnas; j++){
            tablero[i][j] = SINBOMBA;
            jugadas[i][j] = FALSE;
        }
    }
    printMatriz(tablero, filas, columnas);
    printf("\n");
    printMatriz(jugadas, filas, columnas);
    imprimirTablero(filas,columnas);

    crearArchivo(tablero, filas, columnas);

    //
    // ~LIBERAR MEMORIA! free(variable);
    //
}

int main() {
    iniciar();
    return 0;
}
