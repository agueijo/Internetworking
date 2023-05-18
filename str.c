#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

	char str1[5] = "HOLA";
	char str2[5];
	char str3[12];

	// str2 = "CHAU"; NO SE PUEDE 

	str2[0] = 'C';
	str2[1] = 'H';
	str2[2] = 65;
	str2[3] = 'U';
	str2[4] = 0; // str2[4] = '\0';

	snprintf(str3 , sizeof(str3), "-%s-%s-", str1, str2 );

	printf("String: %s %s %s\n", str1, str2, str3 );

}
