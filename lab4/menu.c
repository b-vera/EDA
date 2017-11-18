#include <stdio.h>
#include <math.h>

void menu() {
    int n, opcion;
    do {
        printf("\n   ###############  TRADUCTOR  ###############\n");
        printf( "\n   1. Traducir palabra de espanol a otro idioma.");
        printf( "\n   2. Traducir palabra de otro idioma a espanol");
        printf( "\n   3. Consultar significado de una palabra.");
        printf( "\n   4. Entregar informacion de todo el arbol (espanol-ingles).");
        printf( "\n   5. Salir." );
        printf( "\n\n   Introduzca opcion (1-5): ");

        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: printf( "\n   Introduzca un n%cmero entero: ", 163 );
                    scanf( "%d", &n );
                    printf( "\n   El doble de %d es %d\n\n", n, n * 2 );
                    break;

            case 2: printf( "\n   Introduzca un n%cmero entero: ", 163 );
                    scanf( "%d", &n );
                    printf( "\n   La mitad de %d es %f\n\n", n, ( float ) n / 2 );
                    break;

            case 3: printf( "\n   Introduzca un n%cmero entero: ", 163 );
                    scanf( "%d", &n );
                    printf( "\n   El cuadrado de %d es %d\n\n", n, ( int ) pow( n, 2 ) );

            case 4: printf( "\n   Introduzca un n%cmero entero: ", 163 );
                    scanf( "%d", &n );
                    printf( "\n   El cuadrado de %d es %d\n\n", n, ( int ) pow( n, 2 ) );
         }

    } while ( opcion != 5 );
}
