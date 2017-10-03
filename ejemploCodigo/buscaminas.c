#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buscaminas.h"

void pedirEntrada(int * filas, int * columnas, int * cantidadMinas) {
	int entradaValida = 0;
		
	printf("[ > ] Ingrese dimensiones del tablero (filas columnas): ");
	scanf("%d %d", filas, columnas);

	*cantidadMinas = 0;

	while (*cantidadMinas == 0 || *cantidadMinas - 2 > (*filas)*(*columnas)) {

		if (entradaValida++) {
			printf("[ ! ] Entrada no valida!\n");
		}

		printf("[ > ] Ingrese cantidad de minas en el tablero: ");
		scanf("%d", cantidadMinas);
	}
}

Tablero * jugadaInicial(int filas, int columnas, int cantidadMinas) {
	
	int xInicial,				//< Posicion de la fila en la jugada inicial.
		yInicial,				//< Posicion de la columna en la jugada inicial.
		i, j,					//< Variables auxiliares.
		jugadaValida = 0;		//< Determina si la jugada (coordenadas + tipo de juegada) es valida.
	char tipoJugada;			//< Tipo de Jugada: 'X' => Posicionar una bandera, 'O' => Descubrir casilla.

	do {
		system(CLEAR_SCREEN);
		printf(GAME_NAME);
		mostrarTableroVacio(filas, columnas);

		if (jugadaValida++) {
			printf("[ ! ] Jugada no valida!\n");
		}

		printf("[ > ] Ingrese jugada en el formato 'fila columna tipo' (Ej: 2 3 X): ");
		scanf("%d %d %c", &xInicial, &yInicial, &tipoJugada);
		
		xInicial--;
		yInicial--;

	} while (xInicial < 0 || yInicial < 0 || xInicial > filas || yInicial > columnas || (tipoJugada != 'X' && tipoJugada != 'O'));

	//
	// Pedir Espacio (inicializar)
	//
	Tablero * t 		= (Tablero *)malloc(sizeof(Tablero));
	t->numeroFilas 		= filas;
	t->numeroColumnas 	= columnas;
	t->cantidadMinas 	= cantidadMinas;
	t->campo 			= (int**)calloc((size_t)filas, sizeof(int*));
	t->campoVisible 	= (char**)calloc((size_t)filas, sizeof(char*));

	for (i = 0; i < filas; ++i) {
		t->campo[i] 		= (int*)calloc((size_t)columnas, sizeof(int));
		t->campoVisible[i] 	= (char*)calloc((size_t)columnas, sizeof(char));
	}
	
	//
	// Inicializar a '#' todas las casillas del campo visible
	//	
	for (i = 0; i < filas; ++i) {
		for (j = 0; j < columnas; ++j) {
			t->campoVisible[i][j] = '#';
		}
	}

	//
	// Ingresar minas en campo
	//
	srand(time(NULL));
	int random;
	while (cantidadMinas) {
		random = rand() % (filas * columnas);

		i = random / filas;
		j = random % columnas;

		// primer elemento debe ser vacio.
		if (i == xInicial && j == yInicial) {
			continue;	
		}

		if (t->campo[i][j] != 1) {
			t->campo[i][j] = 1;
			cantidadMinas--;
		}
	}

	//
	// Crear archivo solucion
	//
	FILE * out = fopen("solucion.out", "w");
	int suma = 0;
	
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (t->campo[i][j] == 1) {
				fprintf(out, "%3c", 'M');
			} else {
				suma = sumarAlrededor(t,i,j);
				suma = suma ? suma + '0' : '.';
				fprintf(out, "%3c", suma);
			}
		}
		fprintf(out, "\n");
	}

	fclose(out);

	//
	// Expandir primera jugada. 
	//
	descubrir(t, xInicial, yInicial);
	return t;
}

void mostrarCampo(Tablero * t) {
	int i,j;
	
	system(CLEAR_SCREEN);
	printf(GAME_NAME);

	// numeros de columnas + barra '----'
	printf("    |");
	for (j = 1; j <= t->numeroColumnas; j++) {
		printf("%3d", j);
	}
	printf("\n----|");
	for (j = 0; j < t->numeroColumnas; j++) {
		printf("---");
	}
	printf("\n");

	// filas con indices a su izquierda 'indice | # # # ...'
	for (i = 0; i < t->numeroFilas; i++) {
		printf("%3d |", i+1);	
		for (j = 0; j < t->numeroColumnas; j++) {
			printf("%3c", t->campoVisible[i][j]);
		}
		printf("\n");
	}

	// Mensaje para cerrar el juego.
	printf(GAME_QUIT_MSG);
}

int jugarTurno(Tablero * t){
	int fila, columna;
	char tipo;
	int jugadaValida = 0;

	do {
		if (jugadaValida++) {
			printf("[ ! ] Jugada no valida!\n");
		}
		printf("[ > ] Ingrese jugada en el formato 'fila columna tipo' (Ej: 2 3 X): ");
		scanf("%d %d %c", &fila, &columna, &tipo);
		fila--;
		columna--;
	} while (fila < 0 || columna < 0 || fila > t->numeroFilas || columna > t->numeroColumnas || (tipo != 'X' && tipo != 'O'));

	//
	// PONER BANDERA
	//
	if (tipo == 'X'){
		if (t->campoVisible[fila][columna] == 'B'){
			t->campoVisible[fila][columna] = '#';
		} else {
			t->campoVisible[fila][columna] = 'B';
		}
		return GAME_CONTINUE;
	} 
	//
	// DESCUBRIR
	// caso 1: Hay bomba
	// caso 2: Expandir
	//
	else if (t->campo[fila][columna] == 1) {
		mostrarMinasEnTablero(t);
		mostrarCampo(t);
		return GAME_OVER;
	}
	
	descubrir(t, fila, columna);
	return revisarFinDelJuego(t);
}

