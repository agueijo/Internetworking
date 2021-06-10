#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int main ()
{
	char str[] = "HOLA";
	int n;

	for ( n=0 ; n<strlen(str); n++ ) {
	
		printf ("%c", str[n]);

	}

	printf ("\n");

	return (0);

}
