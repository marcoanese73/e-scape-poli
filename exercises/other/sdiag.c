#include <stdio.h>

#define N 10

int main(int argc, char * argv[])
{
	int mat[N][N];
	int i, j;
	int diag, sup, inf;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &mat[i][j]);

	for(diag = 0, i = 0; i < N; i++)
		diag = diag + mat[i][i];

	for(sup = 0, inf = 0, i = 0; i < N-1; i++)
		for(j = i+1; j < N; j++) {
			sup = sup + mat[i][j];
			inf = inf + mat[j][i];
		}

	printf("%d\n%d\n%d\n", diag, sup, inf);

	return 0;
}