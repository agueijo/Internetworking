#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char str[] = "HOLA";
	int n;

	for ( n=0; n < strlen(str); n++ ) {
	
		printf ("%c", str[n]);

	}

	printf ("\n");

	return (0);

}
