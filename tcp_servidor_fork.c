#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#define P_SIZE sizeof(struct psuma)

struct psuma {
	uint16_t v1;
	uint16_t v2;
	uint32_t res;
};

void terminar_hijo () {
	int pid, res;

	pid = waitpid ( -1 , &res, WNOHANG );
	printf ("Termino el proceso %d con resultado %d\n",pid,res);

}

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
	int pid;
	char buffer[P_SIZE];
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;
	struct psuma *suma;

	signal ( SIGCHLD , terminar_hijo );

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(4444);
	servidor.sin_addr.s_addr = INADDR_ANY;

	sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (bind(sd, (struct sockaddr *) &servidor, sizeof(servidor)) < 0) {
		perror("Error en bind");
		exit(-1);
	}

	listen ( sd , 5 );

	while (1) {

		lon = sizeof(cliente);
		sdc = accept ( sd, (struct sockaddr *) &cliente, &lon );

		pid =  fork();

		if (pid == 0) {

			close (sd);		
	
			while ( ( n = leer_mensaje ( sdc , buffer , P_SIZE ) ) > 0 ) {
				suma = (struct psuma *) buffer;
				printf("Recibí desde: %s puerto: %d los valores: v1 %d v2 %d res %d \n", inet_ntoa(cliente.sin_addr), ntohs( cliente.sin_port), ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res));
				suma->res = htonl(ntohs(suma->v1) + ntohs(suma->v2));
				printf("Enviando: v1 %d v2 %d res %d \n", ntohs(suma->v1), ntohs(suma->v2), ntohl(suma->res));
				send ( sdc , buffer, P_SIZE, 0 );
			}
	
			close (sdc);
			exit (0);

		} else {

			printf("Se creo el proceso %d\n",pid);
			close (sdc);

		}

	}

	close(sd);

}
