#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

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
