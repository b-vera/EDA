#include <stdio.h>

int suma(int a, int b){
	return a+b;
}


int main (){
	printf("\n\n********* Inicio del programa *********\n\n");
	
	int sumando1, sumando2, resultado;
	printf("Ingrese un numero: ");
	scanf("%d",&sumando1);
	
	printf("\nIngrese otro numero: ");
	scanf("%d",&sumando2);
	
	resultado = suma(sumando1,sumando2);
	
	printf("\n\nEl resulado es %d", sumando1 + sumando2);
	printf("\n\nEl resulado es %d", suma(sumando1,sumando2));
	printf("\n\nEl resulado es %d", resultado);

	printf("\n\n********* Fin del programa *********\n\n");

	return 0;

}