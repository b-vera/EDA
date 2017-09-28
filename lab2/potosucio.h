#pragma once
#ifndef potosucio_h
#define potosucio_h

/////////////////////////////////////////////////
/// Definicion De Constantes
/////////////////////////////////////////////////
/**
 * Para poder trabajar de manera mas eficiente nuestro mazo de cartas, se define de manera
 * numerica a las cartas que posean una letra como valor.
 * Se define a la vez una variable BLANK la cual se utilizara para indicar una carta retirada
 * del mazo.
 */

#define A 1
#define J 11
#define Q 12
#define K 13
#define JOKER 14
#define BLANK 15

/////////////////////////////////////////////////
/// Definicion Tipo de Datos
/////////////////////////////////////////////////

/**
 * Estructura que almacena el valor numerico de cada carta y un puntero hacia la carta
 * siguinte.
 */
typedef struct Carta {
    int valor;              //< Campo con el valor de cada carta.
    struct Carta * sig;     //< Campo con el puntero a la carta siguiente.
} Carta;

/**
 * Estructura que se utiliza para generar una lista con las cartas que posea cada jugador.
 * Posee punteros para definir la cabeza y la cola de la lista y un entero para almacenar
 * el tamaño de esta.
 */
typedef struct Mano {
    Carta * head;           //< Campo con el puntero al primer elemento de la lista.
    Carta * tail;           //< Campo con el puntero al ultimo elemento de la lista.
    int size;               //< Campo con el tamaño de elementos en la lista.
} Mano;

/**
 * Estructura que almacena los datos de cada jugador, los cuales consisten en el nombre
 * del jugador, un puntero a la Estructura Mano, un verificador utilizado cuando el jugador
 * se quede sin cartas en la mano y el puntero al siguiente jugador.

 */
typedef struct jugador {
    char* nombre;           //< Campo con nombre del jugador correspondiente.
    Mano* mano;             //< Campo con el puntero a la mano del jugador.
    int verificador;        //< Campo con el valor verificador del jugador.
    struct jugador * sig;
} jugador;

/**
 * Estructura sobre la cual se genera una lista circular con el fin de poder unir cada
 * jugador con el siguiente, generando asi los turnos.
 * Posee punteros para definir la cabeza y la cola de la lista y un entero para almacenar
 * el tamaño de esta.
 */
typedef struct Turnos {
    jugador * head;         //< Campo con el puntero al primer elemento de la lista.
    jugador * tail;         //< Campo con el puntero al ultimo elemento de la lista.
    int size;               //< Campo con el tamaño de elementos en la lista.
} Turnos;

/////////////////////////////////////////////////
/// Definicion De Firmas de Funciones
/////////////////////////////////////////////////

/**
* Inicializa la estructura Mano y le da valores iniciales.
*
* @return 	list
*/
Mano * crearMano();

/**
* Agrega un Nodo Carta a la lista Mano al final de esta.
* Si la lista se encuentra vacia, esta inserta el primer valor.
*
* @param 	Mano 	list 			Lista la cual contiene la mano del jugador.
* @param 	int 	valor 		    Valor de la carta la cual se agregara.
* @return 	void
*/
void agregarCarta(Mano * list,int valor);

/**
* Encargada de mostrar en pantalla los elementos de la lista Mano.
*
* @param 	Mano 	list 			Lista la cual contiene la mano del jugador.
* @return 	void
*/
void mostrarMano(Mano * list);

/**
* Realiza la busqueda de una carta en la lista referente a su posicion y la retorna.
*
* @param 	Mano 	list 			Lista la cual contiene la mano del jugador.
* @param 	int 	pos 	    	Posicion de la carta que buscamos.
* @return 	int                     Valor de la carta buscada.
*/
int buscarCarta(Mano * list,int pos);

/**
* Elimina de la lista la carta segun el valor entregado.
*
* @param 	Mano 	list 			Lista la cual contiene la mano del jugador.
* @param 	int 	valor 		    Valor de la carta la cual se agregara.
* @return 	list
*/
Mano * borrarDeMano(Mano * list,int valor);

/**
* Entrega el primer elemento de la lista.
*
* @param 	Mano 	list 			Lista la cual contiene la mano del jugador.
* @return 	int
*/
int obtenerPrimerValor(Mano * list);

/**
* Entrega el ultimo elemento de la lista.
*
* @param 	Mano 	list 			Lista la cual contiene la mano del jugador.
* @return 	int
*/
int obtenerUltimoValor(Mano * list);

/**
* Entrega un elemento al azar de la lista.
*
* @param 	Mano 	list 			Lista la cual contiene la mano del jugador.
* @return 	int
*/
int obtenerAleatorio(Mano * list);

/**
* Funcion encargada de buscar si una carta se encuentra dos veces en la mano.
* De ser asi, estas son eliminadas.
*
* @param 	Mano 	list 			Lista la cual contiene la mano del jugador.
* @return 	void
*/
void EliminarPares(Mano * list);

/**
* Encargada de cambiar de manera aleatoria las posiciones de cada carta en el mazo.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @return 	list
*/
Mano * revolverMano(Mano * list);

/**
* Inicializa la estructura Turnos y le entrega valores iniciales.
*
* @return 	lista
*/
Turnos * crearTurnos();

/**
* Encargado de agregar el Nodo jugador a la lista Turnos y agregarle sus valores iniciales.
* Si la lista se encuentra vacia, este inserta el primer elemento.
*
* @param 	Turnos*	list 			Lista la cual contiene a los jugadores.
* @param 	char* 	nombre  		Nombre del jugador.
* @return 	void
*/
void agregarJugador(Turnos * list,char* nombre);

/**
* Encargada de mostrar en pantalla los elementos de la lista Turnos.
*
* @param 	Turnos*	list 			Lista la cual contiene a los jugadores.
* @return 	void
*/
void mostrarJugador(Turnos * list);

/**
* Encargada de cambiar las posiciones de los valores del mazo de manera aleatoria.
*
* @return 	void
*/
void revolverMazo();

/**
* Encargada de mostrar en pantalla los elementos del arreglo mazo.
*
* @return 	void
*/
void mostrarMazo();

/**
* Funcion Principal encargada de organizar el TDA anterior.
* Posee las consultas al usuario tales como nombre y cantidad de jugadores.
* Trabaja las 3 etapas del juego por separado.
* Retorna resultado en pantalla de quien fue el perdedor del juego.
*
* @return 	void
*/
void iniciar();

#endif
