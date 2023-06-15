#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char str[] = "HOLA";    
    int n;  

    n = 0;

    while ( n < strlen(str) ) {

        printf ("%c", str[n]);

        n++;

    }

    printf ("\n");

    return (0);

}
