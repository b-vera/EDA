#include <stdio.h>
#include <stdlib.h>

int ** iniciarMatriz(int filas, int columnas) {
    int i;
    int ** matriz = (int**)calloc(filas, sizeof(int*));
    for(i = 0; i < filas; i++){
        matriz[i] = (int*)calloc(columnas, sizeof(int));
    }
    return matriz;
}

int ** reajustarMatriz(int ** matriz,int filas, int columnas) {
    int i;
    matriz = (int**)realloc(matriz, sizeof(int *) * filas);
    for(i = 0; i < filas; i++){
        matriz[i] = (int*)realloc(matriz[i], sizeof(int) * columnas);
    }
    return matriz;
}

int ** asignarMatriz(int ** matriz,int filas,int columnas){
    int i,j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            matriz[i][j]=j;
        }
    }
    return matriz;
}

void printMatriz(int ** matriz,int filas,int columnas) {
    int i,j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas=5,columnas=5;
    int ** matriz = iniciarMatriz(filas,columnas);
    matriz = asignarMatriz(matriz,filas,columnas);
    printMatriz(matriz,filas,columnas);
    printf("\n");
    matriz = reajustarMatriz(matriz,7,7);
    printMatriz(matriz,7,7);
    return 0;
}
