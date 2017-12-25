#include <stdio.h>

#define N 10

int vette(int[], int, int);

int main(int argc, char *argv[])
{
	int a[N], i, num_vette;

	for(i = 0; i < N; i++)
		scanf("%d", &a[i]);

	num_vette = vette(a, N-2, a[N-1]);

	printf("%d\n", num_vette);

	return 0;
}

int vette(int a[], int dim, int max)
{
	if(dim < 0)
		return 0;

	if(a[dim] > max)
		return 1 + vette(a, dim-1, a[dim]);

	return vette(a, dim-1, max);
}