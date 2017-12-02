#pragma once
#include <stdio.h>
#ifndef arbol_h
#define arbol_h

/////////////////////////////////////////////////
/// Definicion Tipo de Datos
/////////////////////////////////////////////////
/**
* Estructura que almacena la palabra junto con su traduccion y su definicion y
* los punteros para el arbol AVL para ambos valores de la palabra.
*/
typedef struct Nodo {
    char * palabraEsp;           //< Campo con la palabra en espanol
    char * palabraOtro;          //< Campo con la traduccion de la palabra
    char * defEsp;               //< Campo con el significado de la palabra
    struct Nodo * padreEsp;      //< Campo con el puntero al padre del nodo espanol
	struct Nodo * padreOtro;     //< Campo con el puntero al padre del nodo traducido
	struct Nodo * espL;          //< Campo con el puntero a la hijo izquierdo espanol
	struct Nodo * espR;          //< Campo con el puntero a la hijo derecho espanol
    struct Nodo * otroL;         //< Campo con el puntero a la hijo izquierdo traducida
	struct Nodo * otroR;         //< Campo con el puntero a la hijo derecho traducida
} Nodo ;

/**
* Estructura que se utiliza para tener los valores raiz del arbol
* tanto de la palabra como su traduccion
*/
typedef struct AVL {
	struct Nodo *rootEsp;         //< Campo con el puntero a la raiz español
    struct Nodo *rootOtros;       //< Campo con el puntero a la raiz traducida
} AVL;

/////////////////////////////////////////////////
/// Definicion De Firmas de Funciones
/////////////////////////////////////////////////

/**
* Encarga de la lectura de el archivo y a la vez la insercion de Datos
* dentro de el arbol AVL junto con su respectiva comprobacion de equilibrio.
*
* @param 	AVL 	arbol 			arbol AVL
* @return 	void
*/
void leerArchivo(AVL *arbol);

/**
* Inicializa las raices del arbol AVL
*
* @return 	void
*/
AVL * crearAVL();

/**
* Inicializa los valores y los punteros del nodo en NULL
*
* @return 	list
*/
Nodo * inicializarNodo();

/**
* Agrega elemento en espanol al arbol si este se encuentra vacio, de no ser asi llama
* a la funcion insertarNodoEsp
*
* @param 	Nodo 	nodo 			nodo al arbol
* @param 	Nodo 	siguiente 		nodo siguiente a revisar
* @param 	Nodo 	ultimo 		    nodo anterior a revisar
* @param 	char* 	palabra 		palabra del Nodo
* @param 	char* 	otra 		    traduccion del Nodo
* @param 	char* 	significado 	significado del Nodo.
* @return 	void
*/
void insertarEsp (Nodo *nodo, Nodo *siguiente, Nodo *ultimo, char *palabra, char *otra, char *significado);

/**
* Agrega elemento traducido al arbol si este se encuentra vacio, de no ser asi llama
* a la funcion insertarNodoEsp
*
* @param 	Nodo 	nodo 			nodo al arbol
* @param 	Nodo 	siguiente 		nodo siguiente a revisar
* @param 	Nodo 	ultimo 		    nodo anterior a revisar
* @param 	char* 	palabra 		palabra del Nodo
* @param 	char* 	otra 		    traduccion del Nodo
* @param 	char* 	significado 	significado del Nodo.
* @return 	void
*/
void insertarOtro (Nodo *nodo, Nodo *siguiente, Nodo *ultimo, char *palabra, char *otra, char *significado);

/**
* revisa la palabra en español a insertar y hace la insercion segun el nodo
* principal hacia la izquierda o derecha
*
* @param 	AVL 	arbol 			arbol AVL
* @param 	char* 	palabra 		palabra del Nodo
* @param 	char* 	otra 		    traduccion del Nodo
* @param 	char* 	significado 	significado del Nodo.
* @return 	void
*/
void insertarNodoEsp (AVL *arbol, char *palabra, char *otra, char *significado );

/**
* revisa la palabra traducida a insertar y hace la insercion segun el nodo
* principal hacia la izquierda o derecha
*
* @param 	AVL 	arbol 			arbol AVL
* @param 	char* 	palabra 		palabra del Nodo
* @param 	char* 	otra 		    traduccion del Nodo
* @param 	char* 	significado 	significado del Nodo.
* @return 	void
*/
void insertarNodoOtros (AVL *arbol, char *palabra, char *otra, char *significado );

