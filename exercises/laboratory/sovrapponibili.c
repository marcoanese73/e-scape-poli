#include <stdio.h>
#define N 5
#define M 3

int main(int argc, char * argv[])
{
	int m1[N][M], m2[N][M];
	int i, j;
	int sov;

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			do
				scanf("%d", &m1[i][j]);
			while(m1[i][j] != 0 && m1[i][j] != 1);
		}
	}
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			do
				scanf("%d", &m2[i][j]);
			while(m2[i][j] != 0 && m2[i][j] != 1);
		}
	}

	sov = 1;

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			if(m1[i][j] == 1 && m2[i][j] == 1)
				sov = 0;
		}
	}

	printf("%d\n", sov);

	return 0;
}
