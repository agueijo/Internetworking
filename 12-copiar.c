#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[]) {

    int f1;
    int f2;
    int n;
    char buffer[512];

    if (argc <= 2 ) {
    
            printf ("Debe ejecutar %s (archivo_origen) (archivo_destino)\n", argv[0]);
        exit(-1);

    }

    f1 = open ( argv[1] , O_RDONLY );
    if ( f1 < 0 ) {
        perror("Error abriendo origen");
        exit (-1);
    }

    f2 = open ( argv[2] , O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR );

    while ( ( n = read ( f1 , buffer , sizeof(buffer) ) ) > 0 ) {

        write ( f2 , buffer , n );

    }

    close (f1);
    close (f2);

    printf ("Archivo copiado exitosamente!\n");

    return (0);

}