/**
* Funcion que realiza la busqueda de el elemento en espanol en el arbol
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @param 	char* 	palabraIn 		palabra del Nodo
* @param 	char* 	palabraOut	    traduccion del Nodo
* @return 	void
*/
void buscarPalabraEsp(Nodo *nodo,char * palabraIn,char * palabraOut);

/**
* Funcion que realiza la busqueda de el elemento traducido en el arbol
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @param 	char* 	palabraIn 		palabra a buscar
* @param 	char* 	palabraOut	    palabra a retornar
* @return 	void
*/
void buscarPalabraOtro(Nodo *nodo,char * palabraIn,char * palabraOut);

/**
* Funcion que realiza la busqueda de la definicion del elemento
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @param 	char* 	palabraIn 		palabra a buscar
* @param 	char* 	palabraOut	    palabra a retornar
* @return 	void
*/
void buscarDefinicion(Nodo *nodo,char * palabraIn,char * palabraOut);

/**
* Funcion que realiza la rotacion hacia la izquierda en el arbol con
* los punteros de la traduccionx
*
* @param 	AVL 	arbol 			arbol AVL
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
void rotarIzquierdaOtros(AVL *arbol, Nodo *nodo);

/**
* Funcion que realiza la rotacion hacia la derecha en el arbol con
* los punteros de la traduccion
*
* @param 	AVL 	arbol 			arbol AVL
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
void rotarDerechaOtros(AVL *arbol, Nodo *nodo);

/**
* Funcion que equilibria el arbol en otro idioma cuando este se
* enuentre desequilibrado
*
* @param 	AVL 	arbol 			arbol AVL
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
void equilibrarOtros(AVL *arbol, Nodo *nodo);

/**
* Funcion que realiza la rotacion hacia la izquierda en el arbol con
* los punteros de la palabra en espanol
*
* @param 	AVL 	arbol 			arbol AVL
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
void rotarIzquierdaEsp(AVL *arbol, Nodo *nodo);

/**
* Funcion que realiza la rotacion hacia la derecha en el arbol con
* los punteros de la palabra en espanol
*
* @param 	AVL 	arbol 			arbol AVL
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
void rotarDerechaEsp(AVL *arbol, Nodo *nodo);

/**
* Funcion que equilibria el arbol en espanol cuando este se
* enuentre desequilibrado
*
* @param 	AVL 	arbol 			arbol AVL
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
void equilibrarEsp(AVL *arbol, Nodo *nodo);

/**
* Funcion que devuelve la diferencia de altura entre el subarbol derecho
* y el subarbol izquierdo en los valores traducidos
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
int diferenciaAlturasOtros(Nodo *nodo);

/**
* Funcion que devuelve la diferencia de altura entre el subarbol derecho
* y el subarbol izquierdo en las palabras en espanol
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
int diferenciaAlturasEsp(Nodo *nodo);

/**
* Funcion que realiza un recorrido inOrden a el arbol AVL en espanol
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @param 	FILE 	fp  			puntero al la lectura del archivo
* @return 	void
*/
void inOrdenEsp (Nodo *nodo,FILE *fp);

/**
* Funcion que realiza un recorrido inOrden a el arbol AVL traducido
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @param 	FILE 	fp  			puntero al la lectura del archivo
* @return 	void
*/
void inOrdenOtro(Nodo *nodo,FILE *fp);

/**
* Funcion que convierte una palabra ingresada a una en minusculas
*
* @param 	char* 	str 			palabra a convertir
* @return 	char*
*/
char *convertirTolower(char *str);

/**
* Funcion que calcula la altura del arbol a partir de un nodo en espanol
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
int alturaEsp (Nodo *nodo);

/**
* Funcion que calcula la altura del arbol a partir de un nodo traducido
*
* @param 	Nodo 	nodo 			nodo al arbol AVL
* @return 	void
*/
int alturaOtro (Nodo *nodo);

/**
* Menu Principal del programa, que realiza el llamado a las funciones
*
* @return 	void
*/
void menu();

/**
* Se libera la memoria del arbol AVL
* @return 	void
*/
void liberarMemoria(Nodo *nodo);
#endif