void liberarTablero(Tablero * t) {
	int i;
	for (i = 0; i < t->numeroFilas; i++) {
		free(t->campo[i]);
		free(t->campoVisible[i]);
	}
	free(t->campo);
	free(t->campoVisible);
}

int descubrir(Tablero * t, int fila, int columna) {

	if (t->campoVisible[fila][columna] == '#') {
		int suma = sumarAlrededor(t, fila, columna);
		if (suma > 0) {
			t->campoVisible[fila][columna] = '0' + suma;
			return 1;
		}

		t->campoVisible[fila][columna] = ' ';

		// arriba
		if (fila > 0 && t->campoVisible[fila-1][columna] == '#') {
			descubrir(t, fila-1, columna);
		}

		// arriba-derecha
		if (fila > 0 && columna < t->numeroColumnas - 1 && t->campoVisible[fila-1][columna+1] == '#') {
			descubrir(t, fila-1, columna+1);
		}
		// derecha
		if (columna < t->numeroColumnas - 1 && t->campoVisible[fila][columna+1] == '#') {
			descubrir(t, fila, columna+1);
		}
		// abajo-derecha
		if (fila < t->numeroFilas - 1 && columna < t->numeroColumnas && t->campoVisible[fila+1][columna+1] == '#') {
			descubrir(t, fila+1, columna+1);
		}
		// abajo
		if (fila < t->numeroFilas - 1 && t->campoVisible[fila+1][columna] == '#') {
			descubrir(t, fila+1, columna);
		}
		// abajo-izquierda
		if (fila < t->numeroFilas - 1 && columna > 0 && t->campoVisible[fila+1][columna-1] == '#') {
			descubrir(t, fila+1, columna-1);
		}
		// izquierda
		if (columna > 0 && t->campoVisible[fila][columna-1] == '#') {
			descubrir(t, fila, columna-1);
		}
		// arriba-izquierda
		if (fila > 0 && columna > 0 && t->campoVisible[fila-1][columna-1] == '#') {
			descubrir(t, fila-1, columna-1);
		}
	}
	
	return 0;
}

void mostrarMinasEnTablero(Tablero * t) {
	int i, j;
	
	for (i = 0; i < t->numeroFilas; i++) {
		for (j = 0; j < t->numeroColumnas; j++) {
			if (t->campo[i][j] == 1) {
				t->campoVisible[i][j] = 'M';
			}
		}
	}
}

int revisarFinDelJuego(Tablero * t) {
	int i, j;

	for (i = 0; i < t->numeroFilas; i++) {
		for (j = 0; j < t->numeroColumnas; j++) {
			// No es Mina y esta cubierta => continuar
			if (t->campo[i][j] != 1 && t->campoVisible[i][j] == '#') {
				return GAME_CONTINUE;
			}
		}
	}

	return GAME_WIN;
}

void mostrarTableroVacio(int filas, int columnas) {
	system(CLEAR_SCREEN);
	int i, j;

	printf(GAME_NAME);
	printf("    |");
	
	for (j = 1; j <= columnas; j++) {
		printf("%3d", j);
	}
	printf("\n----|");
	for (j = 0; j < columnas; j++) {
		printf("---");
	}
	
	printf("\n");
	
	for (i = 1; i <= filas; i++) {
		printf("%3d |", i);
		for (j = 0; j < columnas; j++) {
			printf("%3c", '#');
		}
		printf("\n");
	}
	
	printf(GAME_QUIT_MSG);
}

int sumarAlrededor(Tablero * t, int fila, int columna) {
	int totalMinas = 0;

	// arriba
	if (fila > 0 && t->campo[fila-1][columna] == 1) {
		totalMinas++;
	}
	// arriba-derecha
	if (fila > 0 && columna < t->numeroColumnas - 1 && t->campo[fila-1][columna+1] == 1) {
		totalMinas++;
	}
	// derecha
	if (columna < t->numeroColumnas - 1 && t->campo[fila][columna+1] == 1) {
		totalMinas++;
	}
	// abajo-derecha
	if (fila < t->numeroFilas - 1 && columna < t->numeroColumnas && t->campo[fila+1][columna+1] == 1) {
		totalMinas++;
	}
	// abajo
	if (fila < t->numeroFilas - 1 && t->campo[fila+1][columna] == 1) {
		totalMinas++;
	}
	// abajo-izquierda
	if (fila < t->numeroFilas - 1 && columna > 0 && t->campo[fila+1][columna-1] == 1) {
		totalMinas++;
	}
	// izquierda
	if (columna > 0 && t->campo[fila][columna-1] == 1) {
		totalMinas++;
	}
	// arriba-izquierda
	if (fila > 0 && columna > 0 && t->campo[fila-1][columna-1] == 1) {
		totalMinas++;
	}

	return totalMinas;
}
