#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define P_SIZE sizeof(struct psuma)

struct psuma {
	uint16_t v1;
	uint16_t v2;
	uint32_t res;
};

// Función que se encarga de leer un mensaje de aplicacion completo 
// lee exactamente la cantidad de bytes que se pasan en el argumento total:

int leer_mensaje ( int sd, char * buffer, int total ) {
    int bytes;
    int leido;

    leido = 0;
    bytes = 1;

    while ( (leido < total) && (bytes > 0) ) {

        bytes = recv ( sd , buffer + leido , total - leido , 0);

        leido = leido + bytes;

    }

    return ( leido );

}

int main(int argc, char *argv[]) {
	int n;
	int sd;
	int lon;
	char teclado[512];
	char buffer[P_SIZE];
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;
	struct hostent *h;
	struct psuma *suma;

	if (argc < 2) {
		printf("Debe ejecutar %s (nombre de host)\n",argv[0]); 
		exit (-1);
	}

	sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(4444);
	//servidor.sin_addr.s_addr = inet_addr("x.x.x.x");

	if ( h = gethostbyname ( argv [1] ) ) {
		memcpy ( &servidor.sin_addr , h->h_addr , h->h_length );
        } else {
                herror("DNS error");
                exit (-1);
	}

	lon = sizeof(servidor);

	if ( connect ( sd , (struct sockaddr *) &servidor, lon ) < 0 ) {
		perror ("Error en connect");
		exit(-1);
	}

	suma = (struct psuma *) buffer;

	while (ntohl(suma->res) != 100) {

		printf("Ingrese valor 1: ");
		fgets(teclado, sizeof(teclado), stdin);
		teclado[strlen(teclado) - 1] = '\0';

		suma->v1 = htons(atoi(teclado));

		printf("Ingrese valor 2 (sumar 100 para salir): ");
		fgets(teclado, sizeof(teclado), stdin);
		teclado[strlen(teclado) - 1] = '\0';

		suma->v2 = htons(atoi(teclado));

		suma->res = htonl(0);

		send ( sd, buffer, P_SIZE, 0 );

		n = leer_mensaje (sd, buffer, P_SIZE );

		printf("La suma de %d y %d es %d\n", ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res));

	}

	close(sd);

}
