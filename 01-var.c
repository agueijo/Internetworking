#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int n1,n2;
    int n3 = 30;
    char letra;
    int vector[5];
    char string[10];
    char s1[] = "CHAU";
    char s2[50];

    n1 = 10;
    n2 = n1 + 10;

    n3++;

    n3+=5;

    n2--;

    vector[0] = 65;
    vector[1] = 66;
    vector[2] = 67;
    vector[3] = 68;
    vector[4] = 69;

    // ERROR EL ARRAY TIENE 5 POCICIONES DE 0..4 
    // vector[5] = 99;

    printf("Valor de la variable n1=%d n2=%d y n3=%d \n", ++n1, n2, n3 );

    letra = 'A';

    printf("Valor \\ de %% la letra %c y la letra %c\n", letra , 66 );

    printf("%c\n", vector[0] );
    printf("%c\n", vector[1] );
    printf("%c\n", vector[2] );
    printf("%c\n", vector[3] );
    printf("%c\n", vector[4] );

    // NO EXISTE STRING NO SE PUEDE ASIGNAR;
    //string = "HOLA";

    string[0] = 'H';
    string[1] = 'O';
    string[2] = 'L';
    string[3] = 65;
    string[4] = '\0';

    printf ("El string se puede imprimir así: %s %s\n", string, s1 );

    snprintf(s2, sizeof(s2), "Internetworking dice %s", string);

    printf ("El tamaño en memoria de n1 es %ld bytes\n", sizeof(n1) );
    printf ("El tamaño en memoria de letra es %ld bytes\n", sizeof(letra) );
    printf ("El tamaño en memoria de string es %ld bytes\n", sizeof(string) );
    printf ("El tamaño en memoria de s1 es %ld bytes\n", sizeof(s1) );
    printf ("El tamaño en memoria de s2 es %ld bytes\n", sizeof(s2) );
    printf ("El tamaño del string de s1(%s) es de %ld caracteres, y el de s2(%s) es de %ld\n", s1, strlen(s1), s2, strlen(s2) );

    return (0);

}
