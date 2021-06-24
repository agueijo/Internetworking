#include <stdio.h>
#include <stdlib.h>

int main () {

	int n1 = 20;
	int n2;
	int *p;
	int *q;

	n1 = 10;
	n2 = 20;

	p = malloc ( sizeof (int) );

	*p = 30;

	q = &n2;

	n2 = 40;

	p = q;

	printf ("n1=%d n2=%d *p=%d *q=%d\n", n1, n2, *p, *q);

	return 0;

}
