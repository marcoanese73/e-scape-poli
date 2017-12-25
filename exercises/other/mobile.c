#include <stdio.h>

#define N 100

int main(int argc, char * argv[])
{
	int val[N];
	float avg[N];
	int n, tot;
	int i, j;

	for(i = 0; i < N; i++)
		scanf("%d", &val[i]);
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(tot = 0, j = 0; j <= i; j++)
			tot = tot + val[j];
		avg[i] = (float)tot / j;
	}

	for(; i < N; i++) {
		for(tot = 0, j = 0; j < n; j++)
			tot = tot + val[i-j];
		avg[i] = (float)tot / j;
	}

	for(i = 0; i < N; i++)
		printf("%f ", avg[i]);
	printf("\n");

	return 0;
}