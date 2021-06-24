#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define P_SIZE sizeof(struct psuma) 

struct psuma {
	uint16_t val1;
	uint16_t val2;
	uint32_t res; 
};

int main() {

	int sd;
	char buffer[P_SIZE];
	struct psuma *suma;
	socklen_t lon;
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;

	sd = socket ( PF_INET , SOCK_DGRAM , IPPROTO_UDP );

	servidor.sin_family = AF_INET;
	servidor.sin_port = htons(4444);
	servidor.sin_addr.s_addr = INADDR_ANY;

	lon = sizeof (struct sockaddr_in);

	if ( bind ( sd , (struct sockaddr *) &servidor , lon ) < 0 )
	{
		perror ("Error en bind");
		exit(-1);
	}

	while (1) { 

		recvfrom (sd, buffer, P_SIZE, 0, (struct sockaddr *) &cliente, &lon);
		
		suma = (struct psuma *) buffer;

	        printf ("Recibí val1=%d val2=%d res=%d\n"
					    , ntohs (suma->val1)
                                            , ntohs (suma->val2)
                                            , ntohl (suma->res) );


		suma->res = htonl ( ntohs(suma->val1) + ntohs(suma->val2) ) ;

		sendto (sd, buffer, P_SIZE, 0, (struct sockaddr *) &cliente, lon); 

	}

	close (sd);

	return(0);

}
