#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define P_SIZE sizeof(struct psuma)

struct psuma {
	uint16_t v1;
	uint16_t v2;
	uint32_t res;
};


void *suma (void *);
void *ver_cone (void *);
int leer_mensaje ( int  , char * , int  );

int cone;
pthread_mutex_t m;
pthread_cond_t c;

int main() {

	int lon;
	int sd;
	int sd_cli;
	struct sockaddr_in servidor;
	struct sockaddr_in cliente;
	pthread_t tid;
	pthread_t tid_ver;
	
	servidor.sin_family = AF_INET;
	servidor.sin_port = htons (4444);
	servidor.sin_addr.s_addr = INADDR_ANY;

	sd = socket (PF_INET, SOCK_STREAM, 0);

	if ( bind ( sd , (struct sockaddr *) &servidor , sizeof(servidor) ) < 0 ) {

		perror("Error en bind");
		exit (-1);

	}

	listen ( sd , 5);

	cone = 0;
	pthread_mutex_init ( &m , NULL);
	pthread_cond_init ( &c , NULL);

	pthread_create ( &tid_ver, NULL, ver_cone, NULL );

	while (1) {

		lon = sizeof(cliente);

		sd_cli = accept ( sd , (struct sockaddr *) &cliente , &lon);

		pthread_mutex_lock (&m);

		cone++;

		pthread_cond_signal (&c);
		
		pthread_mutex_unlock (&m);
	
		pthread_create ( &tid, NULL, suma, &sd_cli );

	}

	close (sd);

}

void *suma ( void *arg ) {

	int sdc;
	int n;
	char buffer[P_SIZE];
	struct psuma *suma;

	suma = (struct psuma *) buffer;

	sdc = *( (int *) arg);

	n = 1;
	while ( n != 0) {

		if ( ( n = leer_mensaje ( sdc , buffer , P_SIZE ) ) > 0 ) {

			suma->res = htonl ( ntohs (suma->v1) + ntohs(suma->v2) );
			printf ("Enviando: %d %d %d \n",ntohs(suma->v1),ntohs(suma->v2),ntohl(suma->res));
			send ( sdc , buffer , P_SIZE ,0 );

		}

	}
	close (sdc);

	pthread_mutex_lock (&m);

	cone--;

	pthread_cond_signal (&c);
	
	pthread_mutex_unlock (&m);

}

void *ver_cone (void * arg) {

	while (1) {

		pthread_mutex_lock (&m);
	
		pthread_cond_wait(&c,&m);
	
		printf("Conexiones %d\n",cone);

		pthread_mutex_unlock (&m);
	}

}

int leer_mensaje ( int socket , char *buffer , int total ) {

	int bytes, leido;

	leido = 0;
	bytes = 1;
	while ( (leido < total) && (bytes > 0) ) {
		bytes = recv ( socket , buffer + leido , total - leido , 0 );
		leido = leido + bytes;
	}
	return (leido);
}

