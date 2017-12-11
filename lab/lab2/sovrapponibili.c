/* 2.3 MATRICI SOVRAPPONIBILI */

/* Scrivere un programma che chiede all’utente di inserire gli elementi di due matrici A e B dimensione 5×3 con soli valori 0 e 1.
Durante l'acquisizione, se un valore non rispetta il vincolo di essere 0 o 1, viene richiesto.
Il programma verifica se sia possibile sovrapporre la matrice B alla matrice A in modo tale che nessun elemento di valore 1 di B si vada a sovrapporre ad un elemento di valore 1 in A.
In caso affermativo, il programma visualizza 1, 0 altrimenti.
Per esempio, date le seguenti matrici A e B:
A: 1 0 0  B: 0 1 0
   0 1 1     1 0 0
   0 0 0     0 1 0
   1 1 0     0 0 1
   1 1 1     0 0 0
il programma visualizza 1. */

#include <stdio.h>
#define N 5
#define M 3

int main(int argc, char * argv[])
{
	int m1[N][M], m2[N][M];
	int i, j;
	int sov;

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			do
				scanf("%d", &m1[i][j]);
			while(m1[i][j] != 0 && m1[i][j] != 1);
		}
	}
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			do
				scanf("%d", &m2[i][j]);
			while(m2[i][j] != 0 && m2[i][j] != 1);
		}
	}

	sov = 1;

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			if(m1[i][j] == 1 && m2[i][j] == 1)
				sov = 0;
		}
	}

	printf("%d\n", sov);

	return 0;
}
