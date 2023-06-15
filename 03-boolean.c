#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 109
// TODO LO QUE DEVUELVA CERO ES FALSO Y LO QUE DEVUELVE DISTINTO DE CERO ES VERDADERO

int main ()
{
    int n1 = 10;
    int n2 = 20;

    // VER QUE PASA CON ESTO:
    // if ( n1 = n2 ) {
    if ( n1 == n2 || n2 == 20) {

        printf ("VERDADERO\n");

    } else {

        printf ("FALSO\n");
    }

    return (0);

}
