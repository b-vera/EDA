#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

void menu() {

    int opcion;

    FILE *fp;
    fp = fopen ("Palabras.out","w");

    AVL *arbol = NULL;
    arbol = crearAVL();
    leerArchivo(arbol);

    char *palabraIn,*palabraOut,*palabraAnterior,*value;
    value           = (char*)calloc(20,sizeof(char));
    palabraIn       = (char*)calloc(20,sizeof(char));
    palabraOut      = (char*)calloc(20,sizeof(char));
    palabraAnterior = (char*)calloc(20,sizeof(char));

    do {
        printf("\n   ###############  TRADUCTOR  ###############\n");
        printf( "\n   1. Traducir palabra de espanol a otro idioma.");
        printf( "\n   2. Traducir palabra de otro idioma a espanol");
        printf( "\n   3. Consultar significado de una palabra.");
        printf( "\n   4. Entregar informacion de todo el arbol en espanol.");
        printf( "\n   5. Entregar informacion de todo el arbol en ingles.");
        printf( "\n   6. Salir." );
        printf( "\n\n   Introduzca opcion (1-6): ");

        scanf("%s",value);
        opcion = atoi(value);

        switch ( opcion ) {

            case 1: printf("\n   Escoja una palabra en espanol a traducir: ");
                    scanf("%s",palabraIn);
                    strcpy(palabraAnterior,palabraOut);
                    buscarPalabraEsp(arbol->rootEsp,palabraIn,palabraOut);
                    if (strcmp(palabraOut,"")==0 || strcmp(palabraOut,palabraAnterior)==0) {
                        printf("\n   No se encuentra la palabra.\n");
                    } else {
                        printf("\n   La traduccion es: %s\n",palabraOut);
                    }
                    break;

            case 2: printf("\n   Escoja una palabra en otro idioma a traducir: ");
                    scanf("%s",palabraIn);
                    strcpy(palabraAnterior,palabraOut);
                    buscarPalabraOtro(arbol->rootOtros,palabraIn,palabraOut);
                    if (strcmp(palabraOut,"")==0 || strcmp(palabraOut,palabraAnterior)==0) {
                        printf("\n   No se encuentra la palabra.\n");
                    } else {
                        printf("\n   La traduccion es: %s\n",palabraOut);
                    }
                    break;

            case 3: printf("\n   Escoja una palabra a definir: ");
                    scanf("%s",palabraIn);
                    strcpy(palabraAnterior,palabraOut);
                    buscarDefinicion(arbol->rootEsp,palabraIn,palabraOut);
                    if (strcmp(palabraOut,"")==0 || strcmp(palabraOut,palabraAnterior)==0) {
                        printf("\n   No se encuentra la palabra.\n");
                    } else {
                        printf("\n   La Definicion es: %s\n",palabraOut);
                    }
                    break;

            case 4: printf("\n   Presione 6 para salir del programa y ver el archivo generado. \n");
                    inOrdenEsp(arbol->rootEsp,fp);
                    break;

            case 5: printf("\n   Presione 6 para salir del programa y ver el archivo generado. \n");
                    inOrdenOtro(arbol->rootOtros,fp);
                    break;

         }

    } while ( opcion != 6 );

    fclose(fp);

    // se libera la memoria
    free(value);
    free(palabraIn);
    free(palabraOut);
    free(palabraAnterior);

    // se libera la memoria del arbol AVL
    liberarMemoria(arbol->rootEsp);
}
