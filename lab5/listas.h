#pragma once
#ifndef listas_h
#define listas_h

/////////////////////////////////////////////////
/// Definicion Tipo de Datos
/////////////////////////////////////////////////

/**
 * Estructura que almacena la palabra y un puntero hacia la carta
 * siguinte.
 */
typedef struct Palabra {
    char * palabra;           //< Campo con el valor de cada palabra.
    struct Palabra * sig;     //< Campo con el puntero a la palabra siguiente.
} Palabra;

/**
 * Estructura que se utiliza para generar una lista con las palabras
 * Posee punteros para definir la cabeza y la cola de la lista y un entero para almacenar
 * el tamaño de esta.
 */
typedef struct Lista {
    Palabra * head;           //< Campo con el puntero al primer elemento de la lista.
    Palabra * tail;           //< Campo con el puntero al ultimo elemento de la lista.
    int size;                 //< Campo con el tamaño de elementos en la lista.
} Lista;

/////////////////////////////////////////////////
/// Definicion De Firmas de Funciones
/////////////////////////////////////////////////

/**
* Inicializa la estructura matriz y le da valores iniciales.
*
*  @return 	lista
*/
Lista * crearLista();

/**
* Agrega un Nodo vertice a la lista matriz al final de esta.
* Si la lista se encuentra vacia, esta inserta el primer valor.
*
* @param 	Lista 	list 			Lista la cual contiene las palabras.
* @param 	char* 	palabra 		palabra insertada.
* @return 	void
*/
void agregarPalabra(Lista * list,char * palabra);

/**
* Encargada de mostrar en pantalla los elementos de la lista.
*
* @param 	Lista 	list 			Lista la cual contiene las palabras.
* @return 	void
*/
void mostrarLista(Lista * list);
#endif
