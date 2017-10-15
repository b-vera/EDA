#include <stdio.h>
#include "matriz.c"

void iniciar() {

    int cantVertices;

    grafoMatriz matriz;
    grafoMatriz * ptr;
    ptr = &matriz;

    int prueba = 5;
    iniciarMatriz(ptr,prueba);
    imprimirMatriz(ptr,prueba);
    liberarMemoria(ptr,prueba);


}
int main() {
    iniciar ();
    return 0;
}
