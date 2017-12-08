/* 1.2 PADDING */

/* Si vuole rappresentare a video un valore naturale num utilizzando un numero a scelta di cifre k inserendo 0 nelle posizioni più significative, fino a raggiungere la dimensione desiderata.
Nel caso in cui l'utente inserisca un numero di cifre k minore di quelle che costituiscono il numero num il programma visualizza il valore num così come e'. 
Per esempio, volendo rappresentare 842 su 5 cifre, si ottiene 00842. */

#include <stdio.h>
#define BASE 10
#define ZERO 0

int contacifre(int);

int main(int argc, char *argv[])
{
	int num, k;
	int i, cifre;

	do
		scanf("%d", &num);
	while(num <= 0);

	do
		scanf("%d", &k);
	while(k <= 0);

	cifre = contacifre(num);

	i = 0;
	while(i < k-cifre) {
		printf("%d", ZERO);
		i++;
	}

	printf("%d\n", num);

	return 0;
}

int contacifre(int num)
{
	int cifre;

	cifre = 0;
	while(num > 0) {
		num = num / BASE;
		cifre++;
	}

	return cifre;
}
