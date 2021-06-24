#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int i;
	char str1[10];
	char str2[10];
	char str3[] = "ASIGNADO EN LA DECLARACION";
	
	// str1 = "HOLA"; 

	str1[0] = 'H';
	str1[1] = 'O';
	str1[2] = 76; // ASCI de L
	str1[3] = 'A';
	str1[4] = '\0'; // str[4] = 0;

	for ( i = 0 ; str1[i] != '\0'; i ++ ) { 

		printf ("%c",str1[i]);

	}
	printf ("\n");

	sprintf ( str2, "CHAU");

	printf ("El string str2 es: %s\n", str2 );

	strcpy(str3,str1);

	printf ("El string str3 es: %s la longitud es %d\n", str3, strlen(str3) );

	printf ("El tamaño de str3 es: %d \n", sizeof(str3));

	snprintf ( str3, sizeof(str3), "%s como te va? %s",str1, str2);

	printf ("El string str3 es: %s la longitud es %d\n", str3, strlen(str3) );

        snprintf ( str3, sizeof(str3), "%s como te va? %s Hasta la próxima",str1, str2);

        printf ("El string str3 es: %s la longitud es %d\n", str3, strlen(str3) );

	return (0);
}
