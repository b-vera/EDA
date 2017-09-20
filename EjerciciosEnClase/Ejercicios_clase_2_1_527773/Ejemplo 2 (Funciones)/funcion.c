#include <stdio.h>

int main (){
	printf("\n\n********* Inicio del programa *********\n\n");
	
	int sumando1, sumando2;
	printf("Ingrese un numero: ");
	scanf("%d",&sumando1);
	
	printf("\nIngrese otro numero: ");
	scanf("%d",&sumando2);
	printf("\n\nEl resulado es %d", sumando1 + sumando2);

	printf("\n\n********* Fin del programa *********\n\n");

	return 0;

}