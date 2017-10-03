#ifndef _BUSCAMINAS_H_
#define _BUSCAMINAS_H_


//===================================================+
// DEFINICION DE CONSTANTES
//===================================================+
/**
 * Los comandos para limpiar la pantalla son diferentes para Windowsy Linux/OSX
 * Por lo mismo se define una constante en base al SO con el que se esta trabajando,
 * y se hace uso de la funcion system() y la constante para limpiar la pantalla en los
 * diferentes SOs.
 */
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
	#define CLEAR_SCREEN "cls"
#else 
	#define CLEAR_SCREEN "clear"
#endif

#define GAME_NAME 		"~[ BUSCAMINAS ASCII v1.0]~\n\n"
#define GAME_QUIT_MSG 	"\nPresione [Ctrl + C] para salir.\n\n"


//===================================================+
// DEFINICION DE TIPOS DE DATOS
//===================================================+

/**
 * Posibles valores resultante de cualquier jugada.
 * GAME_CONTINUE 	=> El juego continua, es decir, no se ha realizado una jugada concluyente.
 * GAME_OVER 		=> Fin del juego, el usuario ha descubierto una mina.
 * GAME_WIN			=> Fin del juego, el usuario ha descubierto todas las casillas sin bomba.
 */
enum game_status {
	GAME_CONTINUE,
	GAME_OVER,
	GAME_WIN
};

/**
 * Estructura que almacena todos los datos necesarios para simular un tablero.
 * No es estrictamente necesario trabajar con una, pero simplifica el paso de variables
 * y hace mas facil la comprension del codigo.
 */
typedef struct {
	int ** campo;				//< Campo con las posiciones de las bombas, solo permite 0's o 1's
	char ** campoVisible;		//< Campo visible para el usuario, aqui se posicionan banderas y numeros.
	int numeroFilas;			//< Numero de filas del campo.
	int numeroColumnas;			//< Numero de columnas del campo
	int cantidadMinas;			//< Cantidad de minas que contiene el campo.
} Tablero;

//===================================================+
// DEFINICION DE FIRMAS DE FUNCIONES
//===================================================+

/**
 * Recibe entrada de datos necesarios para generar campo de juego.
 *
 * @param 	int 	filas 			Variable para guardar numero de filas ingresadas por usuario.
 * @param 	int 	columnas 		Variable para guardar numero de columnas ingresadas por usuario.
 * @param 	int 	cantidadMinas 	Variable para guardar numero de filas por usuario.
 * @return 	void
 */
void pedirEntrada(int * filas, int * columnas, int * cantidadMinas);

/**
 * Crea una estructura Tablero en base a los parametros "filas", "columnas", "cantidadMinas",
 * Pide memoria para los campos de juego acorde a las variables mencionadas anteriormente;
 * En base a la primera jugada (ingreso de fila-columna-tipoJugada) posiciona las minas.
 * Y genera el archivo "solucion.out" con las posiciones de las minas.
 *
 * @param 	int 	filas 			Numero de filas que poseera el tablero.
 * @param 	int 	columnas 		Numero de columnas que poseera el tablero.
 * @param 	int 	cantidadMinas 	Numero de minas que poseera el tablero.
 * @return Tablero
 */
Tablero * jugadaInicial(int filas, int columnas, int cantidadMinas);

/**
 * Muestra el campo al jugador, notese que este es de tipo char**, y solo se almacenan en este las jugadas.
 *
 * @param 	Tablero 	t 			Estructura Tablero del cual se quiere mostrar "campoVisible".
 * @return 	void
 */
void mostrarCampo(Tablero * t);

/**
 * Pide el ingreso de jugada al usuario y resuelve en base a la entrada, es decir,
 * de ingresar tipo de jugada 'X', marca la posicion con una 'B' que significa BANDERA,
 * de ingresar tipo de jugada 'O', y haber una mina en la posicion termina el juego,
 * en caso contrario descubre las casillas vacias.
 *
 * @param 	Tablero 	t 			Estructura Tablero del cual se quiere mostrar "campoVisible".
 * @return 	int 					Retorna alguno de los valores de (enum) game_status, acorde al resultado de la jugada.
 */
int jugarTurno(Tablero * t);

/**
 * Libera la memoria pedida para el tablero de juego.
 *
 * @param 	Tablero 	t 			Estructura Tablero.
 * @return 	void
 */
void liberarTablero(Tablero * t);



/**
 * Descubre de manera recursiva las casillas vacias comenzando en la posicion ["fila", "columna"].
 *
 * @param 	int 	fila 			Fila la cual se descubrira.
 * @param 	int 	columna 		Columna la cual se descubrira.
 * @return  int						1 de encontrar un numero, 0 en caso contrario.
 */
int descubrir(Tablero * t, int fila, int columna);

/**
 * Descubre todas las minas en el tablero, marcando su posicion con una 'M' en la variable "campoVisible".
  *
 * @param 	Tablero 	t 			Numero de filas que poseera el tablero.
 * @return 	void
 */
void mostrarMinasEnTablero(Tablero * t);

/**
 * Determina si aun existen casillas sin bombas por descubrir.
 * 
 * @param 	Tablero 	t 			Numero de filas que poseera el tablero.
 * @return 	int						GAME_CONTINUE de existir minas por descubrir, en caso contrario GAME_WIN.
 */
int revisarFinDelJuego(Tablero * t);

/**
 * Muestra una matriz de filas x columnas para la primera jugada,
 * este no se almacena en ninguna parte, solo se muestra por pantalla
 *
 * @param 	int 	filas 			Numero de filas que poseera la impresion de la matriz.
 * @param 	int 	columnas 		Numero de columnas que poseera la impresion de la matriz.
 * @return 	void
 */
void mostrarTableroVacio(int filas, int columnas);

/**
 * Cuenta las minas alrededor de la casilla en la fila "fila" y columna "columna".
 * Valores posibles de retorno son [0,8]
 *
 * @param 	Tablero 	t 			Tablero en el cual contar  de filas que poseera el tablero.
 * @param 	int 		fila 		Fila de la casilla.
 * @param 	int 		columna 	Columna de la casilla.
 * @return 	int						Numero de minas en las 8 casillas de alreadedor.
 */
int sumarAlrededor(Tablero * t, int fila, int columna);

#endif