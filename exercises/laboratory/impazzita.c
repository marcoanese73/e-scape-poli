#include <stdio.h>

#define N 5

int main(int argc, char * argv[])
{
	int m[N][N];
	int i, j, num;
	int r, c;
	int k;

	for(i = 0, num = 1; i < N; i++)
		for(j = 0; j < N; j++) {
			m[i][j] = num;
			num++;
		}
	
	scanf("%d%d", &r, &c);

	k = m[r][c];

	for(i = 0; i < N; i++) {
		if(i != r)
			m[i][c] = k * 2;
	}

	for(i = 0; i <= r; i++) {
		for(j = 0; j < N; j++) {
			if(j != c && i != r)
				m[i][j] = m[i][j] + k;
			else if(j < c)
				m[i][j] = m[i][j] + k;
			else if (j != c) 
				m[i][j] = m[i][j] - k;
		}
	}

	for(i = r + 1; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(j != c)
				m[i][j] = m[i][j] - k;
		}
	}

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%d ", m[i][j]);
		}
	printf("\n");
	}

	return 0;
}
