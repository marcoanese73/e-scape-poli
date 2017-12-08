/* 1.5 MINIMO COMUNE MULTIPLO E MASSIMO COMUNE DIVISORE */

/* Scrivere un programma che riceve in ingresso due numeri interi a e b e calcola e visualizza sia massimo comune divisore (MCD) e sia minimo comune multiplo (mcm), ognuno seguito dal carattere a capo '\n'. */

#include <stdio.h>

int mcd(int, int);
int mcm(int, int);

int main(int argc, char *argv[])
{
	int a, b;

	do
		scanf("%d", &a);
	while(a < 0);

	do
		scanf("%d", &b);
	while(b < 0);

	printf("%d\n%d\n", mcd(a, b), mcm(a, b));

	return 0;
}

int mcd(int a, int b)
{
	int min, max;
	int div, mcd, trovato;

	if(a < b) {
		min = a;
		max = b;
	} else {
		min = b;
		max = a;
	}

	trovato = 0;
	if(min != 0)
		div = min;
	else {
		div = 1;
		trovato = 1;
	}
	while(!trovato && div >= 1) {
		if(a % div == 0 && b % div == 0)
			trovato = 1;
		else
			div--;
	}

	return div;
}

int mcm(int a, int b)
{
	int min, max;
	int mult, trovato;
	
	if(a < b) {
		min = a;
		max = b;
	} else {
		min = b;
		max = a;
	}

	trovato = 0;
	if(min != 0)
		mult = max;
	else {
		mult = 0;
		trovato = 1;
	}
	while(!trovato && mult <= a*b) {
		if(mult % a == 0 && mult % b == 0)
			trovato = 1;
		else
			mult++;
	}

	return mult; 
}
