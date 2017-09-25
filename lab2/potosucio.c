#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define A 1
#define J 11
#define Q 12
#define K 13
#define JOKER 14
#define BLANK 15

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


int mazo[53] = {A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,A,2,3,4,5,6,7,8,9,0,J,Q,K,JOKER};
int *mazoRevuelto[53];
bool usado[53];

// TDA Mano de cartas

Mano * crearMano() {
    Mano * List = (Mano *)malloc(sizeof(Mano));
    List->head = NULL;
    List->tail = NULL;
    List->size = 0;
    return List;
}

void agregarCarta(Mano * list,int valor) {

    printf("entre a agregarCarta\n");
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

void mostrarMano(Mano * list) {
    Carta *ptr = list->head;
    printf("entre a mostrarMano\n");
    while(ptr) {
        printf("carta %d ",ptr->valor);
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

void borrarDeMano(Mano * list,int valor) {

    printf("entre a borrar %d\n",valor );
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
        list->size--;
    }
    printf("valor borrado\n");
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
    printf("value %d\n",value);
    carta = buscarCarta(list,value);
    return carta;
}

void EliminarPares(Mano * list){
    printf("Entre a EliminarPares\n");
    int index=0,i = 0,j,k,l;
    int length=list->size;
    Carta *ptr = list->head;
    int * aux = (int*)malloc(sizeof(int)*list->size);

    while(ptr!=NULL) {
        aux[i] = ptr->valor;
        ptr = ptr->sig;
        borrarDeMano(list,aux[i]);
        i++;
    }

    for (j = 0; j < list->size; j++) {
        for (k = 0; k < list->size; k++) {
            if (aux[j]==aux[k] && j!=k){
                aux[j]=BLANK;
                aux[k]=BLANK;
            }
        }
    }
    for (l = 0; l < length; l++) {
        if (aux[l]!=BLANK) {
            printf("agregue ---------- %d\n",aux[l]);
            agregarCarta(list,aux[l]);
        }
    }
}

void revolverMano(Mano * list){
    printf("entre a revolver mano\n");
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
        //borrarDeMano(list,aux[i]);
        i++;
    }
    for (j=0; j < list->size; j++) {
    usado[i]=0;
    }
    for (k=0; k < list->size; k++) {
        do{
            index = (rand() % list->size);
        } while (used[index]==1);
        //printf("en pos %d escribo %d \n",k,aux[index]);
        new[k] = aux[index];
        used[index]=1;
    }
    printf("list->size: %d\n",list->size);
    for (l = 0; l < length; l++) {
        //printf("agregue --------- %d\n",new[l]);
        agregarCarta(list,new[l]);
    }

} //falta terminar

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
        link->sig = list->head;
        list->size++;

    }else {
        link->sig = list->head;
        list->tail->sig = link;
        link->nombre = nombre;
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

//operaciones del mazo
void revolverMazo() {
    srand(time(NULL));
    int i;
    for (i=0; i < 53; i++) {
    usado[i]=false;
    }

    int index=0;
    for (i=0; i < 53; i++) {
        do{
            index = (rand() % 53);
        } while (usado[index]);
        //printf("en pos %d escribo %d \n",i,mazo[index]);
        mazoRevuelto[i] = &mazo[index];
        usado[index]=true;
    }
}

void mostrarMazo() {
    int i;
    for (i = 0; i < 53; i++) {
        printf("%d\n",*mazoRevuelto[i]);
    }
}

void iniciar(){
    printf("\n##################################################\n");
    printf("                    POTO SUCIO\n");
    printf("##################################################\n");

    int cantJugadores,rival,index,i;
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
        printf(" 1. CPU-1\n");
        printf(" 2. CPU-2\n");
        printf(" 3. CPU-3\n");
        printf("\n-> ");
        scanf("%d",&rival);
    }else{
        srand(time(NULL));
        int contador=0;
        while (contador<cantJugadores) {
            index = (rand() % 3);
            otrosRivales[contador]=index;
            contador++;
        }
    }


    //inicializar lista turnos con los jugadores
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

    //empleamos nuestro mazo
    revolverMazo();

    //inicializar manos de jugadores y repartir mano a cada jugador
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
    printf("\nETAPA 1\n");
    cont=0;
    actual=turnos->head;
    while (cont<(cantJugadores+1)) {
        printf("Eliminando Pares en jugador %s\n",actual->nombre);
        //mostrarMano(actual->mano);
        //printf("\n");
        //EliminarPares(actual->mano);
        actual = actual->sig;
        cont++;
    }

    // ETAPA 2 = robar carta del mazo por turnos
    printf("\nETAPA 2\n");
    cont=0;
    actual=turnos->head;
    while (contadorMazo != 53 ) {
        agregarCarta(actual->mano,*mazoRevuelto[contadorMazo]);
        *mazoRevuelto[contadorMazo]=BLANK;
        actual = actual->sig;
        contadorMazo++;
    }
    //quitamos pares en etapa 2
    actual=turnos->head;
    while (cont<(cantJugadores+1)) {
        //printf("Eliminando Pares en jugador %s\n",actual->nombre);
        //mostrarMano(actual->mano);
        //printf("\n");
        //EliminarPares(actual->mano);
        actual = actual->sig;
        cont++;
    }

    //ETAPA 3 = robar carta al compañero
    printf("\nETAPA 3\n");
    char respuesta;
    int carta,value;
    actual=turnos->head;
    while (actual->sig->mano->size != 0) {

        // Revolver cartas
        if (strcmp(actual->sig->nombre,Jugador)) {
            printf("\n-> desea revolver la mano ? S/N : \n");
            scanf("%c",&respuesta);
            if (tolower(respuesta) == 's' ) {
                revolverMano(actual->mano);
            }
        }else if (strcmp(actual->sig->nombre,CPU2)==0) {
            revolverMano(actual->sig->mano);
        }else if (strcmp(actual->sig->nombre,CPU3)==0) {
            revolverMano(actual->sig->mano);
        }
        //mostrarMano(actual->sig->mano);


        // Robo de Cartas
        if (strcmp(actual->nombre,Jugador)==0) {
            printf("\n-> eliga una carta a robar entre 0-%d : ",actual->sig->mano->size );
            scanf("%d\n",&carta);
            value = buscarCarta(actual->sig->mano,carta);
            agregarCarta(actual->mano,value);
            //borrarDeMano(actual->sig->mano,value);

        }else if (strcmp(actual->nombre,CPU1)==0) {
            value=obtenerPrimerValor(actual->sig->mano);
            agregarCarta(actual->mano,value);
            //borrarDeMano(actual->sig->mano,value);

        }else if (strcmp(actual->nombre,CPU2)==0) {
            value=obtenerUltimoValor(actual->sig->mano);
            agregarCarta(actual->mano,value);
            //borrarDeMano(actual->sig->mano,value);

        }else if (strcmp(actual->nombre,CPU3)==0) {
            value=obtenerAleatorio(actual->sig->mano);
            agregarCarta(actual->mano,value);
            //borrarDeMano(actual->sig->mano,value);
        }

        actual = actual->sig;


    }


}

int main() {
    iniciar();

    //preguntar al diego:
    //borrarDeMano le da la wea
    //obtenerAleatorio no funciona sin print
    //etapa 3 problema prints

    /*
    char* nombre = "a";
    char* nombre2 = "b";
    Mano * mano = crearMano();
    Turnos * turnos = crearTurnos();
    agregarCarta(mano,J);
    agregarCarta(mano,Q);
    agregarCarta(mano,Q);
    agregarCarta(mano,K);
    agregarCarta(mano,K);
    mostrarMano(mano);
    int asd;
    //asd = buscarCarta(mano,3);
    asd = obtenerAleatorio(mano);
    printf(" aleatorio es %d\n",asd );
    //borrarDeMano(mano,Q);
    //mostrarMano(mano);

    //revolverMano(mano);
    //EliminarPares(mano);

    int prueba = obtenerPrimerValor(mano);
    int prueba2 = obtenerUltimoValor(mano);

    agregarJugador(turnos,nombre);
    agregarJugador(turnos,nombre2);
    //mostrarJugador(turnos);


    //mostrarMazo();
    */
}
