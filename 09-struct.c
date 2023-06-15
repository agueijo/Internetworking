#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    struct tipo_alumnos {
        int legajo;
        char nombre[100];
    };

    struct tipo_alumnos alu1;
    struct tipo_alumnos *alu2;

    alu1.legajo = 1001;
    sprintf ( alu1.nombre , "Pepe" );

    printf ("Alumno1 es: legajo: %d nombre %s \n", alu1.legajo, alu1.nombre );

    alu2 = &alu1;

    printf ("Alumno2 es: legajo: %d nombre %s \n", (*alu2).legajo, (*alu2).nombre );
    
    printf ("Alumno2 es: legajo: %d nombre %s \n", alu2->legajo, alu2->nombre );

    return (0);

}
