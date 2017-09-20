#include<stdio.h>


int buscarMenor(int a[],int n){
	int i;
	int menor = a[0];
	for (i=1;i<n;i++){
		if (menor > a[i]){
			menor = a[i];
		}
	}
	return menor;
}

int buscarMayor(int *a,int n){
	int i;
	int mayor = a[0];
	for (i=1;i<n;i++){
		if (mayor < a[i]){
			mayor = a[i];
		}
	}
	return mayor;
}


int main(){

	printf("\n\n*********** Inicio del Programa ***********\n\n");


	int arreglo[5];
	int	i, mayor, menor,n;
	n=5; // Cantidad de datos
	
	printf("Debe ingresar %d numeros enteros", n);
	for (i = 0; i<n;i++){
		printf("\n	%d.- Ingrese un numero: ",i+1);
		scanf("%d",&arreglo[i]);
	}
	
	
	mayor = buscarMayor(arreglo, n);
	menor = buscarMenor(arreglo, n);
	
	printf("\n\nLos numeros ingresados fueron: ");

	i=0;
	printf("\n	%d", arreglo[i]);
	i++;
	while(i<n-1){
		printf(", %d", arreglo[i]);
		i++;
	}
	printf(" y %d", arreglo[i]);

	printf("\n	El numero menor es: %d", menor);
	printf("\n	El numero mayor es: %d", mayor);

	printf("\n\n*********** Fin del Programa ***********\n\n");

	return 0;
}