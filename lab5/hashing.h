#pragma once
#include <stdio.h>
#include "listas.h"
#include "arbol.h"

#ifndef hashing_h
#define hashing_h

/////////////////////////////////////////////////
/// Definicion De Firmas de Funciones
/////////////////////////////////////////////////

/**
* Funcion que realiza un recorrido inOrden a el arbol AVL en espanol
* y a la vez realiza las inserciones en la tabla hash ingresada
*
* @param 	Nodo    	nodo 			nodo al arbol AVL.
* @param 	Lista** 	arregloEsp  	tabla hash.
* @return 	void
*/
void inOrdenHashEsp(Nodo *nodo,Lista ** arregloEsp);

/**
* Funcion que realiza un recorrido inOrden a el arbol AVL en otro idioma
* y a la vez realiza las inserciones en la tabla hash ingresada
*
* @param 	Nodo    	nodo 			nodo al arbol AVL.
* @param 	Lista** 	arregloOtro  	tabla hash.
* @return 	void
*/
void inOrdenHashOtro(Nodo *nodo,Lista ** arregloOtro);

/**
* Funcion que retorna en un archivo de salida la matriz con los valores
* obtenidos del arbol AVL en espanol
*
* @param 	Lista** 	arregloEsp  	tabla hash.
* @param 	FILE 	    matrizEspanol	puntero al la lectura del archivo.
* @return 	void
*/
void imprimirHashEsp(Lista ** arregloEsp,FILE * matrizEspanol);

/**
* Funcion que retorna en un archivo de salida la matriz con los valores
* obtenidos del arbol AVL en otro idioma
*
* @param 	Lista** 	arregloOtro  	tabla hash.
* @param 	FILE 	    matrizOtro  	puntero al la lectura del archivo.
* @return 	void
*/
void imprimirHashOtro(Lista ** arregloOtro,FILE * matrizOtro);

/**
* Funcion que realiza la busqueda del indice con mayor cantidad de Palabras
* dentro de nuestra tabla hash en espanol
*
* @param 	Lista** 	arregloEsp  	tabla hash.
* @return 	void
*/
char buscarMayorEsp(Lista ** arregloEsp);

/**
* Funcion que realiza la busqueda del indice con mayor cantidad de Palabras
* dentro de nuestra tabla hash en otro idioma
*
* @param 	Lista** 	arregloOtro  	tabla hash.
* @return 	void
*/
char buscarMayorOtro(Lista ** arregloOtro);

/**
* Funcion que realiza un recorrido a los elementos en la tabla hash retornando
* sus indices
*
* @param 	Lista** 	arregloOtro  	tabla hash.
* @param 	FILE 	    patrones      	puntero al la lectura del archivo.
* @return 	void
*/
void indicesPalabras(Lista ** arregloEsp,FILE *patrones);

#endif
