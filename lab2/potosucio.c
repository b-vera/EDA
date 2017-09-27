#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "listas.h"

#define A 1
#define J 11
#define Q 12
#define K 13
#define JOKER 14
#define BLANK 15

// Estructuras

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
    int verificador;
    struct jugador * sig;
} jugador;

typedef struct Turnos {
    jugador * head;
    jugador * tail;
    int size;
} Turnos;

// Mazo
int mazo[53] = {A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,JOKER};
int *mazoRevuelto[53];
int usado[53];

// TDA Mano de cartas

Mano * crearMano() {
    Mano * List = (Mano *)malloc(sizeof(Mano));
    List->head = NULL;
    List->tail = NULL;
    List->size = 0;
    return List;
}

void agregarCarta(Mano * list,int valor) {

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

void mostrarMano(Mano * list) {
    Carta *ptr = list->head;
    while(ptr) {
        printf("%d", ptr->valor);
        if (ptr->sig) {
            printf(",");
        }
        ptr = ptr->sig;
    }
    printf("\n");
}

int buscarCarta(Mano * list,int pos){
    int cont;
    Carta *ptr = list->head;
    while(cont != pos) {
        ptr = ptr->sig;
        cont++;
    }
    return ptr->valor;
}

Mano * borrarDeMano(Mano * list,int valor) {

    //printf("entre a borrar %d\n",valor );
    Carta * nodo = list->head;
    Carta * anterior = NULL;
    while(nodo && nodo->valor < valor) {
        anterior = nodo;
        nodo = nodo->sig;
    }

    if(!nodo || nodo->valor != valor){
        return list;
    } else { /* Borrar el nodo */

        if(!anterior){ /* Primer elemento */
            list->head = nodo->sig;
            //mostrarMano(list);
        }else{  /* un elemento cualquiera */
            anterior->sig = nodo->sig;
            //mostrarMano(list);
        }
        //free(nodo);
        list->size--;
    }
    return list;
}

int obtenerPrimerValor(Mano * list) {
    Carta *ptr = list->head;
    return ptr->valor;
}

int obtenerUltimoValor(Mano * list) {
    Carta *ptr = list->head;
    while(ptr->sig) {
        ptr = ptr->sig;
    }
    return ptr->valor;
}

int obtenerAleatorio(Mano * list){
    srand(time(NULL));
    int value,carta;
    value = (rand() % list->size);
    printf("%c",10);
    carta = buscarCarta(list,value);
    return carta;
}

void EliminarPares(Mano * list){
    int index=0,i = 0,j,k,l,valor;
    int length=list->size;
    Carta *ptr = list->head;
    int * aux = (int*)malloc(sizeof(int)*list->size);

    while(ptr!=NULL) {
        aux[i] = ptr->valor;
        ptr = ptr->sig;
        borrarDeMano(list,aux[i]);
        i++;
    }

    for (j = 0; j < length; j++) {
        for (k = 0; k < length; k++) {
            if (aux[j]==aux[k] && j!=k){
                aux[j]=BLANK;
                aux[k]=BLANK;
            }
        }
    }
    for (l = 0; l < length; l++) {
        if (aux[l]!=BLANK) {
            agregarCarta(list,aux[l]);
        }
    }
}

Mano * revolverMano(Mano * list){

    srand(time(NULL));
    int index=0,i = 0,j,k,l;
    int length=list->size;
    Carta *ptr = list->head;
    int * aux = (int*)malloc(sizeof(int)*list->size);
    int * new = (int*)malloc(sizeof(int)*list->size);
    int * used = (int*)malloc(sizeof(int)*list->size);

    while(ptr!=NULL) {
        aux[i] = ptr->valor;
        ptr = ptr->sig;
        borrarDeMano(list,aux[i]);
        i++;
    }
    for (j=0; j < length; j++) {
    usado[i]=0;
    }
    for (k=0; k < length; k++) {
        do{
            index = (rand() % length);
        } while (used[index]==1);
        //printf("en pos %d escribo %d \n",k,aux[index]);
        new[k] = aux[index];
        used[index]=1;
    }
    for (l = 0; l < length; l++) {
        //printf("agregue --------- %d\n",new[l]);
        agregarCarta(list,new[l]);
    }
    return list;
}

// TDA Turnos

Turnos * crearTurnos() {
    Turnos * List = (Turnos *)malloc(sizeof(Turnos));
    List->head = NULL;
    List->tail = NULL;
    List->size = 0;
    return List;
}

void agregarJugador(Turnos * list,char* nombre) {

    jugador * link = (jugador *)malloc(sizeof(jugador));

    if (list->size == 0 ) {
        list->head= link;
        list->tail = link;
        link->nombre = nombre;
        link->verificador = 0;
        link->sig = list->head;
        list->size++;

    }else {
        link->sig = list->head;
        list->tail->sig = link;
        link->nombre = nombre;
        link->verificador = 0;
        list->size++;
        list->tail = link;
    }
}

void mostrarJugador(Turnos * list) {
    jugador *ptr = list->head;
    printf("entre a mostrarJugador\n");
    while(ptr) {
        printf("jugador %s\n",ptr->nombre);
        ptr = ptr->sig;
    }
}

// Operaciones del Mazo

void revolverMazo() {
    srand(time(NULL));
    int i;
    for (i=0; i < 53; i++) {
    usado[i]=0;
    }

    int index=0;
    for (i=0; i < 53; i++) {
        do{
            index = (rand() % 53);
        } while (usado[index]==1);
        //printf("en pos %d escribo %d \n",i,mazo[index]);
        mazoRevuelto[i] = &mazo[index];
        usado[index]=1;
    }
}

void mostrarMazo() {
    int i;
    for (i = 0; i < 53; i++) {
        printf("%d->",*mazoRevuelto[i]);
    }
}

// Funcion Principal

void iniciar(){
    printf("\n##################################################\n");
    printf("                    POTO SUCIO\n");
    printf("##################################################\n");

    int cantJugadores,rival,index,i,valor,contador,validar;
    char * CPU1 = "CPU-1";
    char * CPU2 = "CPU-2";
    char * CPU3 = "CPU-3";
    char * Jugador = (char*)malloc(sizeof(char)*15);
    int * otrosRivales = (int*)malloc(sizeof(int)*cantJugadores);

    printf("\n-> Ingrese Nombre De Jugador: ");
    scanf("%s",Jugador);
    printf("\n-> Ingrese Cantidad de Jugadores CPU (maximo 3): ");
    scanf("%d",&cantJugadores);
    if (cantJugadores==1) {
        printf("\n-> Escoja su Rival :\n");
        printf("\n 1. CPU-1\n");
        printf(" 2. CPU-2\n");
        printf(" 3. CPU-3\n");
        printf("\n-> ");
        scanf("%d",&rival);
    }else{
        srand(time(NULL));
        int verificador=0;
        while (contador<cantJugadores) {
            index = (rand() % 3);
            otrosRivales[contador]=index;
            contador++;
        }
    }


    // Inicializar lista turnos con los jugadores
    Turnos * turnos = crearTurnos();
    agregarJugador(turnos,Jugador);

    if (cantJugadores==1) {
        if ( rival == 1 ) {
            agregarJugador(turnos,CPU1);

        }else if ( rival == 2 ) {
            agregarJugador(turnos,CPU2);

        }else if (rival == 3) {
            agregarJugador(turnos,CPU3);
        }

    }else{
        for (i = 0; i < cantJugadores; i++) {
            if (otrosRivales[i]==0) {
                agregarJugador(turnos,CPU1);

            }else if (otrosRivales[i]==1) {
                agregarJugador(turnos,CPU2);

            }else if (otrosRivales[i]==2) {
                agregarJugador(turnos,CPU3);

            }
        }
    }

    // Empleamos nuestro mazo
    revolverMazo();

    // Inicializar manos de jugadores y repartir mano a cada jugador
    jugador *actual = turnos->head;
    int j;
    int cont=0;
    int contadorMazo=0;
    while (cont<(cantJugadores+1)) {
        actual->mano = crearMano();
        for ( j = 0; j < 12; j++) {
            //printf("carta %d a jugador %s\n",*mazoRevuelto[contadorMazo],actual->nombre);
            agregarCarta(actual->mano,*mazoRevuelto[contadorMazo]);
            *mazoRevuelto[contadorMazo]=BLANK;
            contadorMazo++;
        }
        //mostrarMano(actual->mano);
        actual = actual->sig;
        cont++;
    }

    // ETAPA 1 = pares en la mano
    cont=0;
    actual=turnos->head;
    if (strcmp("JANICE",Jugador)==0) {
        printf("\n ____________________ ETAPA 1 ____________________\n");
    }
    while (cont<(cantJugadores+1)) {
        if (strcmp("JANICE",Jugador)==0) {
            printf("\n-> Jugador: %s ",actual->nombre);
            printf("| Mano: ");
            mostrarMano(actual->mano);
        }
        EliminarPares(actual->mano);
        if (strcmp("JANICE",Jugador)==0) {
            printf("\n[ Removiendo Pares ]\n");
            printf("\n-> Jugador: %s ",actual->nombre);
            printf("| Mano: ");
            mostrarMano(actual->mano);
            printf("\n-----------\n");
        }
        actual = actual->sig;
        cont++;
    }

    // ETAPA 2 = robar carta del mazo por turnos
    cont=0;
    actual=turnos->head;
    if (strcmp("JANICE",Jugador)==0) {
        printf("\n ____________________ ETAPA 2 ____________________\n");
    }
    while (contadorMazo != 53 ) {
        agregarCarta(actual->mano,*mazoRevuelto[contadorMazo]);
        if (strcmp("JANICE",Jugador)==0) {
            printf("\n-> TURNO = %s\n",actual->nombre);
            printf("\n[ Sacando Carta del Mazo ]\n");
            printf("\n Carta Sacada: %d\n",*mazoRevuelto[contadorMazo]);
            printf("\nJugador: %s ",actual->nombre);
            printf("| Mano: ");
            mostrarMano(actual->mano);
        }
        EliminarPares(actual->mano);
        if (strcmp("JANICE",Jugador)==0) {
            printf("\n[ Removiendo Pares ]\n");
            printf("\nJugador: %s ",actual->nombre);
            printf("| Mano: ");
            mostrarMano(actual->mano);
        }
        *mazoRevuelto[contadorMazo]=BLANK;
        actual = actual->sig;
        contadorMazo++;
    }

    //ETAPA 3 = robar carta al compañero
    char respuesta;
    int carta,value;
    if (strcmp("JANICE",Jugador)==0) {
        printf("\n ____________________ ETAPA 3 ____________________\n");
    }

    printf("validar %d cantJugadores %d\n",validar,cantJugadores );
    while (validar != cantJugadores) {

        if (actual->sig->verificador == 0) {

            // Revolver cartas
            if (strcmp("JANICE",Jugador)==0) {
                printf("\n-> TURNO = %s\n",actual->nombre);
                printf("\nJugador: %s ",actual->nombre);
                printf("| Mano: ");
                mostrarMano(actual->mano);
            }

            if (strcmp(actual->sig->nombre,Jugador)==0) {
                printf("\nDesea revolver la mano ? S/N : ");
                scanf("%c",&respuesta);
                getchar();
                if (tolower(respuesta) == 's' ) {
                    actual->mano=revolverMano(actual->mano);
                    if (strcmp("JANICE",Jugador)==0) {
                        printf("\n[ Revolviendo Mano ]\n");
                        printf("\nJugador: %s ",actual->nombre);
                        printf("| Mano: ");
                        mostrarMano(actual->mano);
                    }
                }
            }else if (strcmp(actual->sig->nombre,CPU2)==0) {
                actual->mano=revolverMano(actual->mano);
                if (strcmp("JANICE",Jugador)==0) {
                    printf("\n[ Revolviendo Mano ]\n");
                    printf("\nJugador: %s ",actual->nombre);
                    printf("| Mano: ");
                    mostrarMano(actual->mano);
                }
            }else if (strcmp(actual->sig->nombre,CPU3)==0) {
                actual->mano=revolverMano(actual->mano);
                if (strcmp("JANICE",Jugador)==0) {
                    printf("\n[ Revolviendo Mano ]\n");
                    printf("\nJugador: %s ",actual->nombre);
                    printf("| Mano: ");
                    mostrarMano(actual->mano);
                }
            }
            // Robo de Cartas
            if (strcmp(actual->nombre,Jugador)==0) {
                printf("\nEliga una carta a robar entre 0-%d : ",(actual->sig->mano->size-1) );
                scanf("%d",&carta);
                getchar();
                value = buscarCarta(actual->sig->mano,carta);
                agregarCarta(actual->mano,value);
                actual->sig->mano = borrarDeMano(actual->sig->mano,value);
                EliminarPares(actual->mano);
                if (strcmp("JANICE",Jugador)==0) {
                    printf("\n[ Sacando Carta del Jugador y Eliminando pares ]\n");
                    printf("\n Carta Sacada: %d\n",value);
                    printf("\nJugador: %s ",actual->nombre);
                    printf("| Mano: ");
                    mostrarMano(actual->mano);
                }

            }else if (strcmp(actual->nombre,CPU1)==0) {
                value=obtenerPrimerValor(actual->sig->mano);
                agregarCarta(actual->mano,value);
                actual->sig->mano = borrarDeMano(actual->sig->mano,value);
                EliminarPares(actual->mano);
                if (strcmp("JANICE",Jugador)==0) {
                    printf("\n[ Sacando Carta del Jugador ]\n");
                    printf("\n Carta Sacada: %d\n",value);
                    printf("\nJugador: %s ",actual->nombre);
                    printf("| Mano: ");
                    mostrarMano(actual->mano);
                }

            }else if (strcmp(actual->nombre,CPU2)==0) {
                value=obtenerUltimoValor(actual->sig->mano);
                agregarCarta(actual->mano,value);
                actual->sig->mano = borrarDeMano(actual->sig->mano,value);
                EliminarPares(actual->mano);
                if (strcmp("JANICE",Jugador)==0) {
                    printf("\n[ Sacando Carta del Jugador ]\n");
                    printf("\n Carta Sacada: %d\n",value);
                    printf("\nJugador: %s ",actual->nombre);
                    printf("| Mano: ");
                    mostrarMano(actual->mano);
                }

            }else if (strcmp(actual->nombre,CPU3)==0) {
                value=obtenerAleatorio(actual->sig->mano);
                agregarCarta(actual->mano,value);
                actual->sig->mano = borrarDeMano(actual->sig->mano,value);
                EliminarPares(actual->mano);
                if (strcmp("JANICE",Jugador)==0) {
                    printf("\n[ Sacando Carta del Jugador ]\n");
                    printf("\n Carta Sacada: %d\n",value);
                    printf("\nJugador: %s ",actual->nombre);
                    printf("| Mano: ");
                    mostrarMano(actual->mano);
                }
            }

            actual = actual->sig;

        } else {
            actual = actual->sig;
            actual = actual->sig;
        }
    }
    printf("El Jugador %s Ha Perdido!\n",actual->nombre);
}

int main() {

    iniciar();
}
