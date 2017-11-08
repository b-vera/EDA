#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Matriz * crearLista() {
    Matriz * List = (Matriz *)calloc(1,sizeof(Matriz));
    List->head = NULL;
    List->tail = NULL;
    List->vertices = 0;
    return List;
}

void agregarLista(Matriz * list,int nodo,int vertices) {

    fila * link = (fila *)calloc(1,sizeof(fila));

    if (list->vertices == 0 ) {
        list->head= link;
        list->tail = link;
        //printf("%d\n",valor);
        link->nodo = nodo;
        link-> arreglo = (int*)calloc(vertices,sizeof(int));
        link->sig = NULL;
        list->vertices++;

    }else {
        link->sig = NULL;
        list->tail->sig = link;
        //printf("%d\n",valor);
        link->nodo = nodo;
        link-> arreglo = (int*)calloc(vertices,sizeof(int));
        list->vertices++;
        list->tail = link;
    }
}

void mostrarLista(Matriz * list) {
    fila *ptr = list->head;
    while(ptr) {
        printf("%d", ptr->nodo);
        if (ptr->sig) {
            printf(" -> ");
        }
        ptr = ptr->sig;
    }
    printf("\n");
}

void imprimirArreglo(fila * ptr){
    int i=0;
    while(i<ptr->lenArreglo) {
        printf("%d", ptr->arreglo[i]);
        printf(" -> ");
    }
}

void verticesEnLista(Matriz * list,int vertices) {
    FILE *fp;
    int count = 0;
    int index = 0;
    int value = 0;
 	fp = fopen ( "Entrada.in", "r" );
    while (!feof(fp)){
        // printf("count = %d  value = %d \n",count,value );

        if (count == 0) {
            fscanf(fp, "%d" ,&value);
            // printf("vertices = %d\n",value);
            count++;
        } else if(count%2 == 0) {
            fscanf(fp, "%d" ,&value);
            // printf("es par\n");
            count++;
        } else {
            fscanf(fp, "%d" ,&value);
            if (value != index) {
                agregarLista(list,value,vertices);
                // printf("agregando a la lista\n");
                index = value;
            }
            count++;
        }
    }
    fclose ( fp );
}

void agregarEnLista(Matriz * list,int vertices) {
    FILE *fp;
    fila *ptr = list->head;
    int count = 0;
    int index = 0;
    int value = 0;
    int countArreglo = 0;
    fp = fopen ( "Entrada.in", "r" );
    while (!feof(fp)){
        printf("count = %d\n",count);
        if (count == 0) {
            fscanf(fp, "%d" ,&value);
            printf("vertices = %d\n",value);
            count++;
        } else if(count%2 == 0) {
            fscanf(fp, "%d" ,&value);
            ptr->arreglo[countArreglo]= value;
            ptr->lenArreglo = ptr->lenArreglo+1;
            countArreglo++;
            count++;
        } else {
            fscanf(fp, "%d" ,&value);
            if (index != value) {
                ptr = ptr->sig;
                countArreglo = 0;
            }
            index=value;
            count++;
        }
    }
    fclose ( fp );
    }
