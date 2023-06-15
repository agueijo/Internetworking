#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERLEN 1024

int main ()
{
    char buffer[BUFFERLEN];
    int op;

    printf ("Ingrese un texto por teclado: ");
    
    fgets ( buffer , BUFFERLEN , stdin );
    buffer[ strlen(buffer) -1 ] = '\0';

    op = atoi(buffer);

    printf( "La longitud de ese string es %ld\n", strlen(buffer) );

    printf ("Usted ingreso lo siguiente: %s y convertido a nuemro es %d\n", buffer, op ); 

    return (0);

}
