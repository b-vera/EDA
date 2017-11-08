#pragma once
#ifndef matriz_h
#define matriz_h

/////////////////////////////////////////////////
/// Definicion Tipo de Datos
/////////////////////////////////////////////////

/**
 * Estructura que almacena la informacion necesaria para generar nuestra
 * matriz de adyacencia
 */
typedef struct grafoMatriz {
    int * vertices;         //< Campo con la cantidad de vertices.
    int ** matriz;     //< Campo que contiene arreglo bidimensional dinamico.
} grafoMatriz ;

/////////////////////////////////////////////////
/// Definicion De Firmas de Funciones
/////////////////////////////////////////////////

/**
* Inicializa con 0 una matriz con las dimensiones del vertice.
*
* @param 	grafoMatriz 	ptr 			Puntero que apunta a la matriz.
* @param 	int           	vertices 		Cantidad de vertices totales en el grafo.
* @return 	void
*/
void iniciarMatriz(grafoMatriz * ptr ,int vertices);

/**
* Funcion encargada de mostrar en pantalla la matriz.
*
* @param 	grafoMatriz 	ptr 			Puntero que apunta a la matriz.
* @param 	int           	vertices 		Cantidad de vertices totales en el grafo.
* @return 	void
*/
void imprimirMatriz(grafoMatriz * ptr ,int vertices);

/**
* Funcion encargada de cargar la informacion leida en el archivo
* y organizarla en una matriz de adyacencia.
*
* @param 	grafoMatriz 	ptr 			Puntero que apunta a la matriz.
* @return 	void
*/
void archivoMatriz(grafoMatriz * ptr);

/**
* Realiza la liberacion de la memoria de la matriz de adyacencia.
*
* @param 	grafoMatriz 	ptr 			Puntero que apunta a la matriz.
* @param 	int           	vertices 		Cantidad de vertices totales en el grafo.
* @return 	void
*/
void liberarMemoria(grafoMatriz * ptr ,int vertices);

#endif
