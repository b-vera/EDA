#include <stdio.h>
#include "matriz.c"
#include "matriz.h"
#include "listas.c"

int cantVertices() {
 	FILE *fp;
    int vertices=0;
 	fp = fopen ( "Entrada.in", "r" );
    fscanf(fp, "%d" ,&vertices);
 	fclose ( fp );
    // printf("valor= %d\n",vertices);
    return vertices;
}

// void vacia(int * valor){
//     if (valor[0] == '\0') {
//         return 1;
//     }
//     return 0;
// }

// void buscarVinculos(grafoMatriz * ptr,int vertices) {
//
//     int i,j;
//     int * verticesRecorridos;
//     int * aristasRecorridos;
//     int * marcados;
//     int * cola;
//
//     inicial=ptr->matriz[1][1];
//
//     verticesRecorridos = (int*)malloc(sizeof(int));
//     aristasRecorridos = (int*)malloc(sizeof(int));
//     marcados = (int*)malloc(sizeof(int));
//     cola = (int*)malloc(sizeof(int));
//
//     for (i = 0; i < vertices; i++) {
//         marcados[i]=0;
//     }
//
//     cola[0]=inicial;
//     marcados[inicial]=1;
//
//     while (vacia(cola)==0) {
//         int u =
//     }
//
// }

void buscarCliques(grafoMatriz * ptr,int vertices) {
    int i,j,k,l;
    int actual[4];
    for (i = 1; i < vertices; i++) {
        for (j = i+1; j < vertices; j++) {
            for (k = j+1; k < vertices; k++) {
                for (l = k+1; l < vertices; l++) {
                    if (i != j && ptr->matriz[i][j]==1 &&
                        i != k && ptr->matriz[i][k]==1 &&
                        i != l && ptr->matriz[i][l]==1 &&
                        j != k && ptr->matriz[j][k]==1 &&
                        j != l && ptr->matriz[j][l]==1 &&
                        k != l && ptr->matriz[k][l]==1 ) {
                        printf("%d, %d, %d, %d conforman un grupo de mejores amigos.\n",i,j,k,l);
                    }
                }
            }
        }
    }

}

void matriz() {

    //cantidad de vertices iniciales
    int vertices=0;
    vertices = cantVertices();

    //matriz
    grafoMatriz matriz;
    grafoMatriz * ptr;
    ptr = &matriz;

    printf("\n***** Inicia el Programa con Matrices *****\n\n");
    iniciarMatriz(ptr,vertices+1);
    archivoMatriz(ptr);
    // imprimirMatriz(ptr,vertices+1);
    // buscarVinculos(ptr,vertices+1);
    buscarCliques(ptr,vertices+1);
    liberarMemoria(ptr,vertices+1);
}

void lista() {

    //cantidad de vertices iniciales
    int vertices=0;
    vertices = cantVertices();

    printf("\n***** Inicia el Programa con Matrices *****\n\n");
    Matriz lista;
    Matriz * ptr = crearLista();
    verticesEnLista(ptr,vertices);
    mostrarLista(ptr);
}

int main() {
    matriz ();
    printf("\n");
    lista ();
    printf("\n");
    return 0;
}
