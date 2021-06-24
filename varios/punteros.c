#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

	int n1 = 10;
	int n2 = 20;

	int *p;
	int *q;

	p = malloc ( sizeof (int) );

	*p = 30;

	q = p;

	printf("n1=%d n2=%d valor de p es %d el de q es %d\n", n1, n2, *p, *q );

	*q = 40;

	printf("n1=%d n2=%d valor de p es %d el de q es %d\n", n1, n2, *p, *q );

	q = &n2;

	// si yo no hago el free antes de perder el puntero p esa memoria queda allocada y perdida
	// Memory leak 
	// free (p); 

	p = q;

	printf("n1=%d n2=%d valor de p es %d el de q es %d\n", n1, n2, *p, *q );

	return (0);

}
