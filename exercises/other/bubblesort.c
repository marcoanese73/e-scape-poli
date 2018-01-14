#include <stdio.h>
#define N 10

int main(int argc, char *argv[])
{
	int vett[N];
	int i, j, temp;

	for(i = 0; i < N; i++)
		scanf("%d ", &vett[i]);

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			if(vett[j] > vett[j+1]) {
				temp = vett[j];
				vett[j] = vett[j+1];
				vett[j+1] = temp;
			}

	for(i = 0; i < N; i++)
		printf("%d ", vett[i]);

	return;
}
