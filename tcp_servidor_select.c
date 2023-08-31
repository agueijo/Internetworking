#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
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


int main() {
	int n;
	int sd;
	int sdc;
	int lon;
	char buffer[P_SIZE];
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;
	struct psuma *suma;
	fd_set copia;
	fd_set conjunto;

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(4444);
	servidor.sin_addr.s_addr = INADDR_ANY;

	sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (bind(sd, (struct sockaddr *) &servidor, sizeof(servidor)) < 0) {
		perror("Error en bind");
		exit(-1);
	}

	listen ( sd , 5 );

	FD_ZERO( &conjunto);
	FD_SET ( sd , &conjunto );

	while (1) {

		copia = conjunto;
		select ( FD_SETSIZE , &copia , NULL, NULL, NULL );

		if ( FD_ISSET ( sd , &copia ) ) {
			lon = sizeof(cliente);
			sdc = accept ( sd, (struct sockaddr *) &cliente, &lon );
			FD_SET ( sdc , &conjunto );
		}

		for ( sdc = 1;  sdc < FD_SETSIZE ; sdc++) {

			if ( FD_ISSET ( sdc , &copia) && (sdc != sd) ) {

				if ( leer_mensaje ( sdc , buffer , P_SIZE ) > 0 ) {

					suma = (struct psuma *) buffer;
					printf("Recibí desde: %s puerto: %d los valores: v1 %d v2 %d res %d \n", inet_ntoa(cliente.sin_addr), ntohs( cliente.sin_port), ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res));
					suma->res = htonl(ntohs(suma->v1) + ntohs(suma->v2));
					printf("Enviando: v1 %d v2 %d res %d \n", ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res));
					send ( sdc , buffer, P_SIZE, 0 );

				} else {

					close (sdc);
					FD_CLR ( sdc , &conjunto );			

				}

			}

		}

	}

	close(sd);

}
