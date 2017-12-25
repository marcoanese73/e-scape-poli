#include <stdio.h>

#define N 30

void leggi(int [][N], int);
int isid(int [][N], int);
void converti(int [][N], int [], int);

int main(int argc, char * argv[])
{
	int mat[N][N], id;
	int vet[N], i;

	leggi(mat, N);
	id = isid(mat, N);
	converti(mat, vet, N);

	printf("%d\n", id);
	for(i = 0; i < N; i++)
		printf("%d ", vet[i]);
	printf("\n");

	return 0;
}

void leggi(int m[][N], int dim)
{
	int i, j;
	for(i = 0; i < dim; i++)
		for(j = 0; j < dim; j++)
			do
				scanf("%d", &m[i][j]);
			while(m[i][j] != 0 && m[i][j] != 1);
}

int isid(int m[][N], int dim)
{
	int i, j;
	int stop;

	stop = 1;

	for(i = 0; stop && i < dim; i++)
		for(j = 0; stop && j < dim; j++)
			if(i != j && m[i][j] != 0 || i == j && m[i][j] != 1)
				stop = 0;

	return stop;
}

void converti(int m[][N], int a[], int dim)
{
	int i, j, k;
	int incr;

	for(i = 0; i < dim; i++)
		for(j = dim-1, incr = 1, a[i] = 0; j >= 0; j--) {
			a[i] = a[i] + incr * m[i][j];
			incr = incr * 2;
		}

	return;
}
