#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void leerArchivo(AVL *arbol){
    char *str1, *str2, * str3;
    str1 = (char*)malloc(sizeof(char)*100);
    str2 = (char*)malloc(sizeof(char)*100);
    str3 = (char*)malloc(sizeof(char)*100);

    FILE *fp;
    fp = fopen ("Diccionario.in","r");
    while (!feof(fp)){
        fscanf(fp, "%s %s %[^\n]", str1, str2, str3);
        insertarNodoEsp(arbol,str1,str2,str3);
        equilibrarEsp(arbol,arbol->rootEsp);
        insertarNodoOtros(arbol,str1,str2,str3);
        equilibrarOtros(arbol,arbol->rootOtros);
    }
	fclose(fp);
    free(str1);
    free(str2);
    free(str3);
}

void escribirArchivo(AVL *arbol){
    FILE *fp;
    fp = fopen ("Diccionario.in","w");
    // utilizar in orden pero en vez de printf usar fprintf(archivoSalida,"%d",valor * 3);
    fclose(fp);
}

int main() {
    menu();
    AVL *arbol = NULL;
    arbol = crearAVL();
    leerArchivo(arbol);
    inOrdenEsp (arbol->rootEsp);
    printf("\n");
    inOrdenOtro(arbol->rootOtros);
    return 0;
}
