#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "arbol.h"


void inOrdenHashEsp(Nodo *nodo,Lista ** arregloEsp) {

    if(nodo != NULL){

        inOrdenHashEsp(nodo -> espL,arregloEsp);

		agregarPalabra(arregloEsp[nodo->palabraEsp[0]%27],nodo -> palabraEsp);

		inOrdenHashEsp(nodo -> espR,arregloEsp);
    }
}

void inOrdenHashOtro(Nodo *nodo,Lista ** arregloOtro) {

    if(nodo != NULL){

        inOrdenHashOtro(nodo -> otroL,arregloOtro);

		agregarPalabra(arregloOtro[nodo->palabraOtro[0]%27],nodo -> palabraOtro);

		inOrdenHashOtro(nodo -> otroR,arregloOtro);
    }
}

void imprimirHashEsp(Lista ** arregloEsp,FILE * matrizEspanol) {
    int i;
    fprintf(matrizEspanol,"*** Matriz en espanol ***\n\n");
    for ( i = 0; i < 27; i++ ) {
        if ( arregloEsp[i]->size != 0 ) {
            Palabra * aux = arregloEsp[i]->head;
            while ( aux != NULL ){
                fprintf( matrizEspanol,"%8s |",aux->palabra );
                aux = aux->sig;
            }
            fprintf(matrizEspanol,"\n");
        }
    }
}

void imprimirHashOtro(Lista ** arregloOtro,FILE * matrizOtro) {
    int i;
    fprintf(matrizOtro,"*** Matriz en otro idioma ***\n\n");
    for ( i = 0; i < 27; i++ ) {
        if ( arregloOtro[i]->size != 0 ) {
            Palabra * aux = arregloOtro[i]->head;
            while ( aux != NULL ){
                fprintf( matrizOtro,"%8s |",aux->palabra );
                aux = aux->sig;
            }
            fprintf(matrizOtro,"\n");
        }
    }
}

char buscarMayorEsp(Lista ** arregloEsp) {
    int i,mayor = -1;
    char caracter = 'x';

    for ( i = 0; i < 27; i++ ) {
        if ( arregloEsp[i]->size > mayor && arregloEsp[i]->size != 0) {
            Palabra * aux = arregloEsp[i]->head;
            mayor = arregloEsp[i]->size;
            caracter = aux->palabra[0];
        }
    }
    return caracter;
}

char buscarMayorOtro(Lista ** arregloOtro) {
    int i,mayor = -1;
    char caracter = 'x';

    for ( i = 0; i < 27; i++ ) {
        if ( arregloOtro[i]->size > mayor && arregloOtro[i]->size != 0) {
            Palabra * aux = arregloOtro[i]->head;
            mayor = arregloOtro[i]->size;
            caracter = aux->palabra[0];
        }
    }
    return caracter;
}

void indicesPalabras(Lista ** arregloEsp,FILE *patrones) {
    int i;
    fprintf(patrones,"******************************\n\n");
    fprintf(patrones, "indices : ");
    for ( i = 0; i < 27; i++ ) {
        if ( arregloEsp[i]->size != 0 ) {
            Palabra * aux = arregloEsp[i]->head;
            fprintf(patrones, " %c ",aux->palabra[0] );
        }
    }
}
