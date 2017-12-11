/* 3.8 CARTE DI CREDITO */

/* La maggior parte dei numeri di carta di credito possono essere validati mediante un algoritmo sviluppato da Hans Peter Luhn di IBM, descritto nel brevetto U. S. numero 2950048 del 1954, ora di dominio pubblico.
L'algoritmo procede dalla destra alla sinistra del numero e la cifra più a destra è un valore di controllo.
Partendo da destra, alternativamente le cifre vengono prese così come sono, oppure vengono moltiplicate per 2.
Si calcola quindi la somma di tutti tali valori, singoli oppure raddoppiate, sommando tutte le cifre.
Se il valore risultante è un multiplo di 10 il numero della carta di credito è valido. */

#include <stdio.h>
#define L 16
#define BASE 10

int main(int argc, char * argv[])
{
	char cred[L+1];
	int tot, prod, i, digit, left, valida;

	gets(cred);
	
	for(tot = 0, i = L-1; i >= 0; i--) {
		if(i % 2 != 0)
			tot += cred[i] - '0';
		else {
			prod = 2 * (int)(cred[i] - '0');
			if(prod >= 10) {
				digit = prod % BASE;
				tot += digit;
				left = prod / BASE;
				tot += left;
			}
			else
				tot += prod;
		}
	}

	if(tot % BASE == 0)
		valida = 1;
	else
		valida = 0;

	printf("%d\n", valida);

	return 0;



}
