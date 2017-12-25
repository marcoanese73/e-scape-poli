/* ESERCIZIO 4 */
/* VARIANTE: l'utente può decidere di inserire anche meno di 50 elementi negli insiemi. L'input atteso diventa: numero intero n1 seguito da n1 elementi da mettere nel primo insieme, numero intero n2 seguito da n2 elementi da mettere nel secondo insieme. */

#include <stdio.h>
#define N 50

int main(int argc, char * argv[])
{
	int i1[N], i2[N], n1, n2;
	int j, h, k, trovato, un[2*N], inter[N];
	int ni, nu;

	do
		scanf("%d", &n1);
	while(!(n1 >= 0 && n1 <= N));

	for(j = 0; j < n1; j++)
		scanf("%d", &i1[j]);

	do
		scanf("%d", &n2);
	while(n2 < 0 || n2 > N);

	for(j = 0; j < n2; j++)
		scanf("%d", &i2[j]);

	for(j = 0; j < n1; j++)
		un[j] = i1[j];

	for(k = 0; k < n2; k++) {
		for(trovato = 0, h = 0; !trovato && h < n1; h++)
			if(i2[k] == i1[h])
				trovato = 1;
		if(!trovato) {
			un[j] = i2[k];
			j++;
		}
	}

	nu = j;
	ni = 0;

	for(j = 0; j < n1; j++) {
		for(h = 0, trovato = 0; !trovato && h < n2; h++)
			if(i1[j] == i2[h])
				trovato = 1;
		if(trovato) {
			inter[ni] = i1[j];
			ni++;
		}
	}

	for(j = 0; j < nu; j++)
		printf("%d ", un[j]);

	printf("\n");

	for(j = 0; j < ni; j++)
		printf("%d ", inter[j]);

	printf("\n");

	return 0;
}
