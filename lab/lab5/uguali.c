/* 5.3 NUMERI UGUALI */

/* Scrivere un sottoprogramma RICORSIVO tuttiuguali che ricevuti in ingresso un array di interi, la dimensione dell'array, un intero n e qualsiasi altro parametro ritenuto strettamente necessario, analizza il contenuto dell'array per verificare se tutti gli elementi sono uguali a n: il sottoprogramma restituisce 1 se la proprietà e verificata, 0 altrimenti. */

#include <stdio.h>
#define N 10

int tuttiuguali(int[], int, int);

int main(int argc, char * argv[])
{
	int vett[N];
	int i;

	for(i = 0; i < N; i++)
		scanf("%d", &vett[i]);

	printf("%d\n", tuttiuguali(vett, N, vett[0]));
	
	return 0;
}

int tuttiuguali(int vett[], int dim, int n)
{
	if(vett[0] == n && dim == 1)
		return 1;

	if(vett[0] == n)
		return tuttiuguali(&vett[1], dim-1, n);

	return 0;
}
