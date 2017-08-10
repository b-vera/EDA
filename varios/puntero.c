#include <stdio.h>

int main()
{
int a=10;
int * const p = &a; //objeto variable y puntero constante
*p = 15;

printf("El valor de a es: %d. \nEl valor de *puntero es: %d. \n",a,*p);


return 0;
}
