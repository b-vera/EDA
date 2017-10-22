#include <stdio.h>
#include "matriz.c"
//#include "listas.c"

int cantVertices(int vertices) {
 	FILE *fp;
 	fp = fopen ( "Entrada.in", "r" );
    fscanf(fp, "%d" ,&vertices);
 	fclose ( fp );
    printf("valor= %d\n",vertices);
    return vertices;
}

void buscarVinculos(grafoMatriz * ptr,int vertices) {

    int i,j;
    int * verticesRecorridos;
    int * aristasRecorridos;
    int * marcados;
    verticesRecorridos = (int*)malloc(sizeof(int));
    aristasRecorridos = (int*)malloc(sizeof(int));
    marcados = (int*)malloc(sizeof(int));

    for (i = 0; i < vertices; i++) {
        marcados[i]=0;
    }

    for (j = 0; j < vertices; j++) {
        printf("%d -> ",marcados[i]);
    }
}

void iniciar() {

    //cantidad de vertices iniciales
    int vertices=0;
    vertices = cantVertices(vertices);

    //matriz
    grafoMatriz matriz;
    grafoMatriz * ptr;
    ptr = &matriz;

    iniciarMatriz(ptr,vertices+1);
    archivoMatriz(ptr);
    imprimirMatriz(ptr,vertices+1);
    buscarVinculos(ptr,vertices+1);
    liberarMemoria(ptr,vertices+1);
}

int main() {
    iniciar ();
    return 0;
}
