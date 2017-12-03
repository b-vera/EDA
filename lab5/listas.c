#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

Lista * crearLista() {

    Lista * List = (Lista *)calloc(1,sizeof(Lista));
    List->head = NULL;
    List->tail = NULL;
    List->size = 0;
    return List;
}

void agregarPalabra(Lista * list,char * palabra) {

    Palabra * link = (Palabra *)calloc(1,sizeof(Palabra));
    if (list->size == 0 ) {
        list->head= link;
        list->tail = link;
        link-> palabra = (char*)calloc(20,sizeof(char));
        strcpy(link->palabra,palabra);
        link->sig = NULL;
        list->size++;

    }else {
        link->sig = NULL;
        list->tail->sig = link;
        link-> palabra = (char*)calloc(20,sizeof(char));
        strcpy(link->palabra,palabra);
        list->size++;
        list->tail = link;
    }
}

void mostrarLista(Lista * list) {
    Palabra *ptr = list->head;
    while(ptr) {
        if (ptr->sig) {
            printf("palabra = %s\n",ptr->palabra);
        }
        ptr = ptr->sig;
    }
    printf("\n");
}
