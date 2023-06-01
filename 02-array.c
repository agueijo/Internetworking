#include <stdio.h>
#include <stdlib.h>

int main () {

	int vec[10];
	char letra = 'A';

	vec[0] = 64;

	vec[1] = 65;

	vec[9] = 66;

	// vec[10] = 88; // la posición 10 no es valida arrat[N] va de 0..(N-1)

	printf("Letra: %c %c \n", letra , vec[1] );

}
