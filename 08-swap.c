#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap ( int *n1, int *n2 ) {
	int aux;

	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

int main ()
{
	int n1;
	int n2;

	n1 = 10;
	n2 = 20;

	printf("Valor n1=%d n2=%d!\n", n1 , n2 );

	swap ( &n1 , &n2 );

	printf("Valor n1=%d n2=%d!\n", n1 , n2 );

	return (0);

}
