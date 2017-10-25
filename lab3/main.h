#pragma once
#ifndef main_h
#define main_h

/////////////////////////////////////////////////
/// Definicion De Firmas de Funciones
/////////////////////////////////////////////////

/**
* Encargada de obtener el primer valor del archivo recibido con el Fin
* de poder acceder a la cantidad de vertices que posee el nodo.
*
* @return 	int      vertices              cantidad de vertices totales del grafo.
*/
int cantVertices();

/**
* Funcion encargada generar la busqueda de un grupo de mejores amigos, esta recorre toda
* la combinatoria de posibles soluciones de grupos de mejores amigos sin repeticiones.
*
* @param 	grafoMatriz 	ptr 			Puntero que apunta a la matriz.
* @param 	int           	vertices 		Cantidad de vertices totales en el grafo.
* @return 	void
*/
void buscarCliques(grafoMatriz * ptr,int vertices);

/**
* Funcion principal del funcionamiento del codigo con matrices.
*
* @return 	void
*/
void matriz();

/**
* Funcion principal del funcionamiento del codigo con listas.
*
* @return 	void
*/
void lista();

/**
* Funcion principal que llama tanto a la matriz como a la lista
* y genera el funcionamiento del programa.
*
* @return 	int     0
*/
int main();



#endif
