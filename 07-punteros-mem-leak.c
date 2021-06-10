#include <stdio.h>
#include <stdlib.h>

int main() {

	int n1;
	int n2;
	int *p;
	int *q;

	n1 = 10;
	n2 = 20;

	p = malloc ( sizeof(int) );
	q = malloc ( sizeof(int) );

	*p = 30;

	p = q;

	*q = 40;

	printf ("n1: %d n2: %d *p: %d *q: %d\n", n1, n2, *p , *q );

	// Memory Leak: perdí referencia a la memoria allocada para p con malloc inicialmente

	free (p);

	return (0);
}
