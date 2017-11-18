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
        equilibrarEsp(arbol->rootEsp);
        insertarNodoOtros(arbol,str1,str2,str3);
        equilibrarOtros(arbol->rootOtros);
    }
	fclose(fp);
    free(str1);
    free(str2);
    free(str3);
}

int main() {
    AVL *arbol = NULL;
    arbol = crearAVL();
    leerArchivo(arbol);
    inOrdenEsp (arbol->rootEsp);
    inOrdenOtro(arbol->rootOtros);
    printf("altura arbol esp = %d\n",alturaEsp(arbol->rootEsp));
    printf("diferencia alturas es = %d\n",diferenciaAlturasEsp(arbol->rootEsp));
    printf("altura arbol otro = %d\n",alturaOtro(arbol->rootOtros));
    printf("diferencia alturas es = %d\n",diferenciaAlturasOtros(arbol->rootOtros));
    return 0;
}
