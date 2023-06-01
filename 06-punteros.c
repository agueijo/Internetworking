#include <stdio.h>
#include <stdlib.h>

int main () {

	int n1 = 10;
	int n2 = 20;
	int *p;
	int *q;

	p = malloc ( sizeof(int) );

	*p = 30;
	q = p;
	*q = 40;

	q = &n1;

	*q = 50;

	printf("El valor de n1 es %d n2 es %d el contenido de p es %d la posición de memoria de p es %p\n", n1, n2, *p , q );
	printf("El valor de n1 es %d n2 es %d el contenido de p es %d la posición de memoria de p es %p\n", n1, n2, *p , &n1 );

	free (p);
	return 0;
}
