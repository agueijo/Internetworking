#include <stdio.h>
#include <stdlib.h>

int main() {

	struct t_alumno {
		int legajo;
		char nombre[20];
	};

	struct t_alumno alumno1;
	struct t_alumno *p;

	alumno1.legajo = 100;
	sprintf(alumno1.nombre, "Agustín");

	printf ("Alumno legajo %d nombre: %s\n", alumno1.legajo, alumno1.nombre );

	p = &alumno1;

	(*p).legajo = 200;

	printf ("Alumno legajo %d nombre: %s\n", alumno1.legajo, alumno1.nombre );

        p->legajo = 300; // = (*p).legajo

        printf ("Alumno legajo %d nombre: %s\n", p->legajo, p->nombre );

	return (0);
}
