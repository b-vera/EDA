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
        printf("%d\n",*ptr->matriz[i]);
        free(ptr->matriz[i]);
    }
    free(ptr->matriz);

    //liberar puntero
    ptr = NULL;
    free(ptr);

}


void iniciar() {

    int cantVertices;
    
    grafoMatriz matriz;
    grafoMatriz * ptr;
    ptr = &matriz;

    int prueba = 5;
    iniciarMatriz(ptr,prueba);
    imprimirMatriz(ptr,prueba);
    liberarMemoria(ptr,prueba);


}
int main() {
    iniciar ();
    return 0;
}
