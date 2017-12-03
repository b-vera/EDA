#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "listas.h"
#include "hashing.h"

void menu() {

    int opcion,i,j,contador;
    char mayorEsp,mayorOtro;

    // Escritura de archivos
    FILE *fp,*matrizEspanol,*matrizOtro,*patrones;
    fp             = fopen ("Palabras.out","w");
    matrizEspanol  = fopen ("matrizEspanol.out","w");
    matrizOtro     = fopen ("matrizOtro.out","w");
    patrones       = fopen ("patrones.out","w");

    // creacion arbol AVL
    AVL *arbol = NULL;
    arbol = crearAVL();
    leerArchivo(arbol);

    // tabla hash en espanol
    Lista ** arregloEsp;
    arregloEsp = (Lista**)calloc(27,sizeof(Lista*));
    for(i = 0; i < 27; i++){
        arregloEsp[i] = crearLista();
    }
    inOrdenHashEsp(arbol->rootEsp,arregloEsp);
    imprimirHashEsp(arregloEsp,matrizEspanol);

    // tabla hash en otro idioma
    Lista ** arregloOtro;
    arregloOtro = (Lista**)calloc(27,sizeof(Lista*));
    for(j = 0; j < 27; j++){
        arregloOtro[j] = crearLista();
    }
    inOrdenHashOtro(arbol->rootOtros,arregloOtro);
    imprimirHashOtro(arregloOtro,matrizOtro);

    // busqueda letra que se repite mas
    mayorEsp   = buscarMayorEsp(arregloEsp);
    mayorOtro = buscarMayorOtro(arregloOtro);
    fprintf(patrones,"******************************\n\n");
    fprintf(patrones, "letra con que comienzan mas palabras en espanol : %c\n",mayorEsp );
    fprintf(patrones, "letra con que comienzan mas palabras en otro idioma : %c\n\n",mayorOtro );

    // indices de la matriz
    indicesPalabras(arregloEsp,patrones);

    // variables para arbol AVL
    char *palabraIn,*palabraOut,*palabraAnterior,*value;
    value           = (char*)calloc(20,sizeof(char));
    palabraIn       = (char*)calloc(20,sizeof(char));
    palabraOut      = (char*)calloc(20,sizeof(char));
    palabraAnterior = (char*)calloc(20,sizeof(char));

    // Menu Principal
    do {
        printf("\n   ###############  TRADUCTOR / DICCIONARIO  ###############\n");
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

    printf("\n   Se crearon los archivos: \n\n      - matrizEspanol.out\n      - matrizOtro.out\n      - patrones.out\n\n");

    fclose(fp);
    fclose(matrizEspanol);
    fclose(matrizOtro);
    fclose(patrones);
    // se libera la memoria
    free(value);
    free(palabraIn);
    free(palabraOut);
    free(palabraAnterior);

    // se libera la memoria del arbol AVL
    liberarMemoria(arbol->rootEsp);
}
