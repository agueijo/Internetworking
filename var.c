#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1+20
#define FALSE 0

int main () {

	int n1;
	int n2 = 20;
	int res;

	const int y = 10;

	n1 = 10;
	n1+=5;
	printf ("La suma de %d + %d es igual a %d\n", ++n1 , n2 , res = ( ++n1 + n2) );

	// CHAR
	char c;

	c = 'X';
	printf ("La letra %d\n", c );

	// ARRAY
	int vec[10];

	vec[0] = 5;
	vec[1] = 20;
	vec[9] = 100;

	printf ("El array posición 1 %d\n", vec[1] );
	
	// STRING
	char str[10];
	char s1[10] = "CHAU";
	char s2[22];

	// str = "HOLA"; ( error )
        str[0] = 'H';
        str[1] = 'O';
        str[2] = 'L';
        str[3] = 'A';
        str[4] = '\0'; // = 0

	printf ("El string %s y %s \n", str , s1);
	snprintf (s2 , sizeof(s2) , "%s y %s", str , s1);
	printf ("El string %s \n", s2 );

	// if ( TRUE ) {
	// if ( n1 = 5 ) { // ( asigna y devuelve lo que asigna que es distinto de cero )
	if ( n1 == 5 ) {

		printf ("Todo valor distinto de cero es verdadero %d\n", (y == 10) );

	} else {

		printf ("El valor cero es falso %d\n", (y != 10) );
	
	}


	return (0);

}
