#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define A 1
#define J 11
#define Q 12
#define K 13
#define X 14

// estructuras
typedef struct Carta {
    int valor;
    struct Carta * sig;
} Carta;

typedef struct Mano {
    Carta * head;
    Carta * tail;
    int size;
} Mano;

typedef struct jugador {
    char* nombre;
    Mano* mano;
    struct jugador * sig;
} jugador;

typedef struct Turnos {
    jugador * head;
    jugador * tail;
    int size;
} Turnos;


int mazo[53] = {A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,X};
int *mazoRevuelto[53];
bool usado[53];

//TDA Mano de cartas

Mano * crearMano(){
    Mano * List = (Mano *)malloc(sizeof(Mano));
    List->head = NULL;
    List->tail = NULL;
    List->size = 0;
    return List;
}

void agregarCarta(Mano * list,int valor) {

    printf("entre\n");
    Carta * link = (Carta *)malloc(sizeof(Carta));

    if (list->size == 0 ) {
        list->head= link;
        list->tail = link;
        printf("%d\n",valor);
        link->valor = valor;
        link->sig = NULL;
        list->size++;

    }else {
        link->sig = NULL;
        list->tail->sig = link;
        printf("%d\n",valor);
        link->valor = valor;
        list->size++;
        list->tail = link;
    }
}

void mostrarMano(Mano * list){
    Carta *ptr = list->head;
    printf("entre aca\n");
    while(ptr) {
        printf("carta %d\n",ptr->valor);
        ptr = ptr->sig;
    }
}

void borrarDeMano(Mano * list,int valor){
   Carta * nodo = list->head;
   Carta * anterior = NULL;
   while(nodo && nodo->valor < valor) {
      anterior = nodo;
      nodo = nodo->sig;
   }
   if(!nodo || nodo->valor != valor){
       return;
   } else { /* Borrar el nodo */
       if(!anterior){ /* Primer elemento */
           nodo = nodo->sig;
       }else{  /* un elemento cualquiera */
           anterior->sig = nodo->sig;
       }
       free(nodo);
   }
}

int obtenerPrimerValor(Mano * list){
    Carta *ptr = list->head;
    return ptr->valor;
}

int obtenerUltimoValor(Mano * list){
    Carta *ptr = list->head;
    printf("entre aca\n");
    while(ptr->sig) {

        ptr = ptr->sig;
    }
    return ptr->valor;
}

//TDA Turnos

Turnos * crearTurnos(){
    Turnos * List = (Turnos *)malloc(sizeof(Turnos));
    List->head = NULL;
    List->tail = NULL;
    List->size = 0;
    return List;
}

void agregarJugador(Turnos * list,char* nombre) {

    printf("entre\n");
    jugador * link = (jugador *)malloc(sizeof(jugador));

    if (list->size == 0 ) {
        list->head= link;
        list->tail = link;
        printf("%s\n",nombre);
        link->nombre = nombre;
        link->sig = list->head;
        list->size++;

    }else {
        link->sig = list->head;
        list->tail->sig = link;
        printf("%s\n",nombre);
        link->nombre = nombre;
        list->size++;
        list->tail = link;
    }
}

void mostrarJugador(Turnos * list){
    jugador *ptr = list->head;
    printf("entre aca\n");
    while(ptr) {
        printf("jugador %s\n",ptr->nombre);
        ptr = ptr->sig;
    }
}


//operaciones del mazo
void revolverMazo(){
    srand(time(NULL));
    int i;
    for (i=0; i < 53; i++){
    usado[i]=false;
    }

    int index=0;
    for (i=0; i < 53; i++){
        do{
            index = (rand() % 53);
        } while (usado[index]);
        printf("%d escribiendo %d \n",i,mazo[index]);
        mazoRevuelto[i] = &mazo[index];
        usado[index]=true;

    }
}

void mostrarMazo(){
    int i;
    for (i = 0; i < 53; i++) {
        printf("%d\n",*mazoRevuelto[i]);
    }
}




int main(){
    char* nombre = "a";
    char* nombre2 = "b";
    Mano * mano = crearMano();
    Turnos * turnos = crearTurnos();
    agregarCarta(mano,J);
    agregarCarta(mano,Q);
    agregarCarta(mano,K);
    //mostrarMano(mano);
    borrarDeMano(mano,Q);
    //mostrarMano(mano);
    int prueba = obtenerPrimerValor(mano);
    int prueba2 = obtenerUltimoValor(mano);

    agregarJugador(turnos,nombre);
    agregarJugador(turnos,nombre2);
    //mostrarJugador(turnos);


    //revolverMazo();
    //mostrarMazo();
}
