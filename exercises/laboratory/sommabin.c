#include <stdio.h>

#define N 8

int somma(int[], int[], int[], int);

int main(int argc, char * argv[])
{
	int vett_1[N], vett_2[N], vett_3[N];
	int i, rip;

	for(i = 0; i < N; i++)
		scanf("%d", &vett_1[i]);

	for(i = 0; i < N; i++)
		scanf("%d", &vett_2[i]);

	rip = somma(vett_1, vett_2, vett_3, N);

	printf("\n");
	for(i = 0; i < N; i++)
		printf("%d ", vett_3[i]);
	printf("\n");
	printf("%d\n", rip);
	
	return 0;
}

int somma(int op_1[], int op_2[], int ris[], int dim)
{
	int i, rip;

	for(i = dim-1, rip = 0; i >= 0; i--) {
		ris[i] = op_1[i] + op_2[i] + rip;
		if(ris[i] > 1) {
			if(ris[i] == 2)
				ris[i] = 0;
			else
				ris[i] = 1;
			rip = 1;
		} else
			rip = 0;
	}

	return rip;
}
