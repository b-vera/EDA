#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbol.h"

AVL * crearAVL() {
	AVL * arbol = NULL;

	if ( ( arbol = malloc( sizeof( AVL ) ) ) == NULL ) return NULL;

	arbol -> rootEsp = NULL;
	arbol -> rootOtros = NULL;

	return arbol;
}

Nodo * inicializarNodo() {
	Nodo * nodo = NULL;

	if ( ( nodo = malloc( sizeof( Nodo ) ) ) == NULL ) {
		return NULL;
	}

    // se inicializan las cadenas de string
    nodo -> palabraEsp  = (char*)malloc(sizeof(char)*100);
    nodo -> palabraOtro = (char*)malloc(sizeof(char)*100);
    nodo -> defEsp	 	= (char*)malloc(sizeof(char)*100);
    nodo -> defOtro 	= (char*)malloc(sizeof(char)*100);

    // se inicializan los punteros
    nodo -> espL  = NULL;
	nodo -> espR  = NULL;
	nodo -> otroL = NULL;
	nodo -> otroR = NULL;

	return nodo;
}

void insertarNodoEsp(AVL *arbol, char *palabra, char *otra, char *significado ) {

	Nodo *nodo 		= NULL;
	Nodo *siguiente = NULL;
	Nodo *ultimo 	= NULL;

	if ( arbol->rootEsp == NULL ) {

		nodo = inicializarNodo();
		strcpy(nodo  -> palabraEsp,palabra);
		strcpy(nodo  -> palabraOtro,otra);
		strcpy(nodo  -> defEsp,significado);
		arbol -> rootEsp = nodo;


	} else {
		siguiente = arbol->rootEsp;
		ultimo = NULL;
		insertarEsp	(nodo, siguiente,ultimo,palabra,otra,significado);
	}
}

void insertarNodoOtros(AVL *arbol, char *palabra, char *otra, char *significado ) {

	Nodo *nodo 		= NULL;
	Nodo *siguiente = NULL;
	Nodo *ultimo 	= NULL;

	if ( arbol->rootOtros == NULL ) {

		nodo = inicializarNodo();
		strcpy(nodo  -> palabraEsp,palabra);
		strcpy(nodo  -> palabraOtro,otra);
		strcpy(nodo  -> defEsp,significado);
		arbol -> rootOtros = nodo;


	} else {
		siguiente = arbol -> rootOtros;
		ultimo = NULL;
		insertarOtro (nodo, siguiente,ultimo,palabra,otra,significado);
	}
}

void insertarEsp(Nodo *nodo, Nodo *siguiente, Nodo *ultimo, char *palabra, char *otra, char *significado) {

	int flag = 0;
	while( siguiente != NULL ) {
		// printf("palabra a insertar -> %s\n",palabra);
		// printf("siguiente Inicio   -> %s\n",siguiente->palabraEsp);
		ultimo = siguiente;
		int valor = strcmp(siguiente->palabraEsp,palabra);
		if (strcmp(siguiente->palabraEsp,palabra) < 0) {
			// printf("entro a derecha\n");
			siguiente = siguiente->espR;
			flag = 1;

		} else if (strcmp(siguiente->palabraEsp,palabra) > 0) {
			// printf("entro a izquierda\n");
			siguiente = siguiente->espL;
			flag = 0;
		} else {
			return;
		}
	}

	nodo = inicializarNodo();
	strcpy(nodo  -> palabraEsp,palabra);
	strcpy(nodo  -> palabraOtro,otra);
	strcpy(nodo  -> defEsp,significado);

	if( flag == 0 ) ultimo->espL = nodo;
	if( flag == 1 ) ultimo->espR = nodo;

}

void insertarOtro(Nodo *nodo, Nodo *siguiente, Nodo *ultimo, char *palabra, char *otra, char *significado) {

	int flag = 0;
	while( siguiente != NULL ) {
		// printf("palabra a insertar -> %s\n",otra);
		// printf("siguiente Inicio   -> %s\n",siguiente->palabraOtro);

		ultimo = siguiente;
		int valor = strcmp(siguiente->palabraOtro,otra);
		if (strcmp(siguiente->palabraOtro,otra) < 0) {
			// printf("entro a derecha\n");
			siguiente = siguiente->otroR;
			flag = 1;

		} else if (strcmp(siguiente->palabraOtro,otra) > 0) {
			// printf("entro a izquierda\n");
			siguiente = siguiente->otroL;
			flag = 0;
		} else {
			return;
		}
	}

	nodo = inicializarNodo();
	strcpy(nodo  -> palabraEsp,palabra);
	strcpy(nodo  -> palabraOtro,otra);
	strcpy(nodo  -> defEsp,significado);

	if( flag == 0 ) ultimo->otroL = nodo;
	if( flag == 1 ) ultimo->otroR = nodo;

}

void inOrdenEsp(Nodo *nodo) {

    if(nodo != NULL){
        inOrdenEsp(nodo -> espL);
        printf("%s\n",nodo -> palabraEsp);
        inOrdenEsp(nodo -> espR);
    }
}

void inOrdenOtro(Nodo *nodo) {

    if(nodo != NULL){
        inOrdenOtro(nodo -> otroL);
        printf("%s\n",nodo -> palabraOtro);
        inOrdenOtro(nodo -> otroR);
    }
}

