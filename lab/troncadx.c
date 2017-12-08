/* 1.5 TRONCABILE PRIMO A DESTRA */

/* Scrivere un programma che acquisisce un valore intero strettamente positivo, e finché non è tale lo richiede. 
Il programma analizza il valore intero e visualizza 1 nel caso sia un troncabile primo a destra, 0 altrimenti. 
Un numero si dice troncabile primo a destra se il numero stesso e tutti i numeri che si ottengono eliminando una alla volta 
la cifra meno significativa del numero analizzato al passo precedente, sono numeri primi. Per esempio, se il numero iniziale 
è 719, i numeri che si ottengono "eliminando una alla volta la cifra meno significativa del numero analizzato al passo 
precedente ..." sono 71 e 7. */

#include <stdio.h>
#define BASE 10

int primality(int);

int main(int argc, char *argv[])
{
	int val;
	int trun_dx;

	do
		scanf("%d", &val);
	while(val <= 0);

	trun_dx = 1;
	while(trun_dx && val > 0) {
		if(!primality(val))
			trun_dx = 0;
		val = val / BASE;
	}

	printf("%d\n", trun_dx);

	return 0;
}

int primality(int num)
{
	int i, isp;

	if((num % 2 == 0 && num != 2) || (num == 1))
		isp = 0;
	else {
		isp = 1;
		i = 3;
		while(isp == 1 && i < num/2) {
			if(num % i == 0)
				isp = 0; 
			else
				i = i + 2; 
		}
	}

	return isp;
}
