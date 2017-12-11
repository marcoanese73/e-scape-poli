/* 2.2 FREQUENZE */

/* Scrivere un programma che acquisisce i dati di una matrice quadrata di numeri interi di dimensione 10, senz'altro compresi nell'intervallo [0,10].
Il programma calcola e visualizza la frequenza nella matrice di ogni numero dell'intervallo [0,10].
Il programma stampa inoltre il numero che compare più frequentemente nella matrice.
Se esistono più numeri a frequenza massima, si stamperà quello con valore più basso. */

#include <stdio.h>
#define N 10

int main(int argc, char * argv[])
{
	int m[N][N], freq[N+1];
	int i, j;
	int max, imax;

	for(i = 0; i < N+1; i++)
		freq[i] = 0;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++) {
			scanf("%d", &m[i][j]);
			freq[m[i][j]]++; }

	for(i = 0, max = freq[i], imax = i; i < N+1; i++) {
		printf("%d frequenza %d\n", i, freq[i]);
		if(freq[i] > max) {
			max = freq[i];
			imax = i;
		}
	}

	printf("%d\n", imax);

	return 0;
}
