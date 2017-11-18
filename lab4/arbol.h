#pragma once
#ifndef arbol_h
#define arbol_h

typedef struct Nodo {
    char * palabraEsp;
    char * palabraOtro;
    char * defEsp;
    char * defOtro;
	struct Nodo * espL;
	struct Nodo * espR;
    struct Nodo * otroL;
	struct Nodo * otroR;
} Nodo ;

typedef struct AVL {
	struct Nodo *rootEsp;
    struct Nodo *rootOtros;
} AVL;

AVL * crearAVL();
Nodo * inicializarNodo();
void insertarEsp (Nodo *nodo, Nodo *siguiente, Nodo *ultimo, char *palabra, char *otra, char *significado);
void insertarOtro (Nodo *nodo, Nodo *siguiente, Nodo *ultimo, char *palabra, char *otra, char *significado);
void insertarNodoEsp (AVL *arbol, char *palabra, char *otra, char *significado );
void insertarNodoOtros (AVL *arbol, char *palabra, char *otra, char *significado );
void inOrdenEsp (Nodo *nodo);
void inOrdenOtro (Nodo *nodo);
int alturaEsp (Nodo *nodo);
int alturaOtro (Nodo *nodo);
int diferenciaAlturasEsp(Nodo *nodo);
int diferenciaAlturasOtros(Nodo *nodo);
void equilibrarEsp(Nodo *nodo);
void equilibrarOtros(Nodo *nodo);
void rotarDerechaEsp(Nodo *nodo);
void rotarDerechaOtros(Nodo *nodo);
void rotarIzquierdaEsp(Nodo *nodo);
void rotarIzquierdaOtros(Nodo *nodo);
#endif
