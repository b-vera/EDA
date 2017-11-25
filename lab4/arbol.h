#pragma once
#include <stdio.h>
#ifndef arbol_h
#define arbol_h

typedef struct Nodo {
    char * palabraEsp;
    char * palabraOtro;
    char * defEsp;
    char * defOtro;
    struct Nodo * padreEsp;
	struct Nodo * padreOtro;
	struct Nodo * espL;
	struct Nodo * espR;
    struct Nodo * otroL;
	struct Nodo * otroR;
} Nodo ;

typedef struct AVL {
	struct Nodo *rootEsp;
    struct Nodo *rootOtros;
} AVL;

void leerArchivo(AVL *arbol);
AVL * crearAVL();
Nodo * inicializarNodo();
void insertarEsp (Nodo *nodo, Nodo *siguiente, Nodo *ultimo, char *palabra, char *otra, char *significado);
void insertarOtro (Nodo *nodo, Nodo *siguiente, Nodo *ultimo, char *palabra, char *otra, char *significado);
void insertarNodoEsp (AVL *arbol, char *palabra, char *otra, char *significado );
void insertarNodoOtros (AVL *arbol, char *palabra, char *otra, char *significado );
void buscarPalabraEsp(Nodo *nodo,char * palabraIn,char * palabraOut);
void buscarPalabraOtro(Nodo *nodo,char * palabraIn,char * palabraOut);
void buscarDefinicion(Nodo *nodo,char * palabraIn,char * palabraOut);
void rotarIzquierdaOtros(AVL *arbol, Nodo *nodo);
void rotarDerechaOtros(AVL *arbol, Nodo *nodo);
void equilibrarOtros(AVL *arbol, Nodo *nodo);
void rotarIzquierdaEsp(AVL *arbol, Nodo *nodo);
void rotarDerechaEsp(AVL *arbol, Nodo *nodo);
void equilibrarEsp(AVL *arbol, Nodo *nodo);
int diferenciaAlturasOtros(Nodo *nodo);
int diferenciaAlturasEsp(Nodo *nodo);
void inOrdenEsp (Nodo *nodo,FILE *fp);
void inOrdenOtro(Nodo *nodo,FILE *fp);
char *convertirTolower(char *str);
int alturaEsp (Nodo *nodo);
int alturaOtro (Nodo *nodo);
void menu();
#endif