int alturaEsp(Nodo *nodo) {

	int alturaIzquierda, alturaDerecha;

	if (nodo == NULL) return 0;
	if (nodo->espL == NULL && nodo->espR == NULL) return 0;

	alturaIzquierda = alturaEsp(nodo->espL);
	alturaDerecha   = alturaEsp(nodo->espR);

	if (alturaIzquierda > alturaDerecha) return 1+alturaIzquierda;

	return 1+alturaDerecha;
}

int alturaOtro(Nodo *nodo) {

	int alturaIzquierda, alturaDerecha;

	if (nodo == NULL) return 0;
	if (nodo->otroL == NULL && nodo->otroR == NULL) return 0;

	alturaIzquierda = alturaOtro(nodo->otroL);
	alturaDerecha   = alturaOtro(nodo->otroR);

	if (alturaIzquierda > alturaDerecha) return 1+alturaIzquierda;

	return 1+alturaDerecha;

}

int diferenciaAlturasEsp(Nodo *nodo) {
	return alturaEsp(nodo->espL)-alturaEsp(nodo->espR);
}

int diferenciaAlturasOtros(Nodo *nodo) {
	return alturaOtro(nodo->otroL)-alturaOtro(nodo->otroR);
}

void equilibrarEsp(AVL *arbol, Nodo *nodo) {

	int diferencia1, diferencia2;
	diferencia1 = diferenciaAlturasEsp(nodo);
	if (diferencia1 > 1) {
		diferencia2 = diferenciaAlturasEsp(nodo->espL);
		if (diferencia2 < 0) {
			rotarIzquierdaEsp(arbol,nodo->espL);
		}
		rotarDerechaEsp(arbol,nodo);
	}
	if (diferencia1 < -1) {
		diferencia2 = diferenciaAlturasEsp(nodo->espR);
		if (diferencia2 > 0) {
			rotarDerechaEsp(arbol,nodo->espR);
		}
		rotarIzquierdaEsp(arbol,nodo);
	}

}

void equilibrarOtros(AVL *arbol, Nodo *nodo) {

	int diferencia1, diferencia2;
	diferencia1 = diferenciaAlturasOtros(nodo);
	if (diferencia1 > 1) {
		diferencia2 = diferenciaAlturasOtros(nodo->otroL);
		if (diferencia2 < 0) {
			rotarIzquierdaOtros(arbol,nodo->otroL);
		}
		rotarDerechaOtros(arbol,nodo);
	}
	if (diferencia1 < -1) {
		diferencia2 = diferenciaAlturasOtros(nodo->otroR);
		if (diferencia2 > 0) {
			rotarDerechaOtros(arbol,nodo->otroR);
		}
		rotarIzquierdaOtros(arbol,nodo);
	}
}

void rotarDerechaEsp(AVL *arbol, Nodo *nodo) {

	Nodo *raiz;
	raiz = nodo -> espL;
	if (nodo  -> padreEsp == NULL) {
		arbol -> rootEsp = raiz;
	} else {
		if (nodo == nodo -> padreEsp -> espL) {
			nodo -> padreEsp -> espL = raiz;
		} else {
			nodo -> padreEsp -> espR = raiz;
		}
	}
	nodo -> espL = raiz -> espR;
	raiz -> espR = nodo;
	raiz -> padreEsp = nodo -> padreEsp;
	raiz -> espR -> padreEsp = raiz;
	if (raiz -> espL != NULL) {
		raiz -> espL -> padreEsp = raiz;
	}
}

void rotarDerechaOtros(AVL * arbol, Nodo *nodo) {
	Nodo *raiz;
	raiz = nodo -> otroL;
	if (nodo -> padreOtro == NULL) {
		arbol -> rootOtros = raiz;
	} else {
		if (nodo == nodo -> padreOtro -> otroL) {
			nodo -> padreOtro -> otroL = raiz;
		} else {
			nodo -> padreOtro -> otroR = raiz;
		}
	}
	nodo -> otroL = raiz -> otroR;
	raiz -> otroR = nodo;
	raiz -> padreOtro = nodo -> padreOtro;
	raiz -> otroR -> padreOtro = raiz;
	if (raiz -> otroL != NULL) {
		raiz -> otroL -> padreOtro = raiz;
	}
}

void rotarIzquierdaEsp(AVL *arbol, Nodo *nodo) {

	Nodo *raiz;
	raiz = nodo -> espR;
	if (nodo -> padreEsp == NULL) {
		arbol -> rootEsp = raiz;
	} else {
		if (nodo == nodo -> padreEsp -> espL) {
			nodo-> padreEsp -> espL = raiz;
		} else {
			nodo-> padreEsp -> espR = raiz;
		}
	}
	nodo -> espR = raiz -> espL;
	raiz -> espL = nodo;
	raiz -> padreEsp = nodo -> padreEsp;
	raiz -> espL -> padreEsp = raiz;
	if (raiz -> espR != NULL) {
		raiz -> espR -> padreEsp = raiz;
	}
}

void rotarIzquierdaOtros(AVL *arbol, Nodo *nodo) {
	Nodo *raiz;
	raiz = nodo -> otroR;
	if (nodo -> padreOtro == NULL) {
		arbol -> rootOtros = raiz;
	} else {
		if (nodo == nodo -> padreOtro -> otroL) {
			nodo -> padreOtro -> otroL = raiz;
		} else {
			nodo -> padreOtro -> otroR = raiz;
		}
	}
	nodo -> otroR = raiz -> otroL;
	raiz -> otroL = nodo;
	raiz -> padreOtro = nodo-> padreOtro;
	raiz -> otroL -> padreOtro = raiz;
	if (raiz -> otroR != NULL) {
		raiz -> otroR -> padreOtro = raiz;
	}
}
