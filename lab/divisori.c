/* 1.4 DIVISORI */

/* Scrivere un programma che acquisiti tre interi x, y e n, calcola e visualizza il numero di interi compresi nell'intervallo [x,y] divisibili per n. Nell'acquisizione il programma deve verificare che i tre interi siano tutti strettamente positivi e se così non e' richiede il solo valore che non rispetta questo vincolo. Si ipotizzi invece che senz'altro x < y (ovvero non è una condizione da verificare). Per esempio, se l'utente inserisce i valori 1 10 2 il programma visualizza 5 (corrispondenti a 2, 4, 6, 8 e 10). */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int x, y, n;
	int divisori;

	do
		scanf("%d", &x);
	while(x <= 0);

	do
		scanf("%d", &y);
	while(y <= 0);

	do
		scanf("%d", &n);
	while(n <= 0);

	divisori = 0;
	while(x <= y) {
		if(x % n == 0)
			divisori++;
		x++;
	}

	printf("%d\n", divisori);

	return 0;
}
