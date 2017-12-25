#include <stdio.h>

#define N 5

int main(int argc, char * argv[])
{
	int m[N][N];
	int i, j, sim;
	
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &m[i][j]);

	sim = 1;

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(m[i][j] != m[j][i])
				sim = 0;
			if(j > i) {
				if(m[i][j] != m[i][i])
					sim = 0;
			}
		}
	}

	printf("%d\n", sim);

	return 0;
}
