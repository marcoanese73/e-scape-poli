#include <stdio.h>

#define N 10

int main(int argc, char * argv[])
{
	int m[N][N], freq[N+1];
	int i, j;
	int max, imax;

	for(i = 0; i < N+1; i++)
		freq[i] = 0;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++) {
			scanf("%d", &m[i][j]);
			freq[m[i][j]]++; }

	for(i = 0, max = freq[i], imax = i; i < N+1; i++) {
		printf("%d frequenza %d\n", i, freq[i]);
		if(freq[i] > max) {
			max = freq[i];
			imax = i;
		}
	}

	printf("%d\n", imax);

	return 0;
}