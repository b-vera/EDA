#include <stdio.h>



int main (){
	int valor;
	FILE *archivoEntrada;
	
	archivoEntrada = fopen("Entrada.in","r");
	
	fscanf(archivoEntrada,"%d",&valor);
	fclose(archivoEntrada);
	
	FILE *archivoSalida;
	archivoSalida = fopen("Salida.out","w");
	fprintf(archivoSalida,"%d",valor * 3);
	fclose(archivoSalida);
	
	return 0;

}