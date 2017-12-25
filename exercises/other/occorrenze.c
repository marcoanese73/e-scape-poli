#include <stdio.h>

#define N 10

typedef struct o {
		char car;
		int n;
	} occ_t;

int main(int argc, char * argv[])
{
	char str[N];
	occ_t v[N];
	int i, j, trovato, nc;

	for(i = 0; i < N; i++)
		scanf("%c", &str[i]);

	nc = 0;

	for(i = 0; i < N; i++) {
		trovato = 0;
		for(j = 0; j < nc && !trovato; j++)
			if(v[j].car == str[i])
				trovato = 1;
			if (trovato)
				v[j-1].n++;
			else {
				v[nc].car = str[i];
				v[nc].n = 1;
				nc++;
			}
	}

	for(i = 0; i < nc; i++)
		printf("%c%d", v[i].car, v[i].n);

	printf("\n");

	return 0;
}