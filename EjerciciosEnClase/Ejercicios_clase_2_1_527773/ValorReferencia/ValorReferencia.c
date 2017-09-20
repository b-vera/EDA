#include <stdio.h>

int cambiarPorValor(int  n){
	n = n +1;
	return n;
}


void cambiarPorReferencia(int * n){
	*n = *n + 1;
}

int main(){
	printf("\n\n******** Inicio del programa ********\n\n");
	int valor1 = 0,valor2 = 0;

	printf("valor1: %d\n",valor1);
	printf("<Cambiar por valor sin asignar>\n");
	cambiarPorValor(valor1);
	printf("valor1: %d\n",valor1);
	/*printf("<Cambiar por valor asignando>\n");
	valor1 = cambiarPorValor(valor1);
	printf("valor1: %d\n",valor1);*/

	printf("\n\n");

	printf("valor2: %d\n",valor2);
	printf("<Cambiar por referencia sin asignar>\n");
	cambiarPorReferencia(&valor2);
	printf("valor2: %d\n",valor2);

	printf("\n\n******** Fin del programa ********\n\n");
	return 0;
}
