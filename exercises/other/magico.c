#include <stdio.h>
#define N 3

int main(int argc, char * argv[])
{
	int m[N][N], somma;
	int i, j, tot, ism;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &m[i][j]);

	somma = 0;

	for(i = 0; i < N; i++)
		somma = somma + m[i][i];

	tot = 0;

	for(i = 0; i < N; i++)
		tot = tot + m[i][N-1-i];

	if(tot == somma)
		ism = 1;
	else
		ism = 0;
	for(i = 0; ism && i < N; i++) {
		for(tot = 0, j = 0; j < N; j++)
			tot = tot + m[i][j];
		if(tot != somma)
			ism = 0;
	}

	for(i = 0; ism && i < N; i++) {
		for(tot = 0, j = 0; j < N; j++)
			tot = tot + m[j][i];
		if(tot != somma)
			ism = 0;
	}

	printf("%d", ism);
	
	if(ism)
		printf(" %d\n", somma);
	else
		printf("\n");

	return 0;
}
