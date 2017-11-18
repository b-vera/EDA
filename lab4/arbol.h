#pragma once
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
void equilibrarEsp(AVL *arbol, Nodo *nodo);
void equilibrarOtros(AVL *arbol, Nodo *nodo);
void rotarDerechaEsp(AVL *arbol, Nodo *nodo);
void rotarDerechaOtros(AVL *arbol, Nodo *nodo);
void rotarIzquierdaEsp(AVL *arbol, Nodo *nodo);
void rotarIzquierdaOtros(AVL *arbol, Nodo *nodo);
void menu();
#endif
