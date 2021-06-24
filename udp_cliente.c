#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define P_SIZE sizeof(struct psuma) 

struct psuma {
	uint16_t val1;
	uint16_t val2;
	uint32_t res; 
};

int main(int argc, char * argv[] ) {

	int sd;
	char buffer[P_SIZE];
	char teclado[1024];
	struct psuma *suma;
	socklen_t lon;
	struct hostent *h;
	struct sockaddr_in servidor;

        if (argc < 2) {
                printf("Debe ejecutar %s (nombre de host)\n", argv[0]);
                exit (-1);
        }

	sd = socket ( PF_INET , SOCK_DGRAM , IPPROTO_UDP );

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(4444);
	if ( h = gethostbyname ( argv [1] ) ) {
                memcpy ( &servidor.sin_addr , h->h_addr , h->h_length );
        } else {
                herror("DNS error");
                exit (-1);
        }

	suma = (struct psuma *) buffer;
	
	while ( ntohl(suma->res) != 100) {

		printf ("Ingrese el primer valor: ");
		fgets(teclado, sizeof(teclado) , stdin);
		teclado[strlen(teclado) - 1 ] = '\0';
		suma->val1 = htons ( atoi (teclado) );

	       	printf ("Ingrese el valor a sumar (debe sumar 100 para terminar): ");
	        fgets(teclado, sizeof(teclado) , stdin);
	        teclado[strlen(teclado) - 1 ] = '\0';
	        suma->val2 = htons ( atoi (teclado) );

		suma->res = 0;

		lon = sizeof (struct sockaddr_in);

		sendto (sd, buffer, P_SIZE, 0, (struct sockaddr *) &servidor, lon); 

		recvfrom (sd, buffer, P_SIZE, 0, (struct sockaddr *) &servidor, &lon);
		
		printf ("La suma de %d + %d es %d\n", ntohs (suma->val1) 
					    	    , ntohs (suma->val2)
					            , ntohl (suma->res));
	}	

	close (sd);

	return(0);

}
