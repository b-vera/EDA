#include <stdio.h>
#include <stdlib.h>

//estructura perro
struct perro{
    char* nombre;
    int edad;
    struct perro * sig;
};


//pasar por referncia
//funcion(&valor)
//void funcion(tipo ** p)
// se le pone el puntero (*) en toda la funcion

//definir el tipo de dato struct bajo el nombre de perrito
typedef struct perro perrito;

//firmar funciones
void agregarPerrito(perrito ** primero);
void mostrarPerritos(perrito * primero);
void borrarNombre(perrito ** primero);
void borrarEdad(perrito ** primero);

perrito * p = NULL;

void agregarPerrito(perrito ** p){
    perrito * n;
    n = (perrito*)malloc(sizeof(perrito));
    printf("ingrese numero:");
    scanf("%i\n",&(n->edad));
    n->sig = *p;
    *p=n;
}

void mostrarPerritos(perrito * p ){
    while (p!=NULL) {
        printf("%d\n",p->edad );
        p=p->sig;
    }
}

int main(){
    agregarPerrito(&p);
    agregarPerrito(&p);
    agregarPerrito(&p);
    agregarPerrito(&p);
    agregarPerrito(&p);
    mostrarPerritos(p);
}
