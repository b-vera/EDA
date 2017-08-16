#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define SINBOMBA -1
#define BOMBA -2
#define GANAR -3
#define PERDER -4


void tablero(int filas,int columnas) {
    int mayor = 0;
    int cifras = 1;
    if(filas>mayor){
        mayor = filas;
    }else {
        mayor = columnas;
    }
    while(mayor/10>0){
        mayor=mayor/10;
        cifras++;
    }

    for (int x = 0; x <= filas; x++) {
        //imprime columna x
        if (x==0) {
            printf("  ");
        }else{
            
            printf("%i ",x);
        }
        for (int y = 0; y <= columnas; y++) {
            //imprime filas iniciales
            if ((x==0 && y !=0) || (x==0 && y == 0)) {
                printf("%i ",y);
            }else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas,cantMinas;

    printf("Ingrese cantidad de filas y columnas:");
    scanf("%i  %i",&filas,&columnas);

    printf("Ingrese la cantidad de minas:");
    scanf("%i",&cantMinas);

    tablero(filas,columnas);

return 0;
}
