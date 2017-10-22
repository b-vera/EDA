#include <stdio.h>

Mano * crearLista() {
    Mano * List = (Mano *)malloc(sizeof(Mano));
    List->head = NULL;
    List->tail = NULL;
    List->size = 0;
    return List;
}

void agregarLista(Mano * list,int valor) {

    Carta * link = (Carta *)malloc(sizeof(Carta));

    if (list->size == 0 ) {
        list->head= link;
        list->tail = link;
        //printf("%d\n",valor);
        link->valor = valor;
        link->sig = NULL;
        list->size++;

    }else {
        link->sig = NULL;
        list->tail->sig = link;
        //printf("%d\n",valor);
        link->valor = valor;
        list->size++;
        list->tail = link;
    }
}
