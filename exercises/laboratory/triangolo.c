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
