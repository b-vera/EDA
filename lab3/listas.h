#pragma once
#ifndef listas_h
#define listas_h


/////////////////////////////////////////////////
/// Definicion Tipo de Datos
/////////////////////////////////////////////////

/**
 * Estructura que almacena el valor numerico de cada carta y un puntero hacia la carta
 * siguinte.
 */
 typedef struct fila {
     int nodo;            //< Campo con el valor de cada vertice.
     int * arreglo;       //< Campo con arreglo dinamico para guardar aristas.
     int lenArreglo;      //< Campo con el valor del largo del arreglo.
     struct fila * sig;   //< Campo con el puntero a la fila siguiente.
 } fila;

/**
 * Estructura que se utiliza para generar una lista con los vertices.
 * Posee punteros para definir la cabeza y la cola de la lista y un entero para almacenar
 * la cantidad de vertices del grafo entregado.
 */
 typedef struct Matriz {
     fila * head;         //< Campo con el puntero al primer elemento de la lista.
     fila * tail;         //< Campo con el puntero al ultimo elemento de la lista.
     int vertices;        //< Campo con la cantidad de vertices en el grafo.
 } Matriz;

 /////////////////////////////////////////////////
 /// Definicion De Firmas de Funciones
 /////////////////////////////////////////////////

 /**
 * Inicializa la estructura matriz y le da valores iniciales.
 *
 * @return 	list
 */
 Matriz * crearLista();

 /**
 * Agrega un Nodo vertice a la lista matriz al final de esta.
 * Si la lista se encuentra vacia, esta inserta el primer valor.
 *
 * @param 	Matriz 	list 			Lista la cual contiene la los vertices del grafo.
 * @param 	int 	nodo 		    Valor con que posee cada vertice.
 * @param 	int 	vertices 		Vertices totales en el grafo.
 * @return 	void
 */
 void agregarLista(Matriz * list,int nodo,int vertices)

 /**
 * Encargada de mostrar en pantalla los elementos de la lista matriz.
 *
 * @param 	Matriz 	list 			Lista la cual contiene la los vertices del grafo.
 * @return 	void
 */
 void mostrarLista(Matriz * list);

 /**
 * Encargada de mostrar en pantalla los elementos del arreglo en cada vertice.
 *
 * @param 	fila 	ptr 			Puntero que se mueve por cada Vertice del grafo.
 * @return 	void
 */
 void imprimirArreglo(fila * ptr);

 /**
 * Agrega los elementos que estan enlazados a otros a una lista
 * generando un indice sin repeticiones.
 *
 * @param 	Matriz 	list 			Lista la cual contiene la los vertices del grafo.
 * @param 	int 	vertices 		Vertices totales en el grafo.
 * @return 	list
 */
 void verticesEnLista(Matriz * list,int vertices);

 /**
 * Agrega los elementos que estan enlazados a otros a un arreglo correspondiente
 * a cada indice ya insertado en la lista.
 *
 * @param 	Matriz 	list 			Lista la cual contiene la los vertices del grafo.
 * @param 	int 	vertices 		Vertices totales en el grafo.
 * @return 	int
 */
 void agregarEnLista(Matriz * list,int vertices);

#endif
