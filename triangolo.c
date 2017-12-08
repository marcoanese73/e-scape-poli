/* 1.3 TRIANGOLO */

/* Il programma riceve in ingresso un numero intero n. Stampare un triangolo rettangolo isoscele fatto di asterischi (cioe di caratteri *), la cui lunghezza di un lato sia pari a n. */

#include <stdio.h>
#define PUNTO '*'

int main(int argc, char *argv[])
{
	int n;
	int lato, punti;

	do
		scanf("%d", &n);
	while(n <= 0);

	for(lato = 1; lato <= n; lato++) {
		for(punti = 1; punti <= lato; punti++)
			printf("%c ", PUNTO);
		printf("\n");
	}

	return 0;
}
