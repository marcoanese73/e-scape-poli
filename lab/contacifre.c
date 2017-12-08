/* 1.1 NUMERO DI CIFRE */

/* Scrivere un programma che chiede all'utente di inserire un numero strettamente positivo (e finche' non e' tale lo richiede) e visualizza il numero di cifre che lo costituiscono.
Ad esempio, se l'utente inserisce 7362, il programma visualizza 4. */

#include <stdio.h>
#define BASE 10

int main(int argc, char *argv[])
{
	int num, cifre;

	do
		scanf("%d", &num);
	while(num <= 0);

	cifre = 0;
	while(num > 0) {
		num = num / BASE;
		cifre++;
	}

	printf("%d\n", cifre);

	return 0;
}
