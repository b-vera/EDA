#include <stdio.h>

void cicloWhile();
void cicloDoWhile();
void cicloFor();


void cicloWhile(){
	int i = 0;
	while(i<=10){
		printf("%i ",i);
		i++;
	}
	return;
}

void cicloDoWhile(){
	int i = 0;
	do{
		printf("%i ",i);
		i++;
	}while(i<=10);
	return;
}


void cicloFor(){
	int i;
	for(i=0;i<=10;i++){
		printf("%i ",i);
	}
	return;
}

int main(){
	printf("\n\n********* Inicio del programa *********\n\n");
	printf("\n\nCon while:\n");
	cicloWhile();
	printf("\n\nCon do while:\n");
	cicloDoWhile();
	printf("\n\nCon for:\n");
	cicloFor();


	printf("\n\n********* Fin del programa *********\n\n");
	return 0;
}