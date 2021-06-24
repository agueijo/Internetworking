#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

struct psuma {
	uint16_t val1;
	uint16_t val2;
        uint32_t res;	
};

#define P_SIZE sizeof(struct psuma)

int main() {

	int sd;
	int lon;
	char buffer[P_SIZE];
	struct psuma *suma;	
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;

	sd = socket ( PF_INET, SOCK_DGRAM, IPPROTO_UDP );

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(4444);
	servidor.sin_addr.s_addr = INADDR_ANY;

	lon = sizeof (servidor);

	bind ( sd , (struct sockaddr *) &servidor , lon );

	while (1) {

		lon = sizeof (cliente);

		recvfrom ( sd, buffer, P_SIZE , 0, (struct sockaddr *) &cliente, &lon);

		suma = (struct psuma *) buffer;

		printf ("Recibí %d + %d\n", ntohs (suma->val1) , ntohs (suma->val2) );

		suma->res = htonl( ntohs(suma->val1) + ntohs(suma->val2) );	

		sendto ( sd, buffer, P_SIZE, 0, (struct sockaddr *) &cliente , lon );

	}

	close (sd);

}
