#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	int i;
	int pid;

	i = 100;

	pid = fork();

	if ( pid == 0) {


       for ( i = 0 ; (i <= 1000); i++) {
			
			sleep(1);

            printf ("HIJO: El valor de i es %d\n", i);

       }

	} else {	

		for ( i = 0 ; (i <= 1000); i++) {
			
			sleep(1);

			printf ("PADRE: El valor de i es %d\n", i);

		}

	}

	return (0);
}
