#include <stdio.h>

#define N 10

int main(int argc, char * argv[])
{
	int m[N][N];
	int k, tot;
	int i, j;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &m[i][j]);

	do
		scanf("%d", &k);
	while(k < 1 || k >= N);

	tot = 0;

	for(i = 0; i < k-1; i++)
		for(j = 0; j < k; j++)
			tot = tot + m[i][j];

	printf("%d\n", tot);

	return 0;
}