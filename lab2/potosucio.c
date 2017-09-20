#include <stdio.h>

void iniciar(){

    char nombreUsuario[20];
    int cantJugadores,rivalElegido;

    printf("Ingrese Nombre de Usuario: \n");
    scanf("%s\n",nombreUsuario);

    printf("Ingrese Cantidad de Jugadores: \n");
    scanf("%s\n",cantJugadores);
    if (cantJugadores == 1) {
        printf("Escoja su Rival: \n");
        scanf("%d\n",rivalElegido);
    }

    switch(rivalElegido){
    case 1:
        //operaciones a realizar en caso de que a valga 0;
        break;
    case 2:
        //mismo proceso
        break;
    case 3:
        //blabla
        break;
    default:
        //en caso de que no se de ninguna de las anteriores hacer...
    }
}

int main(){
}
