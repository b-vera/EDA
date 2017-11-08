#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "listas.h"

int cantVertices() {
 	FILE *fp;
    int vertices=0;
 	fp = fopen ( "Entrada.in", "r" );
    fscanf(fp, "%d" ,&vertices);
 	fclose ( fp );
    return vertices;
}

int verticeInicial(){
    FILE *fp;
    int inicial;
    fp = fopen("Entrada.in","r");
    fscanf(fp,"%d",&inicial);
    fscanf(fp,"%d",&inicial);
    fclose(fp);
    return inicial;
}

void busquedaEnProfundidad(grafoMatriz * ptr,int vertices,int * visited,int * grafoRecorrido,int cont,int i) {
    int j;
    //se inserta en grafoRecorrido
    //printf("\ni %d",i);
    grafoRecorrido[cont]=i;
    visited[i]=1;
    for(j=0;j<vertices;j++){
        if(!visited[j]&&ptr->matriz[i][j]==1){
            busquedaEnProfundidad(ptr,vertices,visited,grafoRecorrido,cont+1,j);
        }
    }
}

void buscarArticulacion(grafoMatriz * ptr,int vertices) {
    int * visited = (int*)calloc((vertices+1),sizeof(int));
    int * grafoRecorrido = (int*)calloc((vertices+1),sizeof(int));

    busquedaEnProfundidad(ptr,vertices+1,visited,grafoRecorrido,1,7);

    // for(int d=0;d<vertices;d++){
    //    printf("\n%d",grafoRecorrido[d]);
    // }


}

/**
* buscarCliques()
* Encargada de la busqueda del grupo de mejores amigos
*
* @param 	grafoMatriz 	ptr 			Puntero que apunta a la matriz.
* @param 	int           	vertices 		Cantidad de vertices totales en el grafo.
*/
void buscarCliques(grafoMatriz * ptr,int vertices) {
    int i,j,k,l;
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

    // cantidad de vertices iniciales
    int i=0,vertices=0;
    vertices = cantVertices();

    // inicializacion de matriz
    grafoMatriz matriz;
    grafoMatriz * ptr;
    ptr = &matriz;

    // parametros para medir tiempo
    clock_t start, end;
    double cpu_time_used;

    printf("\n***** Inicia el Programa con Matrices *****\n\n");
    iniciarMatriz(ptr,vertices+1);
    archivoMatriz(ptr);
    // imprimirMatriz(ptr,vertices+1);
    start = clock();
    buscarCliques(ptr,vertices+1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nEl algoritmo tarda %f segundos en ejecutarse. \n", cpu_time_used);
    buscarArticulacion(ptr,vertices+1);
    liberarMemoria(ptr,vertices+1);
    printf("\n***** Final del Programa con Matrices *****\n\n");
}

void lista() {

    //cantidad de vertices iniciales
    int vertices=0;
    vertices = cantVertices();

    printf("\n***** Inicia el Programa con Listas *****\n\n");
    Matriz lista;
    Matriz * ptr = crearLista();
    verticesEnLista(ptr,vertices);
    //mostrarLista(ptr);
    printf("\n***** Final del Programa con Listas *****\n\n");
}

int main() {
    matriz ();
    printf("\n");
    // lista ();
    printf("\n");
    return 0;
}
