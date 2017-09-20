#include <stdio.h>
#include <stdlib.h>

//estructura alumno
struct alumno{
    char* nombre;
    int edad;
    char* carrera;
    int ingreso;
};


int main() {

    struct alumno viru;
    struct alumno * ptr;
    ptr = &viru;
    viru.nombre = (char*)malloc (100*sizeof(char));

    //utilizando punto . me da el dato
    viru.nombre[0] = 'v'; //asignacion utilizando estructura
    ptr->nombre[1] = '\0'; //asignacion utilizando puntero a estructura

}
