#include <stdio.h>

int main(){
	printf ("\n\n********** Inicio del Programa **********\n\n");

	char nombre1 [20], nombre2 [20];
	int edad1, edad2;

	printf ("\nIngrese el nombre y edad de la primera persona: ");
	scanf("%s",&nombre1);
	scanf("%d",&edad1);
	
	printf ("\n\nIngrese el nombre de la segunda persona: ");
	scanf("%s",&nombre2);
	printf ("\nIngrese la edad de la segunda persona: ");
	scanf("%d",&edad2);

	if (edad1 > edad2){
		printf("El mayor es 1 %s",nombre1);
	}	
	else if (edad1 < edad2){
		printf("El mayor es 2 %s",nombre2);
	}
	else {
		printf("%s y %s tienen la misma edad",nombre1,nombre2);
	}
	
	
	printf ("\n\n********** Fin del Programa **********\n\n");

	return 0;
}