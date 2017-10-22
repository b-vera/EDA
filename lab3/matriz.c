#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int * vertices;
    int ** matriz;
} grafoMatriz ;

void iniciarMatriz(grafoMatriz * ptr ,int vertices) {
    int i,j;
    ptr -> matriz = (int**)calloc(vertices, sizeof(int*));
    for (i = 0; i < vertices; i++) {
        ptr -> matriz[i]= (int*)calloc(vertices, sizeof(int));
    }
}

void imprimirMatriz(grafoMatriz * ptr ,int vertices) {
    int i,j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ",ptr-> matriz[i][j]);
        }
        printf("\n");
    }
}

void liberarMemoria(grafoMatriz * ptr ,int vertices) {
    int i;
    //liberar matriz
    for (i = 0; i < vertices; i++) {
        free(ptr->matriz[i]);
    }
    free(ptr->matriz);

    //liberar puntero
    ptr = NULL;
    free(ptr);

}

void archivoMatriz(grafoMatriz * ptr) {
 	FILE *fp;
    int count = 0;
    int index = 0;
    int value = 0;
 	fp = fopen ( "Entrada.in", "r" );

    while (!feof(fp)){
        if (count == 0) {
            fscanf(fp, "%d" ,&value);
            printf("vertices: %d\n",value);
            count++;
         } else if(count % 2 != 0) {
            fscanf(fp, "%d" ,&index);
            printf("index = %d\n",index);
            count++;
        } else {
            fscanf(fp, "%d" ,&value);
            ptr->matriz[index][value]=1;
            printf("coordenada %d %d\n",index,value);
            ptr->matriz[value][index]=1;
            printf("coordenada %d %d\n",value,index);
            count++;
        }
    }
 	fclose ( fp );
}
