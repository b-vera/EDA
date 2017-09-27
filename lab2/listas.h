#ifndef _LISTAS_H_
#define _LISTAS_H_

/////////////////////////////////////////////////
/// Definicion De Constantes
/////////////////////////////////////////////////
/**
 * Los comandos para limpiar la pantalla son diferentes para Windowsy Linux/OSX
 * Por lo mismo se define una constante en base al SO con el que se esta trabajando,
 * y se hace uso de la funcion system() y la constante para limpiar la pantalla en los
 * diferentes SOs.
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
 * Estructura que almacena todos los datos necesarios para simular un tablero.
 * No es estrictamente necesario trabajar con una, pero simplifica el paso de variables
 * y hace mas facil la comprension del codigo.
 */
typedef struct Carta {
    int valor;
    struct Carta * sig;
} Carta;

/**
 * Estructura que almacena todos los datos necesarios para simular un tablero.
 * No es estrictamente necesario trabajar con una, pero simplifica el paso de variables
 * y hace mas facil la comprension del codigo.
 */
typedef struct Mano {
    Carta * head;
    Carta * tail;
    int size;
} Mano;

/**
 * Estructura que almacena todos los datos necesarios para simular un tablero.
 * No es estrictamente necesario trabajar con una, pero simplifica el paso de variables
 * y hace mas facil la comprension del codigo.
 */
typedef struct jugador {
    char* nombre;
    Mano* mano;
    int verificador;
    struct jugador * sig;
} jugador;

/**
 * Estructura que almacena todos los datos necesarios para simular un tablero.
 * No es estrictamente necesario trabajar con una, pero simplifica el paso de variables
 * y hace mas facil la comprension del codigo.
 */
typedef struct Turnos {
    jugador * head;
    jugador * tail;
    int size;
} Turnos;

/////////////////////////////////////////////////
/// Definicion De Firmas de Funciones
/////////////////////////////////////////////////

/**
* Inicializa la estructura y le da valores iniciales
*
* @return 	list
*/
Mano * crearMano();

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @param 	int 	valor 		    Variable para guardar numero de columnas ingresadas por usuario.
* @return 	void
*/
void agregarCarta(Mano * list,int valor);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @return 	void
*/
void mostrarMano(Mano * list);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @param 	int 	pos 	    	Variable para guardar numero de columnas ingresadas por usuario.
* @return 	void
*/
int buscarCarta(Mano * list,int pos);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @param 	int 	valor     		Variable para guardar numero de columnas ingresadas por usuario.
* @return 	void
*/
Mano * borrarDeMano(Mano * list,int valor);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @return 	void
*/
int obtenerPrimerValor(Mano * list);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @return 	void
*/
int obtenerUltimoValor(Mano * list);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @return 	void
*/
int obtenerAleatorio(Mano * list);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @return 	void
*/
void EliminarPares(Mano * list);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Mano 	list 			Variable para guardar numero de filas ingresadas por usuario.
* @return 	void
*/
Mano * revolverMano(Mano * list);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @return 	void
*/
Turnos * crearTurnos();

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Turnos*	list 			Variable para guardar numero de filas ingresadas por usuario.
* @param 	char* 	nombre  		Variable para guardar numero de columnas ingresadas por usuario.
* @return 	void
*/
void agregarJugador(Turnos * list,char* nombre);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @param 	Turnos*	list 			Variable para guardar numero de filas ingresadas por usuario.
* @return 	void
*/
void mostrarJugador(Turnos * list);

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @return 	void
*/
void revolverMazo();

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @return 	void
*/
void mostrarMazo();

/**
* Recibe entrada de datos necesarios para generar campo de juego.
*
* @return 	void
*/
void iniciar();

#endif
