#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void saludo(){
	char nombre[10];
	printf("ingrese su nombre:");
	scanf("%s",nombre);
	printf("hola, %s\n",nombre);
}

void circulo(){
	float radio=0;
	float PI = 3.14;
	float area, perimetro;
	printf("ingrese radio del circulo:");
	scanf("%f",&radio);

	area = PI * pow(radio,radio);
	perimetro = 2 * PI * radio;

		printf("perimetro = %f\n",perimetro);
		printf("area = %f\n",area);
}

void promedio(){

	int nota1,nota2,nota3,nota4,promedio;
	printf("Ingrese primera nota: ");
	scanf("%i",&nota1);
	printf("Ingrese segunda nota: ");
	scanf("%i",&nota2);
	printf("Ingrese tercera nota: ");
	scanf("%i",&nota3);
	printf("Ingrese cuarta nota: ");
	scanf("%i",&nota4);
	promedio = (nota1+nota2+nota3+nota4)/4;
	printf("el promedio es: %i",promedio );
}

void conversor(){
	int centimetros;
	double respuesta;
	double pulgadas = 2.54;
	printf("ingrese longitud:");
	scanf("%i",&centimetros);
	respuesta=centimetros/pulgadas;
	printf("%i cm = %f in",centimetros,respuesta);

}

void invertido(){
	int numero,centesima,decima,unidad;
	printf("ingrese numero:");
	scanf("%i",&numero);
	centesima = numero/100;
	decima = (numero%100)/10;
	unidad = (numero%100)%10;
	printf("%i%i%i\n",unidad,decima,centesima);
}
void pitagoras(){
	int cateto1,cateto2,suma;
	float hipotenusa;
	printf("Ingrese cateto 1:");
	scanf("%i",&cateto1);
	printf("Ingrese cateto 2:");
	scanf("%i",&cateto2);
	suma=pow(cateto1,2)+pow(cateto2,2);
	hipotenusa=sqrt(suma);
	printf("La hipotenusa es: %f",hipotenusa );
}

void hora(){
	int actual,agregada,suma,nueva;
	printf("Hora actual:");
	scanf("%i",&actual);
	printf("Cantidad de Horas:");
	scanf("%i",&agregada);
	suma = actual + agregada;
	nueva = suma%24;
	printf("en %i horas, el reloj marca las %i\n",agregada,nueva);
}

void decimal(){
	float numero,nuevo;
	int unidad;
	printf("Ingrese un numero:");
	scanf("%f",&numero);
	unidad= numero/1;
	nuevo=fabs(numero-unidad);
	printf("%.4f\n",nuevo);
}

void nota(){
	int nota1,nota2,lab,final;
	printf("Ingrese nota certamen 1:");
	scanf("%i",&nota1);
	printf("Ingrese nota certamen 2:");
	scanf("%i",&nota2);
	printf("Ingrese nota laboratorio:");
	scanf("%i",&lab);
	final = (((60-lab*0.3)/0.7)*3)-nota1-nota2;
	printf("necesita nota %i en el certamen 3\n",final);
}
void telegrafo() {
	char mensaje[20];
	int i=0;
	int precio=0;
	printf("mensaje:");
	scanf("%[^\n]",mensaje);
	while (mensaje[i]!='\0') {
		printf("%c\n",mensaje[i]);
		if ((90>=mensaje[i] && mensaje[i]>=65) || (122>=mensaje[i] && mensaje[i] >=97 )) {
			precio += 10;
		} else if(57>=mensaje[i]&& mensaje[i]>=48) {
			precio += 20;
		} else if(mensaje[i]==32) {
			precio +=0;
		} else{
			precio += 30;
		}
		i++;
	}
	printf("Su mensaje cuesta $%d\n",precio);
}

void anagrama(char *palabra1,char *palabra2) {
	int i=0;
	int j=0;
	while (palabra1[i]!='\0') {
		while (palabra2[j]!='\0') {
			printf("%c-%c\n",palabra1[i],palabra2[j]);
			j++;
		}
		i++;
		j=0;
	}
}
int main(){
	anagrama("torpes","postre");
	return 0;
}
