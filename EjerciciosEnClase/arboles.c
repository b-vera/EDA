#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int N;
    struct nodo * hI;
    struct nodo * hD;
} nodo;

//x = numero a insertar
//R = nodo raiz
void mostrar( nodo * );
void min(nodo*);
void max(nodo*);
void sucesor(nodo*);
void antecesor(nodo*);


void insertar( nodo ** R,int x ) {
    //pedir memoria
    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    //asignarlo
    nuevo->N = x;
    nuevo->hI = NULL;
    nuevo->hD = NULL;

    if ( *R == NULL ) {
        *R = nuevo;
    } else {
        nodo * actual = *R;
        nodo * padre = actual;
        while (actual != NULL) {
            padre = actual;
            if ( actual->N < nuevo->N ) {
                actual = actual->hD;
            } else {
                actual = actual->hI;
            }
        }
        if ( padre->N < nuevo->N ) {
            padre->hD = nuevo;
        } else {
            padre->hI = nuevo;
        }
    }
}

int main() {

    nodo * raiz = NULL;
    insertar(&raiz,3);
    printf("asda\n");
    // insertar(&raiz,2);
    insertar(&raiz,6);
    // insertar(&raiz,3);
    insertar(&raiz,9);
    insertar(&raiz,8);
    mostrar(raiz);
    min(raiz);
    max(raiz);
    sucesor(raiz);

    return 0;

}
void mostrar(nodo * R) {
    if (R == NULL) {
        return;
    }

    printf("%d\n", R->N);

    if (R->hI) {
        mostrar(R->hI);
    }

    if (R->hD) {
        mostrar(R->hD);
    }
}

void min(nodo * R) {
    if (R == NULL) {
        return;
    }
    while (R->hI != NULL) {
        R = R->hI;
    }
    printf("min = %d\n",R->N);
}

void max(nodo * R) {
    if (R == NULL) {
        return;
    }
    while (R->hD != NULL) {
        R = R->hD;
    }
    printf("max = %d\n",R->N);
}

void sucesor(nodo * R) {
    if (R == NULL) {
        return;
    }
    R = R->hD;
    return min(R);

}

void antecesor(nodo * R) {
    if (R == NULL) {
        return;
    }
    R = R->hI;
    return max(R);
}
/*
void padre() {
}

void borrar() {
}
*/
