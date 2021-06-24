#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap ( int *p1, int *p2 ) {
	int aux;

	aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}

int main () {

	int n1 = 10;
	int n2 = 20;

	printf("n1=%d n2=%d\n", n1, n2 );

	swap ( &n1 , &n2);

	printf("n1=%d n2=%d\n", n1, n2 );

	return (0);
}
