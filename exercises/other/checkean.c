#include <stdio.h>
#include <string.h>

#define N 13
#define MOLT_DISP 1
#define MOLT_PARI 3

int checkean13(char[]);

int main(int argc, char *argv[])
{
	char seq[N+1];
	int check, l;

	gets(seq);
	l = strlen(seq);
	check = checkean13(seq);
	if(check != (seq[l-1] - '0'))
		printf("Codice scorretto %d\n", check);
	else
		printf("Codice corretto %s\n", seq);

	return 0;
}

int checkean13(char ean[])
{
	int somma, i, unit;

	for(i = 1, somma = 0; ean[i+1] != '\0'; i += 2)
		somma += (ean[i] - '0') * MOLT_PARI;

	for(i = 0; ean[i] != '\0' && i < N-1; i += 2)
		somma += (ean[i] - '0') * MOLT_DISP;

	unit = somma % 10;
	
	return (10 - unit);
}
