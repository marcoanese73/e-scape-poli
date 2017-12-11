/* Scrivere un programma che chiede all’utente di inserire una sequenza di numeri interi terminata dallo 0 (lo 0 non fa parte della sequenza). Il programma ignora i valori negativi e valuta e stampa a video le coppie di numeri consecutivi che soddisfano tutte le condizioni che seguono: sono diversi tra di loro, sono entrambi numeri pari, il loro prodotto è un quadrato perfetto. */

#include <stdio.h>
#define STOP 0

int main(int argc, char * argv[])
{
	int num;
	int prec;
	int min, max, trovato;

	do
		scanf("%d", &prec);
	while(prec < 0);
	
	do
		scanf("%d", &num);
	while(num < 0);

	while(num != STOP) {
		if(num != prec && num % 2 == 0 && prec % 2 == 0) {
			if(num < prec) {
				min = num;
				max = prec; }
			else {
				min = prec;
				max = num; }
			trovato = 0;
			while(!trovato && min < max) {
				if (num * prec == min * min) {
					trovato = 1;
					printf("%d %d\n", prec, num); }
				else
					min++;
			}
		}
	prec = num;
	do
		scanf("%d", &num);
	while(num < 0);
	}
	
	return 0;
}
